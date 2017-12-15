# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/26 20:10:24 by jgaillar          #+#    #+#              #
#    Updated: 2017/12/04 11:59:37 by jgaillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src/

SRC_NAME = main.c raytracing.c struct.c img.c vector.c vector2.c hooks.c \
			check_data_plan.c check_data_light.c check_data_sphere.c \
			check_data_cylindre.c ft_check.c ft_compare_sd.c ft_compare.c \
			ft_parsing_sd.c ft_parsing.c list_tools.c vectorcalc.c \
			check_format.c check_format_obj.c check_data_cone.c check_obj.c \
			shadows.c \

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
