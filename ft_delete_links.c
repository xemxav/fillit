/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_delete_links.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 12:19:21 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 10:53:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*ft_delete_links(t_tetris *first)
{
	t_tetris *tmp;

	if (first == NULL)
		return (NULL);
	tmp = first->next;
	ft_memdel((void**)&first);
	return (ft_delete_links(tmp));
}
