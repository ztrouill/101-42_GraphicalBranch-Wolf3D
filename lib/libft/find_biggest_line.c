/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_biggest_line.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 16:47:44 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 09:07:08 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int				find_biggest_line(char **tab)
{
	int			i;
	int			j;
	int			res;
	int			tmp;

	i = 0;
	j = 0;
	res = 0;
	tmp = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			tmp++;
			if (tab[i][j] == ' ')
				tmp--;
			j++;
		}
		if (tmp > res)
			res = tmp;
		tmp = 0;
		j = 0;
		i++;
	}
	return (res);
}
