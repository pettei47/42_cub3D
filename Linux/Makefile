# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teppei <teppei@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 12:46:40 by teppei            #+#    #+#              #
#    Updated: 2020/12/23 02:53:06 by teppei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g
SRCS	=	srcs/ft_read_cub.c srcs/ft_read_cub_utils.c srcs/ft_read_map.c \
			srcs/ft_map_check.c srcs/ft_error_cub.c srcs/ft_map_close.c \
			srcs/ft_get_sprite.c srcs/ft_move.c srcs/ft_key_press.c \
			srcs/ft_next_frame.c srcs/ft_wall_render.c srcs/ft_sprite_render.c\
			srcs/ft_fc_render.c srcs/ft_window_load.c srcs/ft_bmp.c \
			srcs/ft_digit_only.c \
			srcs/main_read_cub.c
OBJS	=	$(SRCS:%.c=%.o)

HEAD	=	./includes/cub3d.h
INCS	=	-I./includes
LINK	=	-L./libraries
LIBS	=	-lft -lgnl -lmlx -lm -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS) LIBFT MLX GNL
	$(CC) -o $(NAME) $(OBJS) $(LINK) $(INCS) $(LIBS)
%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) */*.gch
	rm -f *.bmp

fclean: clean
	rm -f $(NAME)

alclean: fclean
	make fclean -C utils/libft
	make fclean -C utils/gnl
	make clean -C minilibx-linux/
	rm -f libraries/*.a
	if [ ! -d libraries ]; mkdir libraries; fi

LIBFT:
	make -C utils/libft
	cp utils/libft/libft.a ./libraries

GNL:
	make -C utils/gnl

MLX:
	make -C minilibx-linux/
	cp minilibx-linux/libmlx*.a ./libraries

re: fclean all
cl: all clean
reall: alclean all

.PHONY: all clean fclean re cl alclean reall
