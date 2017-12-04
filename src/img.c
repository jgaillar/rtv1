/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 22:06:24 by jgaillar          #+#    #+#             */
/*   Updated: 2017/12/01 10:54:51 by jgaillar         ###   ########.fr       */
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
	color = (r << 16) | (g << 8) | b;
	return (color);
}
