/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:23:23 by jgaillar          #+#    #+#             */
/*   Updated: 2017/10/04 11:23:24 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		vecsous(t_vec *res, t_vec *i, t_vec *j)
{
	res->x = i->x - j->x;
	res->y = i->y - j->y;
	res->z = i->z - j->z;
}

void		vecadd(t_vec *res, t_vec *i, t_vec *j)
{
	res->x = i->x + j->x;
	res->y = i->y + j->y;
	res->z = i->z + j->z;
}

int			dot_product(t_vec *i, t_vec *j)
{
	int res;

	res = ((i->x * j->x) + (i->y * j->y) + (i->z * j->z));
	return (res);
}

void		cross_product(t_vec *res, t_vec *i, t_vec *j)
{
	res->x = (i->y * j->z) - (i->z * j->y);
	res->y = (i->z * j->x) - (i->x * j->z);
	res->z = (i->x * j->y) - (i->y * j->x);
}

void		vecpuivec(t_vec *res, t_vec *i, t_vec *j)
{
	res->x = i->x * j->x;
	res->y = i->y * j->y;
	res->z = i->z * j->z;
}

void		veclength(t_vec *i)
{
	i->length = sqrt((i->x * i->x) + (i->y * i->y) + (i->z * i->z));
}

void		vecnorm(t_vec *i)
{
	if (!i->length)
		veclength(i);
	i->x = i->x / i->length;
	i->y = i->y / i->length;
	i->z = i->z / i->length;
	veclength(i);
}
