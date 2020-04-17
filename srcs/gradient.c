/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gradient.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/25 17:44:54 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 10:30:23 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf.h"

static double			percent(int start, int end, int current)
{
	double			placement;
	double			distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int				get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

void					init_color(t_segment *segment, t_color *color,
									t_vector *p)
{
	color->start_x = segment->p1.x;
	color->start_y = segment->p1.y;
	color->end_x = segment->p2.x;
	color->end_y = segment->p2.y;
	color->current_x = p->x;
	color->current_y = p->y;
	color->delta_x = segment->dx;
	color->delta_y = segment->dy;
	color->start_color = GREY_DARK;
	color->end_color = GREY_LIGHT;
}

int						get_color(t_segment segment, t_vector p)
{
	t_color			color;
	int				red;
	int				green;
	int				blue;
	double			percentage;

	init_color(&segment, &color, &p);
	if (color.current_color == color.end_color)
		return (color.current_color);
	percentage = percent(color.start_y, color.end_y, color.current_y);
	red = get_light((color.start_color >> 16) & 0xFF, (color.end_color >> 16)
			& 0xff, percentage);
	green = get_light((color.start_color >> 8) & 0xff, (color.end_color >> 8)
			& 0xff, percentage);
	blue = get_light(color.start_color & 0xff, color.end_color
			& 0xff, percentage);
	return ((red << 16) | (green << 8) | blue);
}
