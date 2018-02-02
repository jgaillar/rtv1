/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_list_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:56:01 by prossi            #+#    #+#             */
/*   Updated: 2018/02/02 16:40:31 by prossi           ###   ########.fr       */
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
		e->i.mlx = e->i.mlx->next;
		e->i.mlx->prev = e->i.tmp_mlx;
	}
	e->i.mlx->img_x = e->i.img_x;
	e->i.mlx->img_y = e->i.img_y;
	fill_img(&e->i.mlx, e->i.nb_img, e);
	e->i.nb_img++;
	return (0);
}

void	reboot_list_interface(t_stuff *e, int option)
{
	if (option == 0)
	{
		while (e->i.mlx->prev != NULL)
			e->i.mlx = e->i.mlx->prev;
		e->i.tmp_mlx = e->i.mlx;
	}
	if (option == 1)
	{
		e->i.mlx = e->i.tmp_mlx;
	}
}

void	searchlist_interface(t_stuff *e, int nmail)
{
	while (e->i.mlx->nmail != nmail)
		e->i.mlx = e->i.mlx->next;
}
