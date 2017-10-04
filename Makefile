# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/26 20:10:24 by jgaillar          #+#    #+#              #
#    Updated: 2017/09/25 17:43:43 by jgaillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src/

SRC_NAME = main.c

OBJ_NAME = $(SRC_NAME:.c=.o)

CPPFLAGS = -Iincludes

NAME = rtv1

CC = clang

CCFLAGS = -Wall -Wextra -Werror

FDFFLAGS = -framework OpenGL -framework Appkit -lpthread -D_REENTRANT \
			-Ofast -march=native

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(SRC_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft ; make re ; make clean ; cd ..
	@cd mlx ; make re ; cd ..
	$(CC) $(CCFLAGS) $(FDFFLAGS) $(CPPFLAGS) libft/libft.a mlx/libmlx.a $^ -o $@

clean:
	@cd src ; rm -rf $(OBJ_NAME) ; cd ..

fclean: clean
	rm -rf libft/libft.a
	rm -rf mlx/libmlx.a
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean
