/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <volivry@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 11:13:19 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 12:52:38 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_tetris		*first;

	if (argc != 2)
		ft_error(1);
	first = NULL;
	if ((first = ft_read_n_create(open(argv[1], O_RDONLY))) == NULL)
	{
		first = ft_delete_links(first);
		ft_error(2);
	}
	if ((ft_start_solving(first)) == NULL)
	{
		ft_delete_links(first);
		ft_error(2);
	}
	ft_delete_links(first);
	return (0);
}
