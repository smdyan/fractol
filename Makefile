# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 18:52:10 by smdyan            #+#    #+#              #
#    Updated: 2022/02/14 15:17:02 by smdyan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c\
	init.c\
	draw.c\
	fractal_mandelbrot.c\
	fractal_julia.c\
	fractal_burning_ship.c\
	color.c\
	controls_keyboard.c\
	controls_mouse.c\
	controls_utils.c\
	stod.c\
	utils.c

HEADER = ./includes

LIBFT = ./libft
MLIBX = ./minilibx_opengl_20191021

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -O3

all: $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(HEADER) -MD

include $(wildcard *.d)

$(NAME): $(OBJ)
	make all -C $(LIBFT)
	make -C $(MLIBX)
	$(CC) $(OBJ) -o $(NAME) -L$(LIBFT) -L$(MLIBX)\
				  -lft -lmlx -lm -framework OpenGL -framework AppKit -o $(NAME)
bonus: all

clean:
	make fclean -C $(LIBFT)
	make clean -C $(MLIBX)
	rm -f $(OBJ)
	rm -f $(wildcard *.d)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
