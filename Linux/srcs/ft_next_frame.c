/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 07:00:32 by teppei            #+#    #+#             */
/*   Updated: 2020/12/26 22:14:36 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

static int	free_tex(uint32_t *addr[5], int tex)
{
	tex++;
	if (tex == 5)
	{
		while (--tex >= 0)
			SAFE_FREE(addr[tex]);
		return (0);
	}
	else
		return (tex);
}

static void	*load_img(t_all *a, char *path, int i)
{
	uint32_t	*addr[5];
	t_img		img;
	static int	tex;

	img.img = mlx_xpm_file_to_image(a->mlx_p, path, &img.w, &img.h);
	if (img.img == NULL)
	{
		my_free_a(a);
		error("image file error");
	}
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line, &img.endian);
	if (!(addr[i] = (uint32_t *)malloc(sizeof(uint32_t) * img.w * img.h)))
	{
		my_free_a(a);
		error("malloc in load_image");
	}
	sub_load_image(addr[i], &img);
	a->tex[i].w = img.w;
	a->tex[i].h = img.h;
	mlx_destroy_image(a->mlx_p, img.img);
	a->tex[i].addr = addr[i];
	tex = free_tex(addr, tex);
	return (0);
}

void		load_tex(t_all *a)
{
	load_img(a, a->e->north, 1);
	load_img(a, a->e->south, 0);
	load_img(a, a->e->west, 3);
	load_img(a, a->e->east, 2);
	load_img(a, a->e->sprite, 4);
}

int			next_frame(void *a)
{
	t_all *b;

	b = (t_all *)a;
	mlx_do_sync(b->mlx_p);
	load_tex(a);
	render_fc(b);
	render_wall(b);
	render_sprite(b);
	mlx_put_image_to_window(b->mlx_p, b->win, b->img.img, 0, 0);
	movement(b);
	return (0);
}
