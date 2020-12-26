/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:34:07 by teppei            #+#    #+#             */
/*   Updated: 2020/12/27 00:55:41 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	build_header(t_all *a, char *bmp_header, uint32_t n_pixel)
{
	t_header	header;
	int			i;

	i = 0;
	header.file_size = n_pixel * 4 + 54;
	header.offset = 54;
	header.header_size = 40;
	header.planes = 1;
	header.bpp = 32;
	ft_memcpy(&bmp_header[i], "BM", 2);
	ft_memcpy(&bmp_header[i += 2], &header.file_size, 4);
	ft_memset(&bmp_header[i += 4], 0, 4);
	ft_memcpy(&bmp_header[i += 4], &header.offset, 4);
	ft_memcpy(&bmp_header[i += 4], &header.header_size, 4);
	ft_memcpy(&bmp_header[i += 4], &a->e->win_x, 4);
	ft_memcpy(&bmp_header[i += 4], &a->e->win_y, 4);
	ft_memcpy(&bmp_header[i += 4], &header.planes, 2);
	ft_memcpy(&bmp_header[i += 2], &header.bpp, 4);
	ft_memset(&bmp_header[i += 4], 0, 24);
}

static void	build_pixel_data(t_all *a, char *pixel_data)
{
	int	i;
	int	j;
	int	k;
	int	p;

	i = a->e->win_y - 1;
	k = 0;
	while (i >= 0)
	{
		j = 0;
		p = 0;
		while (j < a->e->win_x * 4)
			pixel_data[i * a->e->win_x * 4 + j++] = a->img.addr[k++];
		while (p++ < (a->img.line - (a->e->win_x * 4)))
			k++;
		i--;
	}
}

void		error_free_a(char *msg, t_all *a)
{
	my_free_a(a);
	error(msg);
}

void		make_bmp(t_all *a)
{
	char		bmp_header[54];
	char		*pixel_data;
	uint32_t	n_pixel;
	int			fd;

	load_tex(a);
	render_fc(a);
	render_wall(a);
	render_sprite(a);
	fd = open("capture_cub3D.bmp", O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
		error_free_a("cannot open file bmp", a);
	n_pixel = a->img.line * a->e->win_y;
	if (!(pixel_data = (char *)malloc(sizeof(char) * n_pixel * 4)))
		error_free_a("malloc error in make_bmp", a);
	build_header(a, bmp_header, n_pixel);
	build_pixel_data(a, pixel_data);
	write(fd, bmp_header, 54);
	write(fd, pixel_data, n_pixel * 4);
	close(fd);
	SAFE_FREE(pixel_data);
	quit_normally(a);
}
