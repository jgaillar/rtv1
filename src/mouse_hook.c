/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:14:48 by jgaillar          #+#    #+#             */
/*   Updated: 2018/01/04 16:14:49 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		check_distdebug(t_stuff *e, int option)
{
	if (e->c.distsph < e->c.dist && e->c.distsph > 0.00001)
	{
		e->c.obj = (e->c.distsph < e->c.dist ? SPHERE : -1);
		e->c.dist = e->c.distsph;
		e->d.color.r = e->d.colsph.r;
		e->d.color.g = e->d.colsph.g;
		e->d.color.g = e->d.colsph.b;
	}
	if (e->c.distpla < e->c.dist && e->c.distpla > 0.00001)
	{
		e->c.obj = (e->c.distpla < e->c.dist ? PLAN : e->c.obj);
		e->c.dist = e->c.distpla;
		e->d.color.r = e->d.colpla.r;
		e->d.color.g = e->d.colpla.g;
		e->d.color.b = e->d.colpla.b;
	}
	if (e->c.distcyl < e->c.dist && e->c.distcyl > 0.00001)
	{
		e->c.obj = (e->c.distcyl < e->c.dist ? CYLINDRE : e->c.obj);
		e->c.dist = e->c.distcyl;
		e->d.color.r = e->d.colcyl.r;
		e->d.color.g = e->d.colcyl.g;
		e->d.color.b = e->d.colcyl.b;
	}
	if (e->c.distcone < e->c.dist && e->c.distcone > 0.00001)
	{
		e->c.obj = (e->c.distcone < e->c.dist ? CONE : e->c.obj);
		e->c.dist = e->c.distcone;
		e->d.color.r = e->d.colcone.r;
		e->d.color.g = e->d.colcone.g;
		e->d.color.g = e->d.colcone.b;
	}
	if (e->c.distlight < e->c.dist && e->c.distlight > 0.00001 && option == 1)
	{
		e->c.obj = (e->c.distlight < e->c.dist ? LIGHT : e->c.obj);
		e->c.dist = e->c.distlight;
	}
}

void		checkdebug(t_stuff *e, t_vec *raydir, t_vec *pos, int option)
{
	e->c.dist = INFINITY;
	e->c.distsph = INFINITY;
	e->c.distpla = INFINITY;
	e->c.distcyl = INFINITY;
	e->c.distcone = INFINITY;
	e->c.distlight = INFINITY;
	if (option == 1)
		e->c.obj = -1;
	while (e->sph)
	{
		checksphere(e->sph, raydir, pos);
		if (e->sph->t < e->c.distsph && e->sph->t > 0.00001)
		{
			e->c.distsph = e->sph->t;
			if (option == 1)
			{
				e->c.objsph = e->sph->nm;
				e->c.obj = SPHERE;
			}
			else
			{
				e->d.colsph.r = e->sph->color.r;
				e->d.colsph.g = e->sph->color.g;
				e->d.colsph.b = e->sph->color.b;
			}
		}
		e->sph = e->sph->next;
	}
	while (e->pla)
	{
		checkplan(e->pla, raydir, pos);
		if (e->pla->t < e->c.distpla && e->pla->t > 0.00001)
		{
			e->c.distpla = e->pla->t;
			if (option == 1)
			{
				e->c.objpla = e->pla->nm;
				e->c.obj = PLAN;
			}
			else
			{
				e->d.colpla.r = e->pla->color.r;
				e->d.colpla.g = e->pla->color.g;
				e->d.colpla.b = e->pla->color.b;
			}
		}
		e->pla = e->pla->next;
	}
	while (e->cyl)
	{
		checkcyl(e->cyl, raydir, pos);
		if (e->cyl->t < e->c.distcyl && e->cyl->t > 0.00001)
		{
			e->c.distcyl = e->cyl->t;
			if (option == 1)
			{
				e->c.objcyl = e->cyl->nm;
				e->c.obj = CYLINDRE;
			}
			else
			{
				e->d.colcyl.r = e->cyl->color.r;
				e->d.colcyl.g = e->cyl->color.g;
				e->d.colcyl.b = e->cyl->color.b;
			}
		}
		e->cyl = e->cyl->next;
	}
	while (e->cone)
	{
		checkcone(e->cone, raydir, pos);
		if (e->cone->t < e->c.distcone && e->cone->t > 0.00001)
		{
			e->c.distcone = e->cone->t;
			if (option == 1)
			{
				e->c.objcone = e->cone->nm;
				e->c.obj = CONE;
			}
			else
			{
				e->d.colcone.r = e->cone->color.r;
				e->d.colcone.g = e->cone->color.g;
				e->d.colcone.b = e->cone->color.b;
			}
		}
		e->cone = e->cone->next;
	}
	while (e->light && option == 1)
	{
		checklight(e->light, raydir, pos);
		if (e->light->t < e->c.distlight && e->light->t > 0.00001)
		{
			e->c.distlight = e->light->t;
			e->c.objlight = e->light->nm;
			e->c.obj = LIGHT;
		}
		e->light = e->light->next;
	}
}

int		raythingydebug(t_stuff *e)
{
	reboot_list_loop(e, 3);
	checkdebug(e, &e->raydir, &e->poscam, 1);
	check_distdebug(e, 1);
	ft_putendl("1");
	printf("sph : [%f] | pla : [%f]\n\n", e->c.distsph, e->c.distpla);
	reboot_list_loop(e, 3);
	e->c.colorf.r = 0;
	e->c.colorf.g = 0;
	e->c.colorf.b = 0;
	if (e->c.obj >= 0 && e->c.obj <= 3)
	{
		getintersection(e, e->c.dist);
		printf("interx : [%f] | intery : [%f] | interz : [%f]\n\n", e->c.inter.x, e->c.inter.y, e->c.inter.z);
		while (e->light)
		{
			getlightdir(e, e->c.inter);
			reboot_list_loop(e, 1);
			printf("dirx : [%f] | diry : [%f] | dirz : [%f]\n\n", e->light->lightdir.x, e->light->lightdir.y, e->light->lightdir.z);
			checkdebug(e, &e->light->lightdir, &e->c.inter, 2);
			check_distdebug(e, 2);
			ft_putendl("2");
			printf("sph : [%f] | pla : [%f]\n\n", e->c.distsph, e->c.distpla);
			checklight(e->light, &e->light->lightdir, &e->c.inter);
			printf("lightdist : [%f]\n\n", e->light->t);
		 	// printf("sph : [%f] | pla : [%f]\n", e->c.distsph, e->c.distpla);
			if (e->c.dist > e->light->t && e->c.dist > 0.00001 && e->light->t > 0.00001)
			{
				ft_putendl("3");
				printf("sph : [%f] | pla : [%f]\n\n", e->c.distsph, e->c.distpla);
				if (e->c.obj == SPHERE)
				{
					searchlist(e, e->c.objsph, SPHERE);
					vecsous(&e->sph->norm, &e->c.inter, &e->sph->pos);
					vecnorm(&e->sph->norm);
					rgb_add(&e->c.colorf, e->c.colorf, \
						getlight(&e->sph->norm, &e->light, &e->sph->color, e), 1);
				}
				else if (e->c.obj == PLAN)
				{
					searchlist(e, e->c.objpla, PLAN);
					rgb_add(&e->c.colorf, e->c.colorf, \
						getlight(&e->pla->norm, &e->light, &e->pla->color, e), 1);
				}
				else if (e->c.obj == CYLINDRE)
				{
					searchlist(e, e->c.objcyl, CYLINDRE);
					vecsous(&e->cyl->norml, &e->c.inter, &e->cyl->pos);
					vecnorm(&e->cyl->norml);
					e->cyl->norml.z = 0;
					vecnorm(&e->cyl->norml);
					rgb_add(&e->c.colorf, e->c.colorf, \
							getlight(&e->cyl->norml, &e->light, &e->cyl->color, e), 1);
				}
				else if (e->c.obj == CONE)
				{
					searchlist(e, e->c.objcone, CONE);
					vecsous(&e->cone->norml, &e->c.inter, &e->cone->pos);
					vecnorm(&e->cone->norml);
					rgb_add(&e->c.colorf, e->c.colorf,\
					 	getlight(&e->cone->norm, &e->light, &e->cone->color, e), 1);
			 	}
			}
			else
			{
				e->d.color.r = 255;
				e->d.color.g = 0;
				e->d.color.b = 0;
				shadows(e, &e->c.inter, e->d.color);
			}
			e->light = e->light->next;
		}
	}
	else if (e->c.obj == LIGHT)
	{
		searchlist(e, e->c.objlight, LIGHT);
		rgb_add(&e->c.colorf, e->c.colorf, e->light->color, e->light->diff);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_stuff *e)
{
	double color;

	if (button == 1 && (x >= 0 && x <= WIDTH) && (y >= 0 && y <= LENGTH))
	{
		mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->img.img_ptr, 0, 0);
		reboot_list_loop(e, 3);
		raydir(e, x, y);
		check(e, &e->raydir, &e->poscam, 1);
		check_dist(e, 1);
		if (e->c.obj == 0)
		{
			color = 0x6a74af;
			ft_putstr("SPHERE : ");
			ft_putnbr(e->c.objsph);
			ft_putchar('\n');
		}
		else if (e->c.obj == 1)
		{
			color = 0xf3a1d1;
			ft_putstr("PLAN : ");
			ft_putnbr(e->c.objpla);
			ft_putchar('\n');
		}
		else if (e->c.obj == 2)
		{
			color = 0xff5370;
			ft_putstr("CYLINDRE : ");
			ft_putnbr(e->c.objcyl);
			ft_putchar('\n');
		}
		else if (e->c.obj == 3)
		{
			color = 0x73d1c8;
			ft_putstr("CONE : ");
			ft_putnbr(e->c.objcone);
			ft_putchar('\n');
		}
		else if (e->c.obj == 4)
		{
			color = 0xff9966;
			ft_putstr("LIGHT : ");
			ft_putnbr(e->c.objlight);
			ft_putchar('\n');
		}
		if (e->c.obj > -1)
			ft_segment(e, x, y, color);
	}
	if (button == 2 && (x >= 0 && x <= WIDTH) && (y >= 0 && y <= LENGTH))
	{
		reboot_list_loop(e, 3);
		raydir(e, x, y);
		raythingydebug(e);
	}
	return (0);
}
