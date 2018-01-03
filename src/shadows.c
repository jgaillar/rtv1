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
	checklight(e->light, lightdir, inter);
	check(e, lightdir, inter, e->light->t);
	check_dist(e, 0);
	if (e->c.dist < e->light->t && e->c.dist > 0.00001 && e->c.obj != LIGHT)
		return (rgbtohexa(color.r * e->light->amb, color.g * e->light->amb, color.b * e->light->amb));
	return (0);
}
