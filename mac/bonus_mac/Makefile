# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teppei <teppei@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 12:46:40 by teppei            #+#    #+#              #
#    Updated: 2020/12/30 12:32:18 by teppei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D_bonus
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g
SRCS	=	srcs/ft_read_cub_bonus.c srcs/ft_read_cub_utils_bonus.c srcs/ft_read_map_bonus.c \
			srcs/ft_map_check_bonus.c srcs/ft_error_cub_bonus.c srcs/ft_map_close_bonus.c \
			srcs/ft_get_sprite_bonus.c srcs/ft_move_bonus.c srcs/ft_key_press_bonus.c \
			srcs/ft_next_frame_bonus.c srcs/ft_wall_render_bonus.c srcs/ft_sprite_render_bonus.c\
			srcs/ft_fc_render_bonus.c srcs/ft_window_load_bonus.c srcs/ft_bmp_bonus.c \
			srcs/ft_digit_only_bonus.c \
			srcs/main_read_cub_bonus.c
OBJS	=	$(SRCS:%.c=%.o)

HEAD	=	./includes/cub3d_bonus.h
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
	rm -rf *.dSYM
	rm -f *.bmp
	rm -f */*.bmp

fclean: clean
	rm -f $(NAME)

re: fclean all
cl: all clean

.PHONY: all clean fclean re cl
