/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 13:09:32 by jgaillar          #+#    #+#             */
/*   Updated: 2017/11/21 15:31:32 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_struct(t_stuff *e)
{
	e->poscam.x = 0;
	e->poscam.y = 0;
	e->poscam.z = 0;
	e->pr.x = 20;
	e->pr.y = 0;
	e->pr.z = 0;
	e->vech.x = 0;
	e->vech.y = 0;
	e->vech.z = 1;
	e->distvue = 1;
	e->largvue = 0.5;
	e->longvue = 0.3;
	e->sphere.poss.x = 30;
	e->sphere.poss.y = 0;
	e->sphere.poss.z = 0;
	e->sphere.rayon = 2;
	e->sphere.color.r = 128;
	e->sphere.color.g = 0;
	e->sphere.color.b = 64;
	e->plan.normp.x = 0;
	e->plan.normp.y = 0;
	e->plan.normp.z = 1;
	e->plan.plan.x = 1;
	e->plan.plan.y = 0;
	e->plan.plan.z = 0.5;
	e->plan.color.r = 0;
	e->plan.color.g = 0;
	e->plan.color.b = 255;
	e->light.posl.x = 10;
	e->light.posl.y = 0;
	e->light.posl.z = 0;
	e->light.color.r = 255;
	e->light.color.g = 255;
	e->light.color.b = 255;
	e->light.amb = 0.1;
	e->light.diff = 0.2;
	e->rt.colorf = 0;
	vecsous(&e->dircam, &e->pr, &e->poscam);
	vecnorm(&e->dircam);
	cross_product(&e->vecdroit, &e->dircam, &e->vech);
	vecnorm(&e->vecdroit);
	upleft(e);
	vecnorm(&e->vecupleft);
	create_image(e);
}

void	create_image(t_stuff *e)
{
	e->img.img_ptr = mlx_new_image(e->img.mlx_ptr, WIDTH, LENGTH);
	e->img.data = mlx_get_data_addr(e->img.img_ptr,\
		&e->img.bits_per_pixel, &e->img.size_line, &e->img.endian);
}

void	upleft(t_stuff *e)
{
	t_vec tmp;
	t_vec tmp2;
	t_vec tmp3;

	tmp.x = e->distvue * e->dircam.x;
	tmp.y = e->distvue * e->dircam.y;
	tmp.z = e->distvue * e->dircam.z;
	tmp2.x = (e->longvue / 2) * e->vech.x;
	tmp2.y = (e->longvue / 2) * e->vech.y;
	tmp2.z = (e->longvue / 2) * e->vech.z;
	tmp3.x = (e->largvue / 2) * e->vecdroit.x;
	tmp3.y = (e->largvue / 2) * e->vecdroit.y;
	tmp3.z = (e->largvue / 2) * e->vecdroit.z;
	vecadd(&e->vecupleft, &e->poscam, &tmp);
	vecadd(&e->vecupleft, &e->vecupleft, &tmp2);
	vecsous(&e->vecupleft, &e->vecupleft, &tmp3);
}
