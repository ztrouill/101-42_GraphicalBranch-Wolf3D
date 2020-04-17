/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf_struct.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/11 11:15:39 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 15:53:34 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF_STRUCT_H
# define WOLF_STRUCT_H

# include "wolf_define.h"
# include "wolf.h"

typedef struct		s_vector
{
	float					x;
	float					y;
}					t_vector;

typedef struct		s_image
{
	int						*image_str;
	int						bits_per_pixel;
	int						size_line;
	int						endian;
	void					*image_ptr;
}					t_image;

typedef struct		s_player
{
	float					pos_x;
	float					pos_y;
	float					dir_x;
	float					dir_y;
	float					screen_x;
	float					screen_y;
	float					cam_x;
}					t_player;

typedef struct		s_rays
{
	float					dir_x;
	float					dir_y;
	int						pos_x;
	int						pos_y;
	float					len_x;
	float					len_y;
	int						side;
	float					dist_x;
	float					dist_y;
	int						inc_x;
	int						inc_y;
	int						wall;
	float					dist_from_wall;
}					t_rays;

typedef struct		s_texture
{
	t_image					wall[5];
	t_image					end_screen[2];
	t_image					sky;
	float					map_x;
	float					y;
	float					x;
	int						size;
	int						full_width;
	int						full_height;
	int						i;
}					t_texture;

typedef struct		s_world
{
	int				**map;
	float			line_height;
	int				line_pos[2][WIDTH];
	int				x;
	int				line_nb;
	int				row_nb;
}					t_world;

typedef struct		s_segment
{
	t_vector				p1;
	t_vector				p2;
	t_vector				p;
	int						d;
	int						dx;
	int						dy;
	int						sx;
	int						sy;
	int						e;
	int						e2;
}					t_segment;

typedef struct		s_color
{
	int						start_x;
	int						start_y;
	int						end_x;
	int						end_y;
	int						current_x;
	int						current_y;
	int						delta_x;
	int						delta_y;
	int						start_color;
	int						end_color;
	int						current_color;
}					t_color;

typedef struct		s_data
{
	t_image					image;
	t_player				player;
	t_rays					rays;
	t_world					world;
	t_texture				texture;
	int						frontal;
	int						lateral;
	int						end;
	void					*window_ptr;
	void					*mlx_ptr;
	char					**map;
}					t_data;

#endif
