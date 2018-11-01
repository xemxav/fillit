/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <volivry@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 10:22:09 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 18:11:42 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../libft/libft.h"
# include <fcntl.h>

# define BUF_SIZE	1024

typedef struct			s_tetri_list
{
	int					x[4];
	int					y[4];
	char				letter;
	struct s_tetri_list	*next;
}						t_tetris;

typedef struct			s_grid
{
	int					size;
	char				**strings;
}						t_grid;

void					ft_error(int numerror);

t_tetris				*ft_read_n_create(int fd);

t_tetris				*ft_adnd(t_tetris *maillon, char *substr, char l);

t_tetris				*ft_start_solving(t_tetris *first);

int						ft_solver(t_tetris *link, t_grid *grid, int x, int y);

t_grid					*ft_new_grid(int size);

void					ft_print_grid(t_grid *grid);

void					ft_free_grid(t_grid *grid);

t_tetris				*ft_delete_links(t_tetris *first);

#endif
