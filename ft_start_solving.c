/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_start_solving.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 12:44:29 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/14 14:46:47 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_lst_count(t_tetris *first)
{
	int	lst_count;

	lst_count = 1;
	while (first->next != NULL)
	{
		first = first->next;
		lst_count++;
	}
	return (lst_count);
}

static int		ft_find_square(int min_area)
{
	int size;

	size = 2;
	while (size * size < min_area)
		size++;
	return (size);
}

t_tetris		*ft_start_solving(t_tetris *first)
{
	t_grid	*grid;
	int		size;

	size = ft_find_square(ft_lst_count(first) * 4);
	grid = ft_new_grid(size);
	while (!(ft_solver(first, grid, 0, 0)))
	{
		size++;
		ft_free_grid(grid);
		grid = ft_new_grid(size);
	}
	ft_print_grid(grid);
	ft_free_grid(grid);
	return (first);
}
