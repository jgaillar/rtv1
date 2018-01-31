/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:32:49 by prossi            #+#    #+#             */
/*   Updated: 2018/01/31 13:11:12 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		init_list_cone(t_cone **cone)
{
	if (!(*cone = (t_cone *)malloc(sizeof(t_cone))))
		return (-1);
	(*cone)->prev = NULL;
	(*cone)->pos.x = 0;
	(*cone)->pos.y = 0;
	(*cone)->pos.z = 0;
	(*cone)->color.r = 0;
	(*cone)->color.g = 0;
	(*cone)->color.b = 0;
	(*cone)->norm.x = 0;
	(*cone)->norm.y = 0;
	(*cone)->norm.z = 0;
	(*cone)->angle = 0;
	(*cone)->next = NULL;
	return (0);
}

int		init_list_cyl(t_cyl **cyl)
{
	if (!(*cyl = (t_cyl *)malloc(sizeof(t_cyl))))
		return (-1);
	(*cyl)->prev = NULL;
	(*cyl)->pos.x = 0;
	(*cyl)->pos.y = 0;
	(*cyl)->pos.z = 0;
	(*cyl)->color.r = 0;
	(*cyl)->color.g = 0;
	(*cyl)->color.b = 0;
	(*cyl)->norm.x = 0;
	(*cyl)->norm.y = 0;
	(*cyl)->norm.z = 0;
	(*cyl)->ray = 0;
	(*cyl)->next = NULL;
	return (0);
}

int		init_list_light(t_light **light)
{
	if (!(*light = (t_light *)malloc(sizeof(t_light))))
		return (-1);
	(*light)->prev = NULL;
	(*light)->pos.x = 0;
	(*light)->pos.y = 0;
	(*light)->pos.z = 0;
	(*light)->color.r = 0;
	(*light)->color.g = 0;
	(*light)->color.b = 0;
	(*light)->ray = 0;
	(*light)->amb = 0;
	(*light)->diff = 0;
	(*light)->next = NULL;
	return (0);
}

int		init_list_sph(t_sphere **sph)
{
	if (!(*sph = (t_sphere *)malloc(sizeof(t_sphere))))
		return (-1);
	(*sph)->prev = NULL;
	(*sph)->pos.x = 0;
	(*sph)->pos.y = 0;
	(*sph)->pos.z = 0;
	(*sph)->color.r = 0;
	(*sph)->color.g = 0;
	(*sph)->color.b = 0;
	(*sph)->ray = 0;
	(*sph)->next = NULL;
	return (0);
}

int		init_list_pla(t_plan **pla)
{
	if (!(*pla = (t_plan *)malloc(sizeof(t_plan))))
		return (-1);
	(*pla)->prev = NULL;
	(*pla)->pos.x = 0;
	(*pla)->pos.y = 0;
	(*pla)->pos.z = 0;
	(*pla)->color.r = 0;
	(*pla)->color.g = 0;
	(*pla)->color.b = 0;
	(*pla)->norm.x = 0;
	(*pla)->norm.y = 0;
	(*pla)->norm.z = 0;
	(*pla)->next = NULL;
	return (0);
}

void	fill_list_sph(t_sphere **sph, double *tabd, int nbm)
{
	(*sph)->pos.x = tabd[0];
	(*sph)->pos.y = tabd[1];
	(*sph)->pos.z = tabd[2];
	(*sph)->ray = tabd[3];
	(*sph)->color.r = tabd[4];
	(*sph)->color.g = tabd[5];
	(*sph)->color.b = tabd[6];
	(*sph)->nm = nbm;
	free(tabd);
}

void	fill_list_pla(t_plan **pla, double *tabdpla, int nbmpla)
{
	(*pla)->pos.x = tabdpla[0];
	(*pla)->pos.y = tabdpla[1];
	(*pla)->pos.z = tabdpla[2];
	(*pla)->color.r = tabdpla[3];
	(*pla)->color.g = tabdpla[4];
	(*pla)->color.b = tabdpla[5];
	(*pla)->norm.x = tabdpla[6];
	(*pla)->norm.y = tabdpla[7];
	(*pla)->norm.z = tabdpla[8];
	(*pla)->nm = nbmpla;
	free(tabdpla);
}

void	fill_list_light(t_light **light, double *tabdlight, int nbmlight)
{
	(*light)->pos.x = tabdlight[0];
	(*light)->pos.y = tabdlight[1];
	(*light)->pos.z = tabdlight[2];
	(*light)->ray = tabdlight[3];
	(*light)->color.r = tabdlight[4];
	(*light)->color.g = tabdlight[5];
	(*light)->color.b = tabdlight[6];
	(*light)->amb = tabdlight[7];
	(*light)->diff = tabdlight[8];
	(*light)->nm = nbmlight;
	free(tabdlight);
}

void	fill_list_cyl(t_cyl **cyl, double *tabdcyl, int nbmcyl)
{
	(*cyl)->pos.x = tabdcyl[0];
	(*cyl)->pos.y = tabdcyl[1];
	(*cyl)->pos.z = tabdcyl[2];
	(*cyl)->norm.x = tabdcyl[3];
	(*cyl)->norm.y = tabdcyl[4];
	(*cyl)->norm.z = tabdcyl[5];
	(*cyl)->ray = tabdcyl[6];
	(*cyl)->color.r = tabdcyl[7];
	(*cyl)->color.g = tabdcyl[8];
	(*cyl)->color.b = tabdcyl[9];
	(*cyl)->nm = nbmcyl;
	free(tabdcyl);
}

void	fill_list_cone(t_cone **cone, double *tabdcone, int nbmcone)
{
	(*cone)->pos.x = tabdcone[0];
	(*cone)->pos.y = tabdcone[1];
	(*cone)->pos.z = tabdcone[2];
	(*cone)->color.r = tabdcone[3];
	(*cone)->color.g = tabdcone[4];
	(*cone)->color.b = tabdcone[5];
	(*cone)->norm.x = tabdcone[6];
	(*cone)->norm.y = tabdcone[7];
	(*cone)->norm.z = tabdcone[8];
	(*cone)->angle = tabdcone[9];
	(*cone)->nm = nbmcone;
	free(tabdcone);
}

void	reboot_list(t_stuff *e)
{
	while (e->sph->prev != NULL)
		e->sph = e->sph->prev;
	while (e->pla->prev != NULL)
		e->pla = e->pla->prev;
	while (e->light->prev != NULL)
		e->light = e->light->prev;
	while (e->cyl->prev != NULL)
		e->cyl = e->cyl->prev;
	while (e->cone->prev != NULL)
		e->cone = e->cone->prev;
	e->tmp = e->sph;
	e->tmppla = e->pla;
	e->tmplight = e->light;
	e->tmpcyl = e->cyl;
	e->tmpcone = e->cone;
}

void	reboot_list_loop(t_stuff *e, int option)
{
	if (option == 1 || option == 3)
	{
		e->sph = e->tmp;
		e->pla = e->tmppla;
		e->cyl = e->tmpcyl;
		e->cone = e->tmpcone;
	}
	if (option == 2 || option == 3)
		e->light = e->tmplight;
}

void	searchlist(t_stuff *e, int nmail, int nlist)
{
	reboot_list_loop(e, 1);
	if (nlist == SPHERE)
	{
		while (e->sph->nm != nmail)
			e->sph = e->sph->next;
	}
	if (nlist == PLAN)
	{
		while (e->pla->nm != nmail)
		e->pla = e->pla->next;
	}
	if (nlist == CYLINDRE)
	{
		while (e->cyl->nm != nmail)
			e->cyl = e->cyl->next;
	}
	if (nlist == CONE)
	{
		while (e->cone->nm != nmail)
			e->cone = e->cone->next;
	}
	if (nlist == LIGHT)
	{
	while (e->light->nm != nmail)
		e->light = e->light->next;
	}
}

void	print_list(t_stuff *e)
{
	printf("\n------\nDEBUT DES SPHERES\n------\n\n");
	while (e->sph)
	{
		printf("PosX : [%f]\n", e->sph->pos.x);
		printf("PosY : [%f]\n", e->sph->pos.y);
		printf("PosZ : [%f]\n", e->sph->pos.z);
		printf("Rayon : [%f]\n", e->sph->ray);
		printf("ColorR : [%d]\n", e->sph->color.r);
		printf("ColorG : [%d]\n", e->sph->color.g);
		printf("ColorB : [%d]\n", e->sph->color.b);
		printf("Numero du maillon : [%d]\n", e->sph->nm);
		e->sph = e->sph->next;
		ft_putchar('\n');
	}
	printf("\n\n------\nDEBUT DES PLANS\n------\n\n");
	while (e->pla)
	{
		printf("PosX : [%f]\n", e->pla->pos.x);
		printf("PosY : [%f]\n", e->pla->pos.y);
		printf("PosZ : [%f]\n", e->pla->pos.z);
		printf("ColorR : [%d]\n", e->pla->color.r);
		printf("ColorG : [%d]\n", e->pla->color.g);
		printf("ColorB : [%d]\n", e->pla->color.b);
		printf("NormX : [%f]\n", e->pla->norm.x);
		printf("NormY : [%f]\n", e->pla->norm.y);
		printf("NormZ : [%f]\n", e->pla->norm.z);
		printf("Numero du maillon : [%d]\n", e->pla->nm);
		e->pla = e->pla->next;
		ft_putchar('\n');
	}
	printf("\n\n------\nDEBUT DES LIGHT\n------\n\n");
	while (e->light)
	{
		printf("PosX : [%f]\n", e->light->pos.x);
		printf("PosY : [%f]\n", e->light->pos.y);
		printf("PosZ : [%f]\n", e->light->pos.z);
		printf("Rayon : [%f]\n", e->light->ray);
		printf("ColorR : [%d]\n", e->light->color.r);
		printf("ColorG : [%d]\n", e->light->color.g);
		printf("ColorB : [%d]\n", e->light->color.b);
		printf("Lum. Amb : [%f]\n", e->light->amb);
		printf("Lum. Diff : [%f]\n", e->light->diff);
		printf("Numero du maillon : [%d]\n", e->light->nm);
		e->light = e->light->next;
		ft_putchar('\n');
	}
	printf("\n------\nDEBUT DES CYLINDRES\n------\n\n");
	while (e->cyl)
	{
		printf("posX : [%f]\n", e->cyl->pos.x);
		printf("posY : [%f]\n", e->cyl->pos.y);
		printf("posZ : [%f]\n", e->cyl->pos.z);
		printf("NormX : [%f]\n", e->cyl->norm.x);
		printf("NormY : [%f]\n", e->cyl->norm.y);
		printf("NormZ : [%f]\n", e->cyl->norm.z);
		printf("Rayon : [%f]\n", e->cyl->ray);
		printf("ColorR : [%d]\n", e->cyl->color.r);
		printf("ColorG : [%d]\n", e->cyl->color.g);
		printf("ColorB : [%d]\n", e->cyl->color.b);
		printf("Numero du maillon : [%d]\n", e->cyl->nm);
		e->cyl = e->cyl->next;
		ft_putchar('\n');
	}
	printf("\n------\nDEBUT DES CONES\n------\n\n");
	while (e->cone)
	{
		printf("PosX : [%f]\n", e->cone->pos.x);
		printf("PosY : [%f]\n", e->cone->pos.y);
		printf("PosZ : [%f]\n", e->cone->pos.z);
		printf("ColorR : [%d]\n", e->cone->color.r);
		printf("ColorG : [%d]\n", e->cone->color.g);
		printf("ColorB : [%d]\n", e->cone->color.b);
		printf("Numero du maillon : [%d]\n", e->cone->nm);
		e->cone = e->cone->next;
		ft_putchar('\n');
	}
}
