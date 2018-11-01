/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 17:50:37 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 14:27:19 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(int numerror)
{
	if (numerror == 1)
	{
		ft_putstr("usage : param number != 1\n");
		exit(EXIT_FAILURE);
	}
	if (numerror == 2)
	{
		ft_putstr("error\n");
		exit(EXIT_FAILURE);
	}
}
