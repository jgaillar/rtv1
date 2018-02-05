/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:25:42 by prossi            #+#    #+#             */
/*   Updated: 2018/02/05 08:21:38 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	init_struct(t_stuff *e, int option)
{
	if (option == 0 && e->i.first == 0)
	{
		e->i.nb_img = 0;
		e->i.term = 0;
	}
}

void	draw_terminal(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->i.img_y)
	{
		x = -1;
		while (++x < e->i.img_x)
		{
			pixel_put_to_img(&e->i.mlx, x, y, 0x6A455D);
		}
	}
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->i.mlx->img, WIN_X - WIDTH, WIN_Y - LENGTH - 30);
}

void	terminal(t_stuff *e)
{
	if (e->i.first == 0)
	{
		e->i.img_x = 400;
		e->i.img_y = 30;
		new_img(e);
		draw_terminal(e);
	}
	else
	{
		reboot_list_interface(e, 1);
		searchlist_interface(e, 2);
		//e->i.term dans les hooks...
	}
}

int		launch_interface(t_stuff *e)
{
	init_struct(e, 0);
	objet_courant(e);
	apercu_courant(e);
	terminal(e);
	if (e->i.first == 0)
	{
		e->i.first = 1;
		reboot_list_interface(e, 0);
	}
	return (0);
}
