/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_tab_2d_int.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/24 13:47:10 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 10:32:15 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int				**init_tab_2d_int(int line_len, int col_len)
{
	int		i;
	int		**res;

	i = 0;
	if (!(res = (int**)malloc(sizeof(int*) * line_len)))
		return (NULL);
	while (i < line_len)
	{
		if (!(res[i] = (int*)malloc(sizeof(int) * col_len)))
			return (NULL);
		i++;
	}
	return (res);
}
