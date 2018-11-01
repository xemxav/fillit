/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_solver.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 14:34:49 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/14 14:39:15 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check_place(t_tetris *link, t_grid *grid, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((link->y[i] + y) < 0 || (link->x[i] + x) < 0
				|| (link->y[i] + y) > grid->size - 1
				|| (link->x[i] + x) > grid->size - 1
				|| grid->strings[link->y[i] + y][link->x[i] + x] != '.')
			return (0);
		i++;
	}
	return (1);
}

static t_grid	*ft_put_tetris(t_tetris *link, t_grid *grid, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		grid->strings[link->y[i] + y][link->x[i] + x] = link->letter;
		i++;
	}
	return (grid);
}

static t_grid	*ft_erase(char c, t_grid *grid)
{
	int y;
	int x;

	y = 0;
	while (y < grid->size)
	{
		x = 0;
		while (x < grid->size)
		{
			if (grid->strings[y][x] == c)
				grid->strings[y][x] = '.';
			x++;
		}
		y++;
	}
	return (grid);
}

int				ft_solver(t_tetris *link, t_grid *grid, int x, int y)
{
	if (link == NULL)
		return (1);
	while (y < grid->size)
	{
		while (x < grid->size)
		{
			if (ft_check_place(link, grid, x, y) == 1)
			{
				grid = ft_put_tetris(link, grid, x, y);
				if (ft_solver(link->next, grid, 0, 0) == 1)
					return (1);
				else
					grid = ft_erase(link->letter, grid);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}
