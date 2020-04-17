/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   count_col.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/24 13:50:37 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 12:53:20 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int					ft_count_col(char *tab)
{
	int		col_len;

	col_len = 0;
	col_len = ft_strlen(tab);
	col_len = ft_strlen_nospace(col_len, tab);
	return (col_len);
}
