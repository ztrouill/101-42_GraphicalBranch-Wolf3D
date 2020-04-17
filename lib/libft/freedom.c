/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   freedom.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/30 11:09:36 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 09:07:14 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void				freedom(void **tab, int line_len)
{
	int		i;

	i = 0;
	if (!*tab)
		return ;
	while (i < line_len)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}
