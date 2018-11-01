/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_grid.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 14:02:45 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/14 14:03:11 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_grid(t_grid *grid)
{
	int i;

	i = 0;
	while (i < grid->size)
	{
		free(grid->strings[i]);
		i++;
	}
	free(grid->strings);
}
