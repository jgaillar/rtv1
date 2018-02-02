/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:25:42 by prossi            #+#    #+#             */
/*   Updated: 2018/02/02 16:39:22 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void 	init_struct(t_stuff *e, int option)
{
	if (option == 0 && e->i.first == 0)
	{
		e->i.nb_img = 0;
	}
}

void	cadre_apercu(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->i.mlx->img_y)
	{
		x = -1;
		while (++x < e->i.mlx->img_x)
		{
			pixel_put_to_img(&e->i.mlx, x, y, 0xFFFFFF);
		}
	}
}

void	apercu(t_stuff *e)
{
	if (e->i.first == 0)
	{
		e->i.img_x = WIN_X - WIDTH;
		e->i.img_y = WIN_Y - LENGTH;
		new_img(e);
	}
	else
	{
		reboot_list_interface(e, 1);
		searchlist_interface(e, 1);
	}
	cadre_apercu(e);
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->i.mlx->img, 0, e->i.img_y);
}
int		launch_interface(t_stuff *e)
{
	init_struct(e, 0);
	objet_courant(e);
	apercu(e);
	if (e->i.first == 0)
	{
		e->i.first = 1;
		reboot_list_interface(e, 0);
	}
	return (0);
}
