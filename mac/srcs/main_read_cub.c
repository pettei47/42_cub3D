/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_read_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 00:26:18 by teppei            #+#    #+#             */
/*   Updated: 2020/12/26 22:39:42 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_free_a(t_all *a)
{
	my_free_e(a->e);
	if (a->e->num_sp > 0)
		SAFE_FREE(a->sp);
}

void	init_a(t_all *a)
{
	if (!(a->mlx_p = mlx_init()))
	{
		my_free_a(a);
		error("in init_a: Failed to mlx_init");
	}
	a->key.w = 0;
	a->key.a = 0;
	a->key.s = 0;
	a->key.d = 0;
	a->key.l = 0;
	a->key.r = 0;
	a->key.esc = 0;
}

int		quit_normally(void *a)
{
	t_all *b;

	b = a;
	my_free_a(a);
	while(1);
	exit(EXIT_SUCCESS);
	return (0);
}

void	run_mlx(t_all *a)
{
	a->win = mlx_new_window(a->mlx_p, a->e->win_x, a->e->win_y, "cub3D");
	a->img.img = mlx_new_image(a->mlx_p, a->e->win_x, a->e->win_y);
	a->img.addr = mlx_get_data_addr(a->img.img, &a->img.bpp, \
									&a->img.line, &a->img.endian);
	if (a->e->save == 1)
		make_bmp(a);
	mlx_hook(a->win, 2, 1L << 0, press_key, a);
	mlx_hook(a->win, 3, 1L << 1, release_key, a);
	mlx_hook(a->win, 17, 1L << 17, quit_normally, a);
	mlx_loop_hook(a->mlx_p, next_frame, a);
	mlx_loop(a->mlx_p);
}

int		main(int argc, char **argv)
{
	t_all	a;
	t_elem	e;
	int		map_h;

	my_e_reset(&e);
	check_cub(argc, argv, &e);
	map_h = ft_read_cub(argv[1], &e);
	ft_map_check_format(&e);
	if (map_close_check(&e, map_h) == 0)
		error_free("not closed map", &e);
	if (e.num_sp > 254 * 30)
		warning("too many sprites! cub will be slow");
	a.e = &e;
	init_a(&a);
	get_sprite(&a);
	set_move_speed(&a);
	load_window(&a);
	ft_putstr_fd(GREEN, 1);
	ft_putstr_fd("*** SUCCESS LOAD CUB ***\n", 1);
	ft_putstr_fd(DEFAULT, 1);
	run_mlx(&a);
	my_free_a(&a);
	return (0);
}
