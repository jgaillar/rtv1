/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 13:09:32 by jgaillar          #+#    #+#             */
/*   Updated: 2017/11/30 15:49:01 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_struct(t_stuff *e)
{
	e->poscam.x = 0;
	e->poscam.y = 0;
	e->poscam.z = 0;
	e->pr.x = 10;
	e->pr.y = 0;
	e->pr.z = 0;
	e->vech.x = 0;
	e->vech.y = 0;
	e->vech.z = 1;
	e->c.distvue = 1;
	e->c.largvue = 0.5;
	e->c.longvue = 0.3;
	e->sphere.pos.x = 40;
	e->sphere.pos.y = 0;
	e->sphere.pos.z = 0;
	e->sphere.ray = 2;
	e->sphere.color.r = 85;
	e->sphere.color.g = 26;
	e->sphere.color.b = 139;
	e->cyl.pos.x = 30;
	e->cyl.pos.y = 2;
	e->cyl.pos.z = 0;
	e->cyl.norm.x = 0;
	e->cyl.norm.y = 0;
	e->cyl.norm.z = -1;
	e->cyl.color.r = 0;
	e->cyl.color.g = 51;
	e->cyl.color.b = 102;
	e->cyl.ray = 2;
	e->plan.norm.x = 0;
	e->plan.norm.y = 0;
	e->plan.norm.z = 1;
	e->plan.pos.x = 1;
	e->plan.pos.y = 0;
	e->plan.pos.z = 0;
	e->plan.color.r = 226;
	e->plan.color.g = 204;
	e->plan.color.b = 95;
	e->light.pos.x = 30;
	e->light.pos.y = -5;
	e->light.pos.z = 0;
	e->light.ray = 0.5;
	e->light.color.r = 255;
	e->light.color.g = 255;
	e->light.color.b = 255;
	e->light.amb = 0.1;
	e->light.diff = 0.7;
	e->con.pos.x = 15;
	e->con.pos.y = 0;
	e->con.pos.z = 0;
	e->con.color.r = 218;
	e->con.color.g = 134;
	e->con.color.b = 255;
	e->rt.colorf = 0;
	e->pix = 0;
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

	tmp.x = e->c.distvue * e->dircam.x;
	tmp.y = e->c.distvue * e->dircam.y;
	tmp.z = e->c.distvue * e->dircam.z;
	tmp2.x = (e->c.longvue / 2) * e->vech.x;
	tmp2.y = (e->c.longvue / 2) * e->vech.y;
	tmp2.z = (e->c.longvue / 2) * e->vech.z;
	tmp3.x = (e->c.largvue / 2) * e->vecdroit.x;
	tmp3.y = (e->c.largvue / 2) * e->vecdroit.y;
	tmp3.z = (e->c.largvue / 2) * e->vecdroit.z;
	vecadd(&e->vecupleft, &e->poscam, &tmp);
	vecadd(&e->vecupleft, &e->vecupleft, &tmp2);
	vecsous(&e->vecupleft, &e->vecupleft, &tmp3);
}
