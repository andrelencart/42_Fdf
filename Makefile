# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andre <andre@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 13:09:01 by andcarva          #+#    #+#              #
#    Updated: 2025/01/20 20:23:53 by andre            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
CC=cc
CFLAGS= -Wall -Wextra -Werror -g 
OBJ_DIR=Obj
SRC_DIR= Src
LIBFT= Includes/Libft/libft.a
MLX= mlx_linux/libmlx.a

SRC_FILES= main.c init.c drawmap.c utils.c controls.c keyboard.c

OBJ= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
SRC= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -lXext -lX11 -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

$(LIBFT):
	@make -C ./Includes/Libft -s
	
$(MLX):
	@make -C ./mlx_linux -s

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C ./Includes/Libft -s
	@make clean -C ./mlx_linux -s
	
fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)
	
re: fclean all

.PHONY: all fclean clean re