/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:09:06 by jgaillar          #+#    #+#             */
/*   Updated: 2017/12/05 12:27:59 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec		getrefray(t_stuff *e, t_vec *norm)
{
	t_vec res;
	double a;

	a = 2 * (dot_product(norm, &e->light->lightdir));
	res.x = a * norm->x - e->light->lightdir.x;
	res.y = a * norm->y - e->light->lightdir.y;
	res.z = a * norm->z - e->light->lightdir.z;
	vecnorm(&res);
	return (res);
}

void		getspeclight(t_stuff *e, t_vec *norm, t_rgb *color, t_light **light)
{
	double	a;
	t_vec	ref;
	t_vec	v;
	t_rgb tmp;

	vecsous(&v, &e->poscam, &e->c.inter);
	vecnorm(&v);
	ref = getrefray(e, norm);
	a = pow(dot_product(&ref, &v), 100);
	tmp.r = ((*light)->color.r) * (*light)->diff * a;
	tmp.g = ((*light)->color.g) * (*light)->diff * a;
	tmp.b = ((*light)->color.b) * (*light)->diff * a;
	rgb_add(color, *color, tmp, 1);
}

t_rgb		getlight(t_vec *norm, t_light **light, t_rgb *colorobj, t_stuff *e)
{
	t_rgb	rgb;
	double	angle;

	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	angle = ((*light)->ray > 0.00001 ? (dot_product(norm, &(*light)->lightdir)) \
		: 0);
	if ((*light)->ray > 0.00001 && angle > 0.00001)
	{
		if ((*light)->nm == 0)
		{
			rgb.r = colorobj->r * (*light)->amb;
			rgb.g = colorobj->g * (*light)->amb;
			rgb.b = colorobj->b * (*light)->amb;
		}
		rgb.r += (*light)->color.r * angle * (*light)->diff;
		rgb.g += (*light)->color.g * angle * (*light)->diff;
		rgb.b += (*light)->color.b * angle * (*light)->diff;
		getspeclight(e, norm, &rgb, light);
		return (rgb);
	}
	if ((*light)->nm == 0)
		rgb_add(&rgb, rgb, (*colorobj), (*light)->amb);
	return (rgb);
}

int		raythingy(t_stuff *e)
{
	check(e, &e->raydir, &e->poscam, 1);
	check_dist(e, 1);
	reboot_list_loop(e, 3);
	e->c.colorf.r = 0;
	e->c.colorf.g = 0;
	e->c.colorf.b = 0;
	if (e->c.obj >= 0 && e->c.obj <= 3)
	{
		getintersection(e, e->c.dist);
		while (e->light)
		{
			getlightdir(e, e->c.inter);
			reboot_list_loop(e, 1);
			check(e, &e->light->lightdir, &e->c.inter, 2);
			check_dist(e, 2);
			checklight(e->light, &e->light->lightdir, &e->c.inter);
		 	// printf("sph : [%f] | pla : [%f]\n", e->c.distsph, e->c.distpla);
			if (e->c.dist > e->light->t && e->c.dist > 0.00001 && e->light->t > 0.00001)
			{
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

void		aff(t_stuff *e)
{
	int i;
	int j;
	double color;

	i = 0;
	j = 0;
	e->c.posy = -1;
	while (++e->c.posy < LENGTH)
	{
		e->c.posx = -1;
		while (++e->c.posx < WIDTH)
		{
			reboot_list_loop(e, 3);
			raydir(e, e->c.posx, e->c.posy);
			raythingy(e);
			color = rgbtohexa(e->c.colorf.r, e->c.colorf.g, e->c.colorf.b);
			if (e->pix > 0)
			{
				j = -1;
				while (++j <= e->pix)
				{
					i = -1;
					while (++i <= e->pix)
						mlx_pixel_put_to_image(e->img, e->c.posx + i, e->c.posy + j, color);
				}
				e->c.posx += e->pix;
			}
			else
			{
				mlx_pixel_put_to_image(e->img, e->c.posx + i, e->c.posy + j, color);
			}
		}
		if (e->pix > 0)
			e->c.posy += e->pix;
	}
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->img.img_ptr, 0, 0);
	reboot_list_loop(e, 3);
}

void		check(t_stuff *e, t_vec *raydir, t_vec *pos, int option)
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

void		check_dist(t_stuff *e, int option)
{
	if (e->c.distsph < e->c.dist && e->c.distsph > 0.00001)
	{
		e->c.obj = (e->c.distsph < e->c.dist ? SPHERE : -1);
		e->c.dist = e->c.distsph;
		if (option == 1)
		{
			e->d.color.r = e->d.colsph.r;
			e->d.color.g = e->d.colsph.g;
			e->d.color.g = e->d.colsph.b;
		}
	}
	if (e->c.distpla < e->c.dist && e->c.distpla > 0.00001)
	{
		e->c.obj = (e->c.distpla < e->c.dist ? PLAN : e->c.obj);
		e->c.dist = e->c.distpla;
		if (option == 1)
		{
			e->d.color.r = e->d.colpla.r;
			e->d.color.g = e->d.colpla.g;
			e->d.color.b = e->d.colpla.b;
		}
	}
	if (e->c.distcyl < e->c.dist && e->c.distcyl > 0.00001)
	{
		e->c.obj = (e->c.distcyl < e->c.dist ? CYLINDRE : e->c.obj);
		e->c.dist = e->c.distcyl;
		if (option == 1)
		{
			e->d.color.r = e->d.colcyl.r;
			e->d.color.g = e->d.colcyl.g;
			e->d.color.b = e->d.colcyl.b;
		}
	}
	if (e->c.distcone < e->c.dist && e->c.distcone > 0.00001)
	{
		e->c.obj = (e->c.distcone < e->c.dist ? CONE : e->c.obj);
		e->c.dist = e->c.distcone;
		if (option == 1)
		{
			e->d.color.r = e->d.colcone.r;
			e->d.color.g = e->d.colcone.g;
			e->d.color.g = e->d.colcone.b;
		}
	}
	if (e->c.distlight < e->c.dist && e->c.distlight > 0.00001 && option == 1)
	{
		e->c.obj = (e->c.distlight < e->c.dist ? LIGHT : e->c.obj);
		e->c.dist = e->c.distlight;
	}
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
