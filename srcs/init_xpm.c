/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_xpm.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 17:53:30 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 18:29:03 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf.h"

static int				check_ptr(t_texture *texture)
{
	int					i;

	i = 0;
	while (i < 5)
	{
		if (i < 2)
			if (!(texture->end_screen[i].image_ptr))
				return (-1);
		if (!(texture->wall[i].image_ptr))
			return (-1);
		i++;
	}
	if (!(texture->sky.image_ptr))
		return (-1);
	return (0);
}

static int				init_ptr_textures(t_texture *txt, void *mlx_ptr)
{
	txt->wall[0].image_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/1.xpm",
							&(txt->size), &(txt->size));
	txt->wall[2].image_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/2.xpm",
					&(txt->size), &(txt->size));
	txt->wall[1].image_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/3.xpm",
					&(txt->size), &(txt->size));
	txt->wall[3].image_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/4.xpm",
					&(txt->size), &(txt->size));
	txt->wall[4].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
					"textures/5.xpm", &(txt->size), &(txt->size));
	txt->end_screen[0].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
								"textures/fail.xpm", &(txt->full_width),
								&(txt->full_height));
	txt->end_screen[1].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
								"textures/win.xpm", &(txt->full_width),
								&(txt->full_height));
	txt->sky.image_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/sky.xpm",
							&(txt->full_width), &(txt->full_height));
	if (check_ptr(txt) == -1)
		return (-1);
	return (0);
}

static int				init_str_textures(t_texture *txt)
{
	txt->wall[0].image_str = (int*)mlx_get_data_addr(txt->wall[0].image_ptr,
					&(txt->wall[0].bits_per_pixel), &(txt->wall[0].size_line),
					&(txt->wall[0].endian));
	txt->wall[1].image_str = (int*)mlx_get_data_addr(txt->wall[1].image_ptr,
					&(txt->wall[1].bits_per_pixel), &(txt->wall[1].size_line),
					&(txt->wall[1].endian));
	txt->wall[2].image_str = (int*)mlx_get_data_addr(txt->wall[2].image_ptr,
					&(txt->wall[2].bits_per_pixel), &(txt->wall[2].size_line),
					&(txt->wall[2].endian));
	txt->wall[3].image_str = (int*)mlx_get_data_addr(txt->wall[3].image_ptr,
					&(txt->wall[3].bits_per_pixel), &(txt->wall[3].size_line),
					&(txt->wall[3].endian));
	txt->wall[4].image_str = (int*)mlx_get_data_addr(txt->wall[4].image_ptr,
					&(txt->wall[4].bits_per_pixel), &(txt->wall[4].size_line),
					&(txt->wall[4].endian));
	txt->end_screen[0].image_str = (int*)mlx_get_data_addr(txt->end_screen[0].
					image_ptr, &(txt->end_screen[0].bits_per_pixel),
				&(txt->end_screen[0].size_line), &(txt->end_screen[0].endian));
	txt->end_screen[1].image_str = (int*)mlx_get_data_addr(txt->end_screen[1].
					image_ptr, &(txt->end_screen[1].bits_per_pixel),
				&(txt->end_screen[1].size_line), &(txt->end_screen[1].endian));
	txt->sky.image_str = (int*)mlx_get_data_addr(txt->sky.image_ptr,
					&(txt->sky.bits_per_pixel), &(txt->sky.size_line),
					&(txt->sky.endian));
	return (0);
}

int						load_xpm(t_texture *texture, void *mlx_ptr)
{
	texture->size = 256;
	texture->x = 0;
	texture->y = 0;
	texture->map_x = 0;
	texture->full_width = WIDTH;
	texture->full_height = HEIGHT;
	if (init_ptr_textures(texture, mlx_ptr) == -1)
		return (-1);
	init_str_textures(texture);
	return (0);
}
