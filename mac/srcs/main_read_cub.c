/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_read_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 00:26:18 by teppei            #+#    #+#             */
/*   Updated: 2020/12/29 22:35:57 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_free_a(t_all *a)
{
	int	tex;

	tex = 0;
	if (a->tex[0].w > 0)
	{
		while (tex < 5)
		{
			SAFE_FREE(a->tex[tex].addr);
			tex++;
		}
	}
	my_free_e(a->e);
	if (a->e->num_sp > 0)
		SAFE_FREE(a->sp);
}

void	init_a(t_all *a)
{
	int i;

	a->key.w = 0;
	a->key.a = 0;
	a->key.s = 0;
	a->key.d = 0;
	a->key.l = 0;
	a->key.r = 0;
	a->key.esc = 0;
	a->tex[0].w = 0;
	i = 0;
	while (i < 5)
		a->tex[i++].addr = NULL;
	if (!(a->mlx_p = mlx_init()))
	{
		my_free_a(a);
		error("in init_a: Failed to mlx_init");
	}
}

int		quit_normally(void *a)
{
	my_free_a(a);
	exit(EXIT_SUCCESS);
	return (0);
}

void	run_mlx(t_all *a)
{
	a->img.img = mlx_new_image(a->mlx_p, a->e->win_x, a->e->win_y);
	a->img.addr = mlx_get_data_addr(a->img.img, &a->img.bpp, \
									&a->img.line, &a->img.endian);
	if (a->e->save == 1)
		make_bmp(a);
	a->win = mlx_new_window(a->mlx_p, a->e->win_x, a->e->win_y, "cub3D");
	mlx_hook(a->win, 2, 1L << 0, press_key, a);
	mlx_hook(a->win, 3, 1L << 1, release_key, a);
	mlx_hook(a->win, 17, 1L << 17, quit_normally, a);
	load_tex(a);
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
	quit_normally(&a);
	return (0);
}
