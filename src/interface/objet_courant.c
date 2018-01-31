/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_courant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 22:13:22 by prossi            #+#    #+#             */
/*   Updated: 2018/01/31 23:06:58 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void	draw_img(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->i.mlx->img_y)
	{
		x = -1;
		while (++x < e->i.mlx->img_x)
		{
			pixel_put_to_img(&e->i.mlx, x, y, 0xFF0000);
			ft_putnbr(1);
		}
	}
}

void	objet_courant(t_stuff *e)
{
	if (e->i.first == 0)
	{
		new_img(e);
		e->i.mlx->img_x = WIN_X - WIDTH - 1;
		e->i.mlx->img_y = WIN_Y - LENGTH - 1;
	}
	draw_img(e);
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->i.mlx->img, 0, 0);
}
