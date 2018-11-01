/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_new_grid.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 14:03:30 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/14 14:03:39 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_grid	*ft_new_grid(int size)
{
	t_grid	*grid;
	int		i;
	int		j;

	i = 0;
	if ((grid = (t_grid*)malloc(sizeof(*grid))) == NULL)
		return (NULL);
	grid->size = size;
	grid->strings = (char**)ft_memalloc(sizeof(char*) * size);
	while (i < size)
	{
		grid->strings[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			grid->strings[i][j] = '.';
			j++;
		}
		i++;
	}
	return (grid);
}
