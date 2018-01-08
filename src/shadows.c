/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:00:01 by jgaillar          #+#    #+#             */
/*   Updated: 2017/12/15 14:00:03 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		shadows(t_stuff *e, t_vec *inter, t_vec *lightdir, t_rgb color)
{
	t_rgb caca;

	caca.r = 0;
	caca.g = 0;
	caca.b = 0;
	checklight(e->light, lightdir, inter);
	check(e, lightdir, inter, e->light->t);
	check_dist(e, 0);
	if (e->c.dist < e->light->t && e->c.dist > 0.00001 && e->c.obj != LIGHT)
	{
		rgb_add(&e->c.colorf, caca, color, 0.6);
		return (1);
	}
	return (0);
}
