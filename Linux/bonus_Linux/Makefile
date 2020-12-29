# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teppei <teppei@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 12:46:40 by teppei            #+#    #+#              #
#    Updated: 2020/12/29 19:37:53 by teppei           ###   ########.fr        #
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

HEAD	=	./includes/cub3d.h
INCS	=	-I./includes
LINK	=	-L./libraries
LIBS	=	-lft -lgnl -lmlx -lm -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	make -C utils/libft
	cp utils/libft/libft.a ./libraries/
	make -C utils/gnl
	cp utils/gnl/libgnl.a ./libraries/
	make -C minilibx-linux
	cp minilibx-linux/libmlx*.a ./libraries/
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
	if [ ! -d libraries ]; then mkdir libraries; fi

re: fclean all
cl: all clean
reall: alclean all

.PHONY: all clean fclean re cl alclean reall
