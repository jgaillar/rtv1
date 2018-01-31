/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:25:42 by prossi            #+#    #+#             */
/*   Updated: 2018/01/31 22:56:29 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void	fill_img(t_mlx **mlx, int nbmail, t_stuff *e)
{
	(*mlx)->img = mlx_new_image(e->img.mlx_ptr, (*mlx)->img_x, \
		(*mlx)->img_y);
	(*mlx)->map = mlx_get_data_addr((*mlx)->img, &(*mlx)->bpp, \
		&(*mlx)->size_line, &(*mlx)->endian);
	(*mlx)->nmail = nbmail;
}

int		init_img(t_mlx **mlx)
{
	if (!(*mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (-1);
	(*mlx)->prev = NULL;
	(*mlx)->img = NULL;
	(*mlx)->map = NULL;
	(*mlx)->bpp = 0;
	(*mlx)->size_line = 0;
	(*mlx)->endian = 0;
	(*mlx)->next = NULL;
	return (0);
}

int		new_img(t_stuff *e)
{
	if (e->i.nb_img == 0)
	{
		if (init_img(&e->i.mlx) == -1)
			return (-1);
	}
	else
	{
		e->i.tmp_mlx = e->i.mlx;
		if (init_img(&e->i.mlx->next) == -1)
			return (-1);
		e->i.mlx = e->i.tmp_mlx;
		e->i.mlx->prev = e->i.tmp_mlx;
	}
	fill_img(&e->i.mlx, e->i.nb_img, e);
	e->i.nb_img++;
	return (0);
}

void 	init_struct(t_stuff *e, int option)
{
	if (option == 0 && e->i.first == 0)
	{
		e->i.nb_img = 0;
	}
}

int		first_launch_interface(t_stuff *e)
{
	init_struct(e, 0);
	objet_courant(e);
	e->i.first = 1;
}
