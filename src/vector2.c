/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 09:44:13 by jgaillar          #+#    #+#             */
/*   Updated: 2017/11/22 11:57:22 by jgaillar         ###   ########.fr       */
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

void		getintersection(t_vec *poscam, t_vec *raydir, double dist, t_rt *rt)
{
	rt->inter.x = poscam->x + raydir->x * dist;
	rt->inter.y = poscam->y + raydir->y * dist;
	rt->inter.z = poscam->z + raydir->z * dist;
}
