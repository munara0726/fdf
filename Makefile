# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoktobo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 17:07:18 by mtoktobo          #+#    #+#              #
#    Updated: 2020/02/17 19:49:24 by mtoktobo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAMEWORKS=-framework OpenGL -framework AppKit
FLAGS=-Wall -Wextra -Werror
NAME=fdf
SRC=src/*.c
INCLUDES=libft/libft.a minilibx_macos/libmlx.a

all:
	@make -C libft/ all
	@make -C minilibx_macos/ all
	gcc $(SRC) -O $(NAME) $(FLAGS) $(INCLUDES) $(FRAMEWORKS)

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
