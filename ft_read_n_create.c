/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read_n_create.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 11:16:13 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 12:35:47 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check_form(char *substr)
{
	int	neighbours;
	int	i;

	neighbours = 0;
	i = 0;
	while (substr[i])
	{
		if (substr[i] == '#')
		{
			if ((i + 1) < 20 && substr[i + 1] == '#')
				neighbours++;
			if ((i - 1) >= 0 && substr[i - 1] == '#')
				neighbours++;
			if ((i + 5) < 20 && substr[i + 5] == '#')
				neighbours++;
			if ((i - 5) >= 0 && substr[i - 5] == '#')
				neighbours++;
		}
		i++;
	}
	return (neighbours == 6 || neighbours == 8);
}

static int		ft_check(char *substr, int count)
{
	int i;
	int hash;

	i = 0;
	hash = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(substr[i] == '#' || substr[i] == '.'))
				return (0);
			if (substr[i] == '#' && ++hash > 4)
				return (0);
		}
		else if (substr[i] != '\n')
			return (0);
		i++;
	}
	if (count == 21 && substr[20] != '\n')
		return (0);
	if (ft_check_form(substr) == 0)
		return (0);
	return (1);
}

t_tetris		*ft_read_n_create(int fd)
{
	char		*buf;
	int			count;
	t_tetris	*link;
	char		l;
	int			last_read;

	buf = ft_strnew(21);
	l = 'A';
	link = NULL;
	last_read = -1;
	while ((count = read(fd, buf, 21)) >= 20)
	{
		last_read = count;
		if (ft_check(buf, count) == 0 || (link = ft_adnd(link, buf, l)) == NULL)
		{
			ft_strdel(&buf);
			return (NULL);
		}
		l++;
	}
	ft_strdel(&buf);
	if (last_read != 20 || count != 0 || close(fd) == -1)
		return (NULL);
	return (link);
}
