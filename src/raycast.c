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
