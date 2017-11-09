# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amansour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/01 10:00:28 by amansour          #+#    #+#              #
#    Updated: 2017/11/09 11:16:18 by amansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LDFLAGS = -L libft
LDLIBS = -lft
FLAGS = -Werror -Wall -Wextra -g
MLX_LNK= -L miniLibX -lmlx -framework OpenGL -framework AppKit

SRC_PATH = ./src
OBJ_PATH = ./obj
INCLUD  = ./include
LIB = libft/libft.a

SRC = main.c display_point.c rotating.c\
	segment.c draw.c checking.c stocking.c\
	error.c tools.c hook.c zoom.c\

OBJ = $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc $(OBJ) $(LDFLAGS) $(MLX_LNK) $(LDLIBS) -o $(NAME)


#$(MLX_LIB):
#	make -C $(MLX)

$(LIB):
	@make -C libft

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	gcc $(FLAGS) -I $(INCLUD) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)
	@make -C libft clean
#	@make -C $(MLX) clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
