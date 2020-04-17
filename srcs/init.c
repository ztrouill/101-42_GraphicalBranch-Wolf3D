/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 18:02:14 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 18:26:36 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void				init_rays_and_player(t_rays *rays, t_player *player)
{
	rays->dir_x = 0;
	rays->dir_y = 0;
	rays->wall = 0;
	rays->pos_x = 0;
	rays->pos_y = 0;
	rays->side = 0;
	player->dir_x = -1;
	player->dir_y = 0.00001;
	player->screen_x = 0;
	player->screen_y = 0.6;
	player->cam_x = -1;
}

static void				init_world(t_world *world, char **map)
{
	world->x = -1;
	world->line_nb = ft_line_nb(map);
	world->row_nb = find_biggest_line(map);
	if (world->line_nb <= 5 || world->row_nb <= 5)
	{
		world->line_nb = 6;
		world->row_nb = 6;
		world->map = create_basic_map();
	}
	else
	{
		world->line_nb += 2;
		world->row_nb += 2;
		world->map = init_tab_2d_int(world->line_nb, world->row_nb + 2);
		stock_points(world, map);
		secure_map(world, map);
	}
}

static void				spawn(t_data *data)
{
	data->player.pos_x = floor(data->world.line_nb - 1);
	data->player.pos_y = floor(data->world.row_nb / 2);
	if (data->world.map[data->world.line_nb - 1][data->world.row_nb / 2] == 0)
		return ;
	else
	{
		while (data->world.map[(int)data->player.pos_x][(int)data->player.pos_y]
				!= 0)
		{
			if (data->player.pos_x > 0)
				data->player.pos_x--;
			else
				data->player.pos_y--;
			if (data->player.pos_y == 0)
				return ;
		}
	}
}

static	int				init_struct(t_data *data)
{
	t_player		player;
	t_rays			rays;
	t_world			world;
	t_texture		texture;

	init_world(&world, data->map);
	if (load_xpm(&texture, data->mlx_ptr) == -1)
		return (-1);
	init_rays_and_player(&rays, &player);
	data->player = player;
	data->world = world;
	data->rays = rays;
	data->texture = texture;
	data->frontal = 0;
	data->lateral = 0;
	data->end = -1;
	return (0);
}

int						init(t_data *data,
							char *argv, int fd)
{
	t_image		image;

	data->map = stock_argv(fd, &argv);
	if ((check_tab(data->map) == 0))
	{
		ft_putendl(MAP);
		return (-1);
	}
	data->mlx_ptr = mlx_init();
	data->window_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT,
							"W 0 L F  3 D");
	image.image_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	image.image_str = (int*)mlx_get_data_addr(image.image_ptr,
			&(image.bits_per_pixel), &(image.size_line), &(image.endian));
	data->image = image;
	if (init_struct(data) == -1)
	{
		ft_putendl(TEXTURES);
		return (-1);
	}
	spawn(data);
	return (0);
}
