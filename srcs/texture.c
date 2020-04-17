/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   texture.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 12:07:17 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 17:59:04 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf.h"

void				texellit(t_data *data, int64_t y, int64_t x)
{
	if (y < 0 || x < 0 || y >= HEIGHT || x >= WIDTH)
		return ;
	if (data->texture.y < 0 || data->texture.x < 0 ||
		data->texture.y >= data->texture.size ||
		data->texture.x >= data->texture.size)
		return ;
	data->image.image_str[(y * WIDTH) + x] = data->texture.wall[data->
	texture.i].image_str[((int)data->texture.y * data->texture.size) +
	(int)data->texture.x];
}

void				compute_texture_pos(t_data *data)
{
	if (data->rays.side == 0)
	{
		data->texture.i = 0;
		data->texture.map_x = data->player.pos_y + data->rays.dist_from_wall *
							data->rays.dir_y;
	}
	else
	{
		data->texture.i = 1;
		data->texture.map_x = data->player.pos_x + data->rays.dist_from_wall *
							data->rays.dir_x;
	}
	data->texture.map_x -= floor(data->texture.map_x);
	data->texture.x = ceil(data->texture.map_x * data->texture.size) - 1;
	if (data->rays.side == 0 && data->rays.dir_x > 0)
	{
		data->texture.i = 2;
		data->texture.x = data->texture.size - data->texture.x - 1;
	}
	if (data->rays.side == 1 && data->rays.dir_y < 0)
	{
		data->texture.i = 3;
		data->texture.x = data->texture.size - data->texture.x - 1;
	}
}

void				apply_sky(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			data->image.image_str[(y * WIDTH) + x] =
			data->texture.sky.image_str[(y * data->texture.full_width) + x];
			x++;
		}
		x = 0;
		y++;
	}
}

void				apply_end_screen(t_data *data)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			data->image.image_str[y * WIDTH + x] = data->texture.end_screen
			[data->end].image_str[(y * data->texture.full_width) + x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->texture.end_screen[data->end].image_ptr, 0, 0);
	if (data->end == 1)
		mlx_string_put(data->mlx_ptr, data->window_ptr,
				WIDTH / 2 - 100, HEIGHT / 2, CYAN, "Bravo tu es tres fort");
	else
		mlx_string_put(data->mlx_ptr, data->window_ptr,
				WIDTH / 2 - 100, HEIGHT / 2, RED, "Oh non tu as perdu");
}
