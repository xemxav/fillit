/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_grid.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 14:04:04 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/14 14:04:07 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_grid(t_grid *grid)
{
	int i;

	i = 0;
	while (i < grid->size)
	{
		ft_putstr(grid->strings[i]);
		ft_putchar('\n');
		i++;
	}
}
