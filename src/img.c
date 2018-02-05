/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 22:06:24 by jgaillar          #+#    #+#             */
/*   Updated: 2018/02/05 08:21:55 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			mlx_pixel_put_to_image(t_img img, int x, int y, int color)
{
	int			bit_pix;
	float		img_size;

	img_size = WIDTH * LENGTH * img.bits_per_pixel / 8;
	if (x < 0 || y < 0 || y * img.size_line + x * img.bits_per_pixel / 8 > \
		img_size
		|| x >= img.size_line / (img.bits_per_pixel / 8) || y >= img_size / \
		img.size_line)
		return ;
	bit_pix = img.bits_per_pixel / 8;
	img.data[y * img.size_line + x * bit_pix] = color;
	img.data[y * img.size_line + x * bit_pix + 1] = color >> 8;
	img.data[y * img.size_line + x * bit_pix + 2] = color >> 16;
}

double			rgbtohexa(int r, int g, int b)
{
	double color;

	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	color = ((r) << 16) + ((g) << 8) + (b);
	return (color);
}

void			ft_segment(t_stuff *e, int x1, int y1, double color)
{
	int x0;
	int y0;

	x0 = WIDTH / 2;
	y0 = LENGTH;
	//	 DON'T TOUCH
	// x0 = (WIDTH / 2) + (WIN_X - WIDTH);
	// y0 = LENGTH + (WIN_Y - LENGTH);
	e->seg.dx = ft_abs(x1 - x0);
	e->seg.sx = (x0 < x1 ? 1 : -1);
	e->seg.dy = ft_abs(y1 - y0);
	e->seg.sy = (y0 < y1 ? 1 : -1);
	e->seg.err = (e->seg.dx > e->seg.dy \
	? e->seg.dx : -e->seg.dy) / 2;
	while (1)
	{
		mlx_pixel_put(e->img.mlx_ptr, e->img.win_ptr, x0, y0, \
			color);
		if (x0 == x1 && y0 == y1)
			break ;
		e->seg.e2 = e->seg.err;
		if (e->seg.e2 > -e->seg.dx)
		{
			e->seg.err -= e->seg.dy;
			x0 += e->seg.sx;
		}
		if (e->seg.e2 < e->seg.dy)
		{
			e->seg.err += e->seg.dx;
			y0 += e->seg.sy;
		}
	}
}

void			rgb_add(t_rgb *res, t_rgb i, t_rgb j, double k)
{
	res->r = i.r + j.r * k;
	res->g = i.g + j.g * k;
	res->b = i.b + j.b * k;
	if (res->r > 255)
		res->r = 255;
	else if (res->r < 0)
		res->r = 0;
	if (res->g > 255)
		res->g = 255;
	else if (res->g < 0)
		res->g = 0;
	if (res->b > 255)
		res->b = 255;
	else if (res->b < 0)
		res->b = 0;
}
