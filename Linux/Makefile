# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teppei <teppei@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 12:46:40 by teppei            #+#    #+#              #
#    Updated: 2020/12/16 21:07:31 by teppei           ###   ########.fr        #
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
LINK	=	-L./libraries -L/usr/local/lib
LIBS	=	-lft -lgnl -lftprintf -lmlx -lm -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS) LIBFT MLX GNL FTPRINTF
	$(CC) -o $(NAME) $(OBJS) $(LINK) $(INCS) $(LIBS)
%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) */*.gch
	rm -rf *.dSYM
	rm -f *.bmp

fclean: clean
	rm -f $(NAME)

alclean: fclean
	make fclean -C utils/libft
	make fclean -C utils/ft_printf
	make fclean -C utils/gnl
	make clean -C minilibx_mms_20200219/
	rm -f libmlx.dylib
	rm -f libraries/*.a
	rm -f libraries/libmlx.dylib

LIBFT:
	make -C utils/libft
	cp utils/libft/libft.a ./libraries

GNL:
	make -C utils/gnl

FTPRINTF:
	make -C utils/ft_printf

MLX:
	make -C minilibx_mms_20200219/
	cp minilibx_mms_20200219/libmlx.dylib ./libraries
	cp minilibx_mms_20200219/libmlx.dylib .

re: fclean all
cl: all clean
reall: alclean all

.PHONY: all clean fclean re cl alclean reall
