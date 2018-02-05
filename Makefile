# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/26 20:10:24 by jgaillar          #+#    #+#              #
#    Updated: 2018/02/05 08:04:24 by prossi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src/

SRC_NAME = main.c raytracing.c struct.c img.c vector.c vector2.c hooks.c \
			check_data_plan.c check_data_light.c check_data_sphere.c \
			check_data_cylindre.c ft_check.c ft_compare_sd.c ft_compare.c \
			ft_parsing_sd.c ft_parsing.c list_tools.c vectorcalc.c \
			check_format.c check_format_obj.c check_data_cone.c check_obj.c \
			shadows.c mouse_hook.c matrice.c\

PATH_INTERFACE = src/interface/

PATH_LIB_LETTER = src/interface/lib_letter

SRC_NAME_INTERFACE = init_interface.c interface_list_tools.c pixel_put_to_img.c \
objet_courant.c apercu_courant.c

SRC_NAME_LIB_LETTER = AA.c BB.c CC.c \
DD.c EE.c FF.c GG.c HH.c II.c JJ.c KK.c LL.c MM.c NN.c OO.c PP.c QQ.c RR.c \
SS.c TT.c UU.c VV.c WW.c XX.c YY.c ZZ.c ft_segment.c ft_arc.c \
awklm_string_put.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_SRC_INTERFACE = $(SRC_NAME_INTERFACE:.c=.o)

OBJ_SRC_LIB_LETTER = $(SRC_NAME_LIB_LETTER:.c=.o)

CPPFLAGS = -Iincludes

NAME = rtv1

CC = clang

CCFLAGS = -Wall -Wextra -Werror

FDFFLAGS = -framework OpenGL -framework Appkit -lpthread -D_REENTRANT \
			-Ofast -march=native

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

SRC_INTERFACE = $(addprefix $(PATH_INTERFACE)/,$(SRC_NAME_INTERFACE))

SRC_LIB_LETTER = $(addprefix $(PATH_LIB_LETTER)/,$(SRC_NAME_LIB_LETTER))

OBJ = $(addprefix $(SRC_PATH)/,$(OBJ_NAME))

OBJ_INTERFACE = $(addprefix $(PATH_INTERFACE)/,$(OBJ_SRC_INTERFACE))

OBJ_LIB_LETTER = $(addprefix $(PATH_LIB_LETTER)/,$(OBJ_SRC_LIB_LETTER))

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_INTERFACE) $(OBJ_LIB_LETTER)
	@cd libft ; make re ; make clean ; cd ..
	@cd mlx ; make re ; cd ..
	$(CC) $(CCFLAGS) $(FDFFLAGS) $(CPPFLAGS) libft/libft.a mlx/libmlx.a $^ -o $@

clean:
	cd $(SRC_PATH) ; rm -rf $(OBJ_NAME) ; cd -
	cd $(PATH_INTERFACE) ; rm -rf $(OBJ_SRC_INTERFACE) ; cd -
	cd $(PATH_LIB_LETTER) ; rm -rf $(OBJ_SRC_LIB_LETTER) ; cd -

fclean: clean
	rm -rf libft/libft.a
	rm -rf mlx/libmlx.a
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean
