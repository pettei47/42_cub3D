/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchida <suchida@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 01:28:32 by suchida           #+#    #+#             */
/*   Updated: 2020/12/27 14:47:11 by suchida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <sysexits.h>
# include "libft.h"
# include "get_next_line.h"
# include <stdint.h>
# include "mlx.h"

# define SAFE_FREE(ptr) { free(ptr); ptr = NULL; }
# define MAP_WIDTH 257
# define MAP_HEIGHT MAP_WIDTH
# define ESC 65307
# define W 119
# define S 115
# define D 100
# define A 97
# define P 112
# define RIGHT 65363
# define LEFT 65361
# define J 106
# define K 107
# define L 108
# define DEFAULT	"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define BROWN		"\033[33m"
# define BLUE		"\033[34m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define GRAY		"\033[37m"

typedef struct	s_sprite
{
	double		sp_x;
	double		sp_y;
	int			ti;
}				t_sprite;

typedef struct	s_tex
{
	uint32_t	*addr;
	int			w;
	int			h;
}				t_tex;

typedef struct	s_elem
{
	int			win_x;
	int			win_y;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	int			fr;
	int			fg;
	int			fb;
	int			cr;
	int			cg;
	int			cb;
	char		*map[MAP_WIDTH];
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			num_sp;
	int			save;
}				t_elem;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			w;
	int			h;
	int			bpp;
	int			line;
	int			endian;
}				t_img;

typedef struct	s_key
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			l;
	int			r;
	int			esc;
}				t_key;

typedef struct	s_sd
{
	double		x;
	double		y;
	double		inv_det;
	double		transf_x;
	double		transf_y;
	int			screeen_x;
	int			height;
	int			width;
	int			d_start_y;
	int			d_end_y;
	int			d_start_x;
	int			d_end_x;
	double		tex_x;
	double		tex_y;
}				t_sd;

typedef struct	s_raycasting
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_num;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			tex_y;
}				t_raycasting;

typedef struct	s_header
{
	uint32_t	file_size;
	uint32_t	offset;
	uint32_t	header_size;
	uint32_t	planes;
	uint32_t	bpp;
}				t_header;

typedef struct	s_all
{
	t_elem		*e;
	t_sprite	*sp;
	double		mv_spd;
	double		rt_spd;
	void		*win;
	t_img		img;
	void		*mlx_p;
	t_key		key;
	t_tex		tex[5];
	uint32_t	f_color;
	uint32_t	c_color;
	double		*z_buffer;
}				t_all;

int				ft_read_cub(char *cub, t_elem *e);
int				ft_read_map(int *bit, int fd, char **line, t_elem *e);
void			my_e_reset(t_elem *e);
long			my_power(long a, long n);
int				my_c_ptr(char **s);
void			my_free_ptr(char **s);
void			my_free_e(t_elem *e);
void			my_free_a(t_all *a);
int				error(char *msg);
void			error_free(char *msg, t_elem *e);
void			error_devide(char *msg, char *line, t_elem *e);
void			error_free_ptr(char *msg, t_elem *e, char **s);
void			check_cub(int argc, char **argv, t_elem *e);
void			ft_map_check_format(t_elem *e);
int				map_close_check(t_elem *e, int h);
void			map_devide_check(char *cub, t_elem *e);
void			get_sprite(t_all *a);
void			set_move_speed(t_all *a);
int				press_key(int key, void *a);
int				release_key(int key, void *a);
int				next_frame(t_all *a);
int				quit_normally(void *a);
int				only_d(char *str, char c);
void			movement(t_all *a);
void			render_wall(t_all *a);
void			render_sprite(t_all *a);
void			render_fc(t_all *a);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			load_window(t_all *a);
void			make_bmp(t_all *a);
void			load_tex(t_all *a);
void			warning(char *msg);

#endif
