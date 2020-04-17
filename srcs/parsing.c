/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 18:02:28 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 10:08:54 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf.h"

int				check_ext(char *argv)
{
	size_t		i;
	int			j;
	char		*str;

	str = "pam.";
	i = ft_strlen(argv);
	if (i < 5)
		return (-1);
	i -= 1;
	j = 0;
	while (i >= ft_strlen(argv) - 3)
	{
		if (argv[i] != str[j])
			return (-1);
		i--;
		j++;
	}
	return (0);
}

int				**create_basic_map(void)
{
	int		i;
	int		j;
	int		**map;

	i = 0;
	j = 0;
	map = init_tab_2d_int(6, 6);
	while (i <= 5)
	{
		while (j <= 5)
		{
			if (i == 0 || i == 5 || j == 0 || j == 5)
				map[i][j] = 1;
			else
				map[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

void			secure_map(t_world *world, char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < world->line_nb)
	{
		while (j < world->row_nb)
		{
			world->map[0][j] = 5;
			world->map[world->line_nb - 1][j] = 5;
			world->map[i][world->row_nb - 1] = 5;
			world->map[i][0] = 5;
			if (i != 0 && i != world->line_nb - 1)
				if (j >= ft_count_col(tab[i - 1]) + 1)
					world->map[i][j] = 5;
			j++;
		}
		j = 0;
		i++;
	}
}

void			stock_points(t_world *world, char **tab)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	x = 1;
	y = 1;
	while (x <= ft_line_nb(tab))
	{
		while (y <= ft_count_col(tab[i]))
		{
			if (tab[i][j] == ' ' && tab[i][j] != '\0')
				j++;
			world->map[x][y] = ft_atoi(&tab[i][j]);
			y++;
			j++;
		}
		y = 1;
		j = 0;
		x++;
		i++;
	}
}

int				check_tab(char **tab)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]) == 1 || tab[i][j] == ' ')
				j++;
			else
				return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}
