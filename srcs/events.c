/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/20 11:05:35 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 14:26:34 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf.h"

int					key_pressed(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		quit_and_close_window(data);
		return (0);
	}
	if (keycode == W || keycode == UP)
		data->frontal = 1;
	if (keycode == S || keycode == DOWN)
		data->frontal = -1;
	if (keycode == A || keycode == LEFT)
		data->lateral = -1;
	if (keycode == D || keycode == RIGHT)
		data->lateral = 1;
	return (0);
}

int					key_released(int keycode, t_data *data)
{
	if (keycode == W || keycode == S || keycode == UP || keycode == DOWN)
		data->frontal = 0;
	if (keycode == A || keycode == D || keycode == LEFT || keycode == RIGHT)
		data->lateral = 0;
	return (0);
}

static void			rotate(t_data *data)
{
	float			old_dir_x;
	float			old_plane_x;
	float			speed;

	speed = .05;
	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.screen_x;
	if (data->lateral == 1 && speed > 0)
		speed *= -1;
	data->player.dir_x = data->player.dir_x * cos(speed) -
						data->player.dir_y * sin(speed);
	data->player.dir_y = old_dir_x * sin(speed) +
						data->player.dir_y * cos(speed);
	data->player.screen_x = data->player.screen_x * cos(speed) -
						data->player.screen_y * sin(speed);
	data->player.screen_y = old_plane_x * sin(speed) +
						data->player.screen_y * cos(speed);
}

static void			move_front(t_data *data)
{
	float			move_pos_x;
	float			move_pos_y;
	float			speed;

	speed = .1;
	move_pos_x = data->player.dir_x * speed;
	move_pos_y = data->player.dir_y * speed;
	if (data->frontal == -1)
	{
		move_pos_x *= -1;
		move_pos_y *= -1;
	}
	data->player.pos_x += move_pos_x;
	data->player.pos_y += move_pos_y;
	if (data->world.map[(int)data->player.pos_x][(int)data->player.pos_y] != 0
		&& data->world.map[(int)data->player.pos_x][(int)data->player.pos_y]
		!= 3 &&
		data->world.map[(int)data->player.pos_x][(int)data->player.pos_y] != 2)
	{
		data->player.pos_x -= move_pos_x;
		data->player.pos_y -= move_pos_y;
	}
}

int					update(t_data *data)
{
	if (!((data->frontal) && !(data->lateral)) && data->end >= 0)
		return (-1);
	if (data->frontal)
		move_front(data);
	if (data->lateral)
		rotate(data);
	if (data->world.map[(int)data->player.pos_x][(int)data->player.pos_y] == 2)
		data->end = 0;
	if (data->world.map[(int)data->player.pos_x][(int)data->player.pos_y] == 3)
		data->end = 1;
	if (data->end >= 0)
		apply_end_screen(data);
	else
	{
		mlx_clear_window(data->mlx_ptr, data->window_ptr);
		render(data);
	}
	return (0);
}
