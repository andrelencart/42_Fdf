# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 13:09:01 by andcarva          #+#    #+#              #
#    Updated: 2025/03/03 17:30:06 by andcarva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
CC=cc
CFLAGS= -Wall -Wextra -Werror -g
OBJ_DIR= Obj_Fdf
SRC_DIR= Src
LIBFT= Includes/Libft/libft.a
MLX= minilibx-linux/libmlx.a

SRC_FILES= fdf.c init_destroy.c drawmap.c fdf_utils.c hooks.c parser_utils.c  \
			map_func.c projections.c matriz_rot.c rot_trans.c

OBJ= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
SRC= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -lm -lz -lXext -lX11 -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

$(LIBFT):
	@make -C ./Includes/Libft -s
	
$(MLX):
	@make -C ./minilibx-linux -s

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C ./Includes/Libft -s
	@make clean -C ./minilibx-linux -s
	
fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)
	
re: fclean all

r:
	make && clear && ./fdf Maps/42.fdf

.PHONY: all fclean clean re