# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teppei <teppei@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 12:46:40 by teppei            #+#    #+#              #
#    Updated: 2020/12/29 19:51:22 by teppei           ###   ########.fr        #
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
LIBS	=	-lft -lgnl -lmlx

all: $(NAME)

$(NAME): $(OBJS)
	make -C utils/libft
	cp utils/libft/libft.a ./libraries
	make -C utils/gnl
	cp utils/gnl/libgnl.a ./libraries
	make -C minilibx_mms_20200219/
	cp minilibx_mms_20200219/libmlx.dylib ./libraries
	cp minilibx_mms_20200219/libmlx.dylib .
	$(CC) -o $(NAME) $(OBJS) $(LINK) $(LIBS)
%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) */*.gch
	rm -f libmlx.dylib
	rm -rf *.dSYM
	rm -f *.bmp
	rm -f */*.bmp

fclean: clean
	rm -f $(NAME)

alclean: fclean bfclean
	make fclean -C utils/libft
	make fclean -C utils/gnl
	make clean -C minilibx_mms_20200219/
	rm cub3D_bonus
	if [ ! -d libraries ]; then mkdir libraries; fi

re: fclean all
cl: all clean
reall: alclean all

bonus:
	make -C bonus_mac
	cp bonus_mac/cub3D_bonus .

bclean:
	make clean -C bonus_mac

bfclean:
	make fclean -C bonus_mac

.PHONY: all clean fclean re cl alclean reall bonus bclean bfclean
