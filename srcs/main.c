/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/11 11:10:37 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 14:27:13 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf.h"

int					quit_and_close_window(t_data *data)
{
	freedom((void**)data->map, ft_line_nb(data->map));
	freedom((void**)data->world.map, data->world.line_nb);
	mlx_destroy_image(data->mlx_ptr, data->image.image_ptr);
	mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

static int			parsing(int argc, char *argv, t_data *data)
{
	if (argc != 2)
	{
		ft_putendl(PARAM);
		ft_putendl(USAGE);
		return (-1);
	}
	else
	{
		if ((check_ext(argv) == -1) ||
			(init(data, argv, open(argv, O_RDONLY)) == -1))
		{
			ft_putendl(USAGE);
			if (data->map)
				freedom((void**)data->map, ft_line_nb(data->map));
			return (-1);
		}
	}
	return (0);
}

int					main(int argc, char **argv)
{
	t_data			data;

	if ((parsing(argc, argv[1], &data) == -1))
		exit(EXIT_FAILURE);
	else
	{
		render(&data);
		mlx_hook(data.window_ptr, 2, 0L, key_pressed, &data);
		mlx_hook(data.window_ptr, 3, 0L, key_released, &data);
		mlx_hook(data.window_ptr, 17, 0L, quit_and_close_window, &data);
		mlx_loop_hook(data.mlx_ptr, update, &data);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}
