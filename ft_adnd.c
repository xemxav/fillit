/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_adnd.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 14:05:12 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 14:19:26 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static t_tetris	*ft_to_the_left(t_tetris *new)
{
	int i;
	int delta_x;
	int delta_y;

	i = 0;
	delta_x = new->x[i];
	delta_y = new->y[i];
	while (i < 4)
	{
		new->x[i] -= delta_x;
		new->y[i] -= delta_y;
		i++;
	}
	return (new);
}

static t_tetris	*ft_fillmeup(t_tetris *new, char *substr, char l)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (substr[i])
	{
		if (substr[i] == '#')
		{
			new->x[count] = i % 5;
			new->y[count] = i / 5;
			count++;
		}
		i++;
	}
	new->letter = l;
	new->next = NULL;
	return (ft_to_the_left(new));
}

t_tetris		*ft_adnd(t_tetris *link, char *substr, char l)
{
	t_tetris	*new;
	t_tetris	*temp;

	if ((new = malloc(sizeof(t_tetris))) == NULL)
		return (NULL);
	new = ft_fillmeup(new, substr, l);
	if (link == NULL)
		return (new);
	else
	{
		temp = link;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		return (link);
	}
}
