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
SRCS = main.c ./gnl/get_next_line.c ft_playmap.c read_map.c place_piece.c \
ft_lookspot.c ft_trymake.c
OBJ = main.o ./gnl/get_next_line.o ft_playmap.o read_map.o place_piece.o \
ft_lookspot.o ft_trymake.o
LIB = filler.h
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(FLAG) -o $(NAME) $(OBJ) ./libft/libft.a
	echo "Player created"

clean:
	make -C ./libft clean
	rm -f main.o ./gnl/get_next_line.o

fclean: clean
	rm -f $(NAME)
	rm -f *.o
	make -C ./libft fclean

re: fclean all
