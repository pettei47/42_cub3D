/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_frame_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 07:00:32 by teppei            #+#    #+#             */
/*   Updated: 2020/12/29 19:22:37 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	sub_load_image(uint32_t *addr, t_img *img)
{
	int			x;
	int			y;

	y = 0;
	while (y < img->h)
	{
		x = 0;
		while (x < img->w)
		{
			addr[y * img->w + x] = \
				*(uint32_t *)(img->addr + (y * img->line + x * (img->bpp / 8)));
			x++;
		}
		y++;
	}
}

static void	*load_img(t_all *a, char *path, int i)
{
	t_img		img;

	img.img = mlx_xpm_file_to_image(a->mlx_p, path, &img.w, &img.h);
	if (img.img == NULL)
	{
		my_free_a(a);
		error("image file error");
	}
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line, &img.endian);
	if (!(a->tex[i].addr = \
				(uint32_t *)malloc(sizeof(uint32_t) * img.w * img.h)))
	{
		my_free_a(a);
		error("malloc in load_image");
	}
	sub_load_image(a->tex[i].addr, &img);
	a->tex[i].w = img.w;
	a->tex[i].h = img.h;
	mlx_destroy_image(a->mlx_p, img.img);
	return (0);
}

void		load_tex(t_all *a)
{
	load_img(a, a->e->north, 0);
	load_img(a, a->e->south, 1);
	load_img(a, a->e->west, 2);
	load_img(a, a->e->east, 3);
	load_img(a, a->e->sprite, 4);
}

int			next_frame(t_all *a)
{
	t_all	*b;

	b = (t_all *)a;
	mlx_do_sync(b->mlx_p);
	render_fc(b);
	render_wall(b);
	render_sprite(b);
	mlx_put_image_to_window(b->mlx_p, b->win, b->img.img, 0, 0);
	movement(b);
	return (0);
}
