/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 13:09:32 by jgaillar          #+#    #+#             */
/*   Updated: 2017/08/08 13:09:33 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_struct(t_stuff *e)
{
	e->poscam.x = 15;
	e->poscam.y = 20;
	e->poscam.z = 50;
	e->pr.x = 10;
	e->pr.y = 10;
	e->pr.z = 15;
	e->vech.x = 0;
	e->vech.y = 0;
	e->vech.z = 1;
	veclength(&e->vech);
	vecnorm(&e->vech);
	printf("vechx : [%f]\nvechy : [%f]\nvechz : [%f]\n", e->vech.x, e->vech.y, e->vech.z);
	e->distvue = 1;
	e->largvue = 0.5;
	e->longvue = 0.35;
	e->sphere.cx = 15;
	e->sphere.cy = 15;
	e->sphere.cz = 30;
	e->sphere.rayon = 20;
	vecsous(&e->dircam, &e->pr, &e->poscam);
	veclength(&e->dircam);
	vecnorm(&e->dircam);
	printf("dircamx : [%f]\ndircamy : [%f]\ndircamz : [%f]\n", e->dircam.x, e->dircam.y, e->dircam.z);
	cross_product(&e->vecdroit, &e->dircam, &e->vech);
	veclength(&e->vecdroit);
	vecnorm(&e->vecdroit);
	printf("vecdroitx : [%f]\nvecdroity : [%f]\nvecdroitz : [%f]\n", e->vecdroit.x, e->vecdroit.y, e->vecdroit.z);
	upleft(e);
	printf("vecupleftx : [%f]\nvecuplefty : [%f]\nvecupleftz : [%f]\n", e->vecupleft.x, e->vecupleft.y, e->vecupleft.z);
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
