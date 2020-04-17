/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/18 14:38:07 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 14:17:22 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void			detect_wall(t_rays *rays, t_world *world)
{
	while (rays->wall == 0)
	{
		if (rays->len_x <= rays->len_y)
		{
			rays->len_x += rays->dist_x;
			rays->pos_x += rays->inc_x;
			rays->side = 0;
		}
		else
		{
			rays->len_y += rays->dist_y;
			rays->pos_y += rays->inc_y;
			rays->side = 1;
		}
		if (world->map[rays->pos_x][rays->pos_y] > 0)
			rays->wall = world->map[rays->pos_x][rays->pos_y];
	}
}

static void			compute_dist_from_wall(t_rays *rays, t_player *player,
										t_world *world)
{
	if (rays->side == 0)
		rays->dist_from_wall = ((float)rays->pos_x - player->pos_x +
				(1 - (float)rays->inc_x) / 2) / rays->dir_x;
	else
		rays->dist_from_wall = ((float)rays->pos_y - player->pos_y +
				(1 - (float)rays->inc_y) / 2) / rays->dir_y;
	world->line_height = (float)HEIGHT / rays->dist_from_wall;
	world->line_pos[0][world->x] = -world->line_height / 2 + HEIGHT / 2;
	if (world->line_pos[0][world->x] < 0)
		world->line_pos[0][world->x] = 0;
	world->line_pos[1][world->x] = world->line_height / 2 + HEIGHT / 2;
	if (world->line_pos[1][world->x] >= HEIGHT)
		world->line_pos[1][world->x] = HEIGHT - 1;
}

static void			init_vec_pos(t_player *player, t_rays *rays, int x)
{
	player->cam_x = 2 * (float)x / (float)WIDTH - 1;
	rays->dir_x = player->dir_x + player->screen_x * player->cam_x;
	rays->dir_y = player->dir_y + player->screen_y * player->cam_x;
	rays->pos_x = (int)player->pos_x;
	rays->pos_y = (int)player->pos_y;
	rays->dist_x = fabs(1 / rays->dir_x);
	rays->dist_y = fabs(1 / rays->dir_y);
	rays->wall = 0;
	rays->inc_x = (rays->dir_x > 0) ? 1 : -1;
	rays->inc_y = (rays->dir_y > 0) ? 1 : -1;
	if (rays->dir_x > 0)
		rays->len_x = (rays->pos_x + 1 - player->pos_x) * rays->dist_x;
	else
		rays->len_x = (player->pos_x - rays->pos_x) * rays->dist_x;
	if (rays->dir_y > 0)
		rays->len_y = (rays->pos_y + 1 - player->pos_y) * rays->dist_y;
	else
		rays->len_y = (player->pos_y - rays->pos_y) * rays->dist_y;
}

int					render(t_data *data)
{
	apply_sky(data);
	while (++data->world.x < WIDTH)
	{
		init_vec_pos(&data->player, &data->rays, data->world.x);
		detect_wall(&data->rays, &data->world);
		compute_dist_from_wall(&data->rays, &data->player, &data->world);
		compute_texture_pos(data);
		if (data->rays.wall == 2 || data->rays.wall == 3)
			data->texture.i = 4;
		draw_sline(data, 0);
		draw_sline(data, 1);
	}
	data->world.x = -1;
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
							data->image.image_ptr, 0, 0);
	return (0);
}
