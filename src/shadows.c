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

double		shadows(t_stuff *e, t_vec *inter)
{
	t_rgb caca;

	caca.r = 0;
	caca.g = 0;
	caca.b = 0;
	while (e->light)
	{
		reboot_list_loop(e, 1);
		getlightdir(e, *inter);
		checklight(e->light, &e->light->lightdir, inter);
		check(e, &e->light->lightdir, inter, 2);
		check_dist(e, 2);
		if (e->c.dist < e->light->t && e->c.dist > 0.00001 && e->c.obj != LIGHT)
			rgb_add(&e->c.colorf, caca, e->c.colorf, 0.8);
		if (e->light->next == NULL)
			return (1);
		e->light = e->light->next;
	}
	return (0);
}
