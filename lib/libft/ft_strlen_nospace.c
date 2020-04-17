/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen_nospace.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/24 13:48:40 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/24 15:00:41 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int				ft_strlen_nospace(int col_len, char *tab)
{
	int		i;
	int		end;

	end = col_len;
	i = 0;
	while (i <= end)
	{
		while (tab[i] == ' ' && tab[i] != '\0')
		{
			i++;
			col_len--;
		}
		i++;
	}
	return (col_len);
}
