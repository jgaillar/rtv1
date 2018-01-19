/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:23:23 by jgaillar          #+#    #+#             */
/*   Updated: 2017/12/05 09:16:54 by jgaillar         ###   ########.fr       */
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

double		dot_product(t_vec *i, t_vec *j)
{
	double res;

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
