#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/26 13:17:33 by mtrotsen          #+#    #+#              #
#    Updated: 2019/03/26 13:17:34 by mtrotsen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = mtrotsen.filler
SRCS = main.c ./gnl/get_next_line.c ft_playmap.c read_map.c
OBJ = main.o ./gnl/get_next_line.o ft_playmap.o read_map.o
LIB = filler.h
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./ft_printf
	gcc -o $(NAME) $(OBJ) ./libft/libft.a ./ft_printf/libftprintf.a
	echo "Player created"

clean:
	make -C ./libft clean
	make -C ./ft_printf clean
	rm -f main.o ./gnl/get_next_line.o

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean
	make -C ./ft_printf fclean

re: fclean all
