/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_obj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:54:37 by jgaillar          #+#    #+#             */
/*   Updated: 2017/12/01 15:05:37 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		cylindre(t_stuff *e, int y)
{
	if (ft_strcmp(e->b.tab[y - 1], "------") != 0)
		return (-1);
	if (ft_strcmp(e->b.tab[y + 1], "------") != 0)
		return (-1);
	y += 2;
	if (!(e->d.tabdcyl = (double *)malloc(sizeof(double) * 10)))
		return (-1);
	if (check_data_cylindre(e, y) == -1)
		return (-1);
	if (e->d.nbmcyl != 0)
	{
		e->tmpcyl = e->cyl;
		init_list_cyl(&e->cyl->next);
		e->cyl = e->cyl->next;
		e->cyl->prev = e->tmpcyl;
	}
	fill_list_cyl(&e->cyl, e->d.tabdcyl, e->d.nbmcyl);
	e->d.nbmcyl++;
	return (0);
}

int		light(t_stuff *e, int y)
{
	if (ft_strcmp(e->b.tab[y - 1], "------") != 0)
		return (-1);
	if (ft_strcmp(e->b.tab[y + 1], "------") != 0)
		return (-1);
	y += 2;
	if (!(e->d.tabdlight = (double *)malloc(sizeof(double) * 9)))
		return (-1);
	if (check_data_light(e, y) == -1)
		return (-1);
	if (e->d.nbmlight != 0)
	{
		e->tmplight = e->light;
		init_list_light(&e->light->next);
		e->light = e->light->next;
		e->light->prev = e->tmplight;
	}
	fill_list_light(&e->light, e->d.tabdlight, e->d.nbmlight);
	e->d.nbmlight++;
	return (0);
}

int		plan(t_stuff *e, int y)
{
	if (ft_strcmp(e->b.tab[y - 1], "------") != 0)
		return (-1);
	if (ft_strcmp(e->b.tab[y + 1], "------") != 0)
		return (-1);
	y += 2;
	if (!(e->d.tabdpla = (double *)malloc(sizeof(double) * 9)))
		return (-1);
	if (check_data_plan(e, y) == -1)
		return (-1);
	if (e->d.nbmpla != 0)
	{
		e->tmppla = e->pla;
		init_list_pla(&e->pla->next);
		e->pla = e->pla->next;
		e->pla->prev = e->tmppla;
	}
	fill_list_pla(&e->pla, e->d.tabdpla, e->d.nbmpla);
	e->d.nbmpla++;
	return (0);
}

int		sphere(t_stuff *e, int y)
{
	if (ft_strcmp(e->b.tab[y - 1], "------") != 0)
		return (-1);
	if (ft_strcmp(e->b.tab[y + 1], "------") != 0)
		return (-1);
	y += 2;
	if (!(e->d.tabd = (double *)malloc(sizeof(double) * 7)))
		return (-1);
	if (check_data_sphere(e, y) == -1)
		return (-1);
	if (e->d.nbmsph != 0)
	{
		e->tmp = e->sph;
		init_list_sph(&e->sph->next);
		e->sph = e->sph->next;
		e->sph->prev = e->tmp;
	}
	fill_list_sph(&e->sph, e->d.tabd, e->d.nbmsph);
	e->d.nbmsph++;
	return (0);
}

int		cone(t_stuff *e, int y)
{
	if (ft_strcmp(e->b.tab[y - 1], "------") != 0)
		return (-1);
	if (ft_strcmp(e->b.tab[y + 1], "------") != 0)
		return (-1);
	y += 2;
	if (!(e->d.tabdcone = (double *)malloc(sizeof(double) * 10)))
		return (-1);
	if (check_data_cone(e, y) == -1)
		return (-1);
	if (e->d.nbmcone != 0)
	{
		e->tmpcone = e->cone;
		init_list_cone(&e->cone->next);
		e->cone = e->cone->next;
		e->cone->prev = e->tmpcone;
	}
	fill_list_cone(&e->cone, e->d.tabdcone, e->d.nbmcone);
	e->d.nbmcone++;
	return (0);
}
