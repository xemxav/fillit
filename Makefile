# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: volivry <volivry@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/14 16:56:18 by volivry      #+#   ##    ##    #+#        #
#    Updated: 2017/12/26 18:13:33 by xmoreau     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = fillit

OBJS = ft_adnd.o \
		ft_delete_links.o \
		ft_error.o \
		ft_read_n_create.o \
		ft_free_grid.o \
		ft_new_grid.o \
		ft_print_grid.o \
		ft_solver.o \
		ft_start_solving.o \
		main.o

all: $(NAME)

$(NAME): $(OBJS)
	make -C ../libft
	$(CC) $(CFLAGS) -o  $(NAME) $(OBJS) -L ../libft/ -lft

./%.o: ./%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)
	make -C ../libft clean

fclean: clean
	make -C ../libft fclean
	rm -rf $(NAME)
	rm -rf $(OBJS)

re: fclean all

.PHONY: all clean fclean re
