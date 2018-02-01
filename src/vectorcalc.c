/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorcalc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 10:07:54 by jgaillar          #+#    #+#             */
/*   Updated: 2018/02/01 12:05:39 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		raydir(t_stuff *e, int x, int y)
{
	t_vec	tmp;
	t_vec	tmp2;

	e->c.xindent = e->c.largvue / WIDTH * x;
	e->c.yindent = e->c.longvue / LENGTH * y;
	tmp.x = e->vecdroit.x * e->c.xindent;
	tmp.y = e->vecdroit.y * e->c.xindent;
	tmp.z = e->vecdroit.z * e->c.xindent;
	tmp2.x = e->vech.x * e->c.yindent;
	tmp2.y = e->vech.y * e->c.yindent;
	tmp2.z = e->vech.z * e->c.yindent;
	vecadd(&e->raydir, &e->vecupleft, &tmp);
	vecsous(&e->raydir, &e->raydir, &tmp2);
	vecnorm(&e->raydir);
}

void	upleft(t_stuff *e)
{
	t_vec tmp;
	t_vec tmp2;
	t_vec tmp3;
	t_vec o;

	o.x = 0;
	o.y = 0;
	o.z = 0;
	tmp.x = e->c.distvue * e->dircam.x;
	tmp.y = e->c.distvue * e->dircam.y;
	tmp.z = e->c.distvue * e->dircam.z;
	tmp2.x = (e->c.longvue / 2) * e->vech.x;
	tmp2.y = (e->c.longvue / 2) * e->vech.y;
	tmp2.z = (e->c.longvue / 2) * e->vech.z;
	tmp3.x = (e->c.largvue / 2) * e->vecdroit.x;
	tmp3.y = (e->c.largvue / 2) * e->vecdroit.y;
	tmp3.z = (e->c.largvue / 2) * e->vecdroit.z;
	vecadd(&e->vecupleft, &o, &tmp);
	vecadd(&e->vecupleft, &e->vecupleft, &tmp2);
	vecsous(&e->vecupleft, &e->vecupleft, &tmp3);
	vecnorm(&e->vecupleft);
}

void	vectorcalc(t_stuff *e)
{
	vecsous(&e->dircam, &e->pr, &e->poscam);
	vecnorm(&e->dircam);
	cross_product(&e->vecdroit, &e->dircam, &e->vech);
	vecnorm(&e->vecdroit);
	upleft(e);
}
