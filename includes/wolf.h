/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/10 13:10:08 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 14:27:57 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF_H

# define WOLF_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx_macos/mlx.h"
# include "wolf_struct.h"
# include "wolf_define.h"
# include "x.h"
# include <fcntl.h>
# include <math.h>

/*
 ** Initialization **
*/
int			init(t_data *data, char *argv, int fd);
int			load_xpm(t_texture *texture, void *mlx_ptr);
/*
 ** Parsing and Check **
*/
void		stock_points(t_world *world, char **tab);
int			check_ext(char *argv);
int			check_tab(char **tab);
int			**create_basic_map(void);
void		secure_map(t_world *world, char **tab);
/*
 ** Render **
*/
int			render(t_data *data);
void		draw_sline(t_data *data, int d);
int			get_color(t_segment segment, t_vector vector);
void		compute_texture_pos(t_data *data);
void		texellit(t_data *data, int64_t y, int64_t x);
void		apply_end_screen(t_data *data);
void		apply_sky(t_data *data);
/*
 ** Events **
*/
int			quit_and_close_window(t_data *data);
int			update(t_data *data);
int			key_pressed(int keycode, t_data *data);
int			key_released(int keycode, t_data *data);

#endif
