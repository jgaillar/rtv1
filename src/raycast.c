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

void		raycast(t_stuff *e)
{
	int x;
	int y;

	y = -1;
	while (++y < LENGTH)
	{
		x = -1;
		while (++x < WIDTH)
		{
			raydir(e, x, y);
		}
	}
}

void		raydir(t_stuff *e, int x, int y)
{
	int		xindent;
	int		yindent;
	t_vec	tmp;
	t_vec	tmp2;

	xindent = (e->largvue / WIDTH) * x;
	yindent = (e->longvue / LENGTH) * y;
	tmp.x = e->vecdroit.x * xindent;
	tmp.y = e->vecdroit.y * xindent;
	tmp.z = e->vecdroit.z * xindent;
	tmp2.x = e->vech.x * yindent;
	tmp2.y = e->vech.y * yindent;
	tmp2.z = e->vech.z * yindent;
	vecadd(&e->raydir, &e->vecupleft, &tmp);
	vecsous(&e->raydir, &e->raydir, &tmp2);
}

void		checksphere(t_stuff *e, int x, int y)
{
	int	a;
	int	b;
	int	c;

	a = e->raydir.x * e->raydir.x + e->raydir.y * e->raydir.y + e->raydir.z * \
		e->raydir.z;
	b = 2 * (e->raydir.x * (e->poscam.x - e->sphere.cx) + e->raydir.y * \
	(e->poscam.y - e->sphere.cy) + e->raydir.z * (e->poscam.z - e->sphere.cz));
	c = (((e->poscam.x - e->sphere.cx) * (e->poscam.x - e->sphere.cx)) + \
	((e->poscam.y - e->sphere.cy) * (e->poscam.y - e->sphere.cy)) + \
	((e->poscam.z = e->sphere.cz) * (e->poscam.z = e->sphere.cz)) - \
	(e->sphere.rayon * e->sphere.rayon));
	e->rt.det = (b * b) - 4 * a * c;
	if (e->rt.det < 0)
		mlx_pixel_put_to_image(e->img, x, y, 0x000000);
	else if (e->rt.det == 0)
		e->rt.t = (-b + sqrt(e->rt.det)) / (2 * a);
	else if (e->rt.det > 0)
	{
		e->rt.t1 = (-b + sqrt(e->rt.det)) / (2 * a);
		e->rt.t2 = (-b - sqrt(e->rt.det)) / (2 * a);
		e->rt.t = (e->rt.t1 < e->rt.t2 ? e->rt.t1 : e->rt.t2);
	}

}
