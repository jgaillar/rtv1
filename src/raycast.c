/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:09:06 by jgaillar          #+#    #+#             */
/*   Updated: 2017/10/04 11:09:07 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		getintersection(t_vec *poscam, t_vec *raydir, double dist, t_rt *rt)
{
	rt->inter.x = poscam->x + raydir->x * dist;
	rt->inter.y = poscam->y + raydir->y * dist;
	rt->inter.z = poscam->z + raydir->z * dist;
}

void		raycast(t_stuff *e, int x, int y)
{
	e->rt.dist = 9999;
	e->rt.obj = 0;
	raydir(e, x, y);
	checksphere(e, x, y);
	if (e->sphere.t < e->rt.dist && e->sphere.t > 0)
	{
		e->rt.dist = e->sphere.t;
		e->rt.obj = 1;
	}
	checkplan(e, x, y);
	if (e->plan.t < e->rt.dist && e->plan.t > 0)
	{
		e->rt.dist = e->plan.t;
		e->rt.obj = 2;
	}
	if (e->rt.obj == 1)
		mlx_pixel_put_to_image(e->img, x, y, 0x551A8B);
	else if (e->rt.obj == 2)
		mlx_pixel_put_to_image(e->img, x, y, 0xFB6500 * 0.2);
	else if (e->rt.obj == 0)
		mlx_pixel_put_to_image(e->img, x, y, 0x000000);
}

void		aff(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < LENGTH)
	{
		x = -1;
		while (++x < WIDTH)
		{
			raycast(e, x, y);
		}
	}
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->img.img_ptr, 0, 0);
}

void		raydir(t_stuff *e, int x, int y)
{
	t_vec	tmp;
	t_vec	tmp2;

	e->rt.xindent = e->largvue / WIDTH * x;
	e->rt.yindent = e->longvue / LENGTH * y;
	tmp.x = e->vecdroit.x * e->rt.xindent;
	tmp.y = e->vecdroit.y * e->rt.xindent;
	tmp.z = e->vecdroit.z * e->rt.xindent;
	tmp2.x = e->vech.x * e->rt.yindent;
	tmp2.y = e->vech.y * e->rt.yindent;
	tmp2.z = e->vech.z * e->rt.yindent;
	vecadd(&e->raydir, &e->vecupleft, &tmp);
	vecsous(&e->raydir, &e->raydir, &tmp2);
	vecnorm(&e->raydir);
}

void		checksphere(t_stuff *e, int x, int y)
{
	double	a;
	double	b;
	double	c;

	a = (e->raydir.x * e->raydir.x) + (e->raydir.y * e->raydir.y) + (e->raydir.z * \
		e->raydir.z);
	b = 2 * (e->raydir.x * (e->poscam.x - e->sphere.cx) + e->raydir.y * \
	(e->poscam.y - e->sphere.cy) + e->raydir.z * (e->poscam.z - e->sphere.cz));
	c = (((e->poscam.x - e->sphere.cx) * (e->poscam.x - e->sphere.cx)) + \
	((e->poscam.y - e->sphere.cy) * (e->poscam.y - e->sphere.cy)) + \
	((e->poscam.z = e->sphere.cz) * (e->poscam.z = e->sphere.cz)) - \
	(e->sphere.rayon * e->sphere.rayon));
	e->rt.det = (b * b) - 4 * a * c;
	if (e->rt.det < 0)
		e->sphere.t = -1;
	else if (e->rt.det == 0)
		e->sphere.t = (-b + sqrt(e->rt.det)) / (2 * a);
	else if (e->rt.det > 0)
	{
		e->rt.t1 = (-b + sqrt(e->rt.det)) / (2 * a);
		e->rt.t2 = (-b - sqrt(e->rt.det)) / (2 * a);
		e->sphere.t = (e->rt.t1 < e->rt.t2 ? e->rt.t1 : e->rt.t2);
	}

}

void		checkplan(t_stuff *e, int x, int y)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = e->poscam.x - e->plan.planx;
	b = e->poscam.y - e->plan.plany;
	c = e->poscam.z - e->plan.planz;
	d = e->plan.planx + e->plan.plany + e->plan.planz;

	e->plan.t = -(e->plan.normx * a + e->plan.normy * b + e->plan.normz * c + d) \
	/ (e->plan.normx * e->raydir.x + e->plan.normy * \
		e->raydir.y + e->plan.normz * e->raydir.z);
}
