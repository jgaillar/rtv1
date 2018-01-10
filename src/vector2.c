/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 09:44:13 by jgaillar          #+#    #+#             */
/*   Updated: 2017/12/05 09:39:36 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		veclength(t_vec *i)
{
	i->length = sqrt((i->x * i->x) + (i->y * i->y) + (i->z * i->z));
}

void		vecnorm(t_vec *i)
{
	veclength(i);
	i->x = i->x / i->length;
	i->y = i->y / i->length;
	i->z = i->z / i->length;
	veclength(i);
}

void		getintersection(t_stuff *e, double dist)
{
	e->c.inter.x = e->poscam.x + (e->raydir.x * dist);
	e->c.inter.y = e->poscam.y + (e->raydir.y * dist);
	e->c.inter.z = e->poscam.z + (e->raydir.z * dist);
}

void		getlightdir(t_stuff *e, t_vec inter)
{
	vecsous(&e->light->lightdir, &e->light->pos, &inter);
	vecnorm(&e->light->lightdir);
}
