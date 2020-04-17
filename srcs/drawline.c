/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   drawline.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/26 09:02:14 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 18:30:51 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf.h"

void					pixelit(t_data *data, int64_t y, int64_t x, int rgba)
{
	if (y < 0 || x < 0 || y >= HEIGHT || x >= WIDTH)
		return ;
	data->image.image_str[(y * WIDTH) + x] = rgba;
}

static t_vector			makept(int x, int y)
{
	t_vector		p;

	p.x = x;
	p.y = y;
	return (p);
}

static void				core_bresenham(t_segment *segment, t_vector *p,
										int *e, int e2)
{
	if (e2 > -(segment->dx))
	{
		*e -= segment->dy;
		p->x += segment->sx;
	}
	if (e2 < segment->dy)
	{
		*e += segment->dx;
		p->y += segment->sy;
	}
}

static void				init_segment(t_segment *segment, t_vector p1,
									t_vector p2)
{
	segment->p1 = p1;
	segment->p2 = p2;
	segment->sx = (segment->p1.x < segment->p2.x) ? 1 : -1;
	segment->sy = (segment->p1.y < segment->p2.y) ? 1 : -1;
	segment->dx = fabs(segment->p2.x - segment->p1.x);
	segment->dy = fabs(segment->p2.y - segment->p1.y);
	segment->d = (segment->dx > segment->dy) ? segment->dx : segment->dy;
}

void					draw_sline(t_data *data, int d)
{
	t_segment		seg;

	if (d == 0)
		init_segment(&seg, makept(data->world.x, data->world.line_pos[0]
					[data->world.x]), makept(data->world.x, data->world.line_pos
					[1][data->world.x]));
	if (d == 1)
		init_segment(&seg, makept(data->world.x, data->world.line_pos[1]
					[data->world.x]), makept(data->world.x, HEIGHT - 1));
	seg.p.x = seg.p1.x;
	seg.p.y = seg.p1.y;
	seg.e = (seg.dx < seg.dy) ? seg.dx : -(seg.dy) / 2;
	while (seg.d--)
	{
		if (d == 0)
		{
			data->texture.y = (seg.p.y * 2 - HEIGHT + data->world.line_height) *
						(data->texture.size / 2) / data->world.line_height;
			texellit(data, seg.p.y, seg.p.x);
		}
		if (d == 1)
			pixelit(data, seg.p.y, seg.p.x, get_color(seg, seg.p));
		seg.e2 = seg.e;
		core_bresenham(&seg, &seg.p, &seg.e, seg.e2);
	}
}
