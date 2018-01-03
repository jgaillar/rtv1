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

double		getlight(t_vec *norm, t_light **light, t_rgb *colorobj)
{
	t_rgb	rgb;
	double	angle;
	double	color;

	angle = ((*light)->ray > 0.00001 ? (dot_product(norm, &(*light)->lightdir)) \
	 		* (*light)->ray : (dot_product(norm, &(*light)->lightdir)));
	if ((*light)->ray > 0.00001 && angle > 0.00001)
	{
		rgb.r = colorobj->r * (*light)->amb;
		rgb.g = colorobj->g * (*light)->amb;
		rgb.b = colorobj->b * (*light)->amb;
		rgb.r += (*light)->color.r * angle * (*light)->diff;
		rgb.g += (*light)->color.g * angle * (*light)->diff;
		rgb.b += (*light)->color.b * angle * (*light)->diff;
		color = rgbtohexa(rgb.r, rgb.g, rgb.b);
		return (color);
	}
	color = rgbtohexa(colorobj->r * (*light)->amb, colorobj->g * (*light)->amb, colorobj->b * (*light)->amb);
	return (color);
}

int		raythingy(t_stuff *e)
{
	check(e, &e->raydir, &e->poscam, 9999);
	check_dist(e, 9999);
	e->c.colorf = 0;
	if (e->c.obj > -1)
	{
		reboot_list_loop(e);
		getintersection(e, e->c.dist);
		e->c.colorf += shadows(e, &e->c.inter, &e->light->lightdir, e->c.color);
		if (e->c.colorf > 0.00001)
			return (0);
		else if (e->c.obj == SPHERE)
		{
			searchlist(e, e->c.objsph, e->c.obj);
			vecsous(&e->sph->norm, &e->c.inter, &e->sph->pos);
			vecnorm(&e->sph->norm);
			e->c.colorf += getlight(&e->sph->norm, &e->light, &e->sph->color);
		}
		else if (e->c.obj == PLAN)
		{
			searchlist(e, e->c.objpla, e->c.obj);
			e->c.colorf += getlight(&e->pla->norm, &e->light, &e->pla->color);
		}
		else if (e->c.obj == CYLINDRE)
		{
			searchlist(e, e->c.objcyl, e->c.obj);
			vecsous(&e->cyl->norml, &e->c.inter, &e->cyl->pos);
			vecnorm(&e->cyl->norml);
			e->c.colorf += getlight(&e->cyl->norml, &e->light, &e->cyl->color);
		}
		else if (e->c.obj == CONE)
		{
			searchlist(e, e->c.objcone, e->c.obj);
			vecsous(&e->cone->norml, &e->cone->pos, &e->c.inter);
			vecnorm(&e->cone->norml);
			e->c.colorf += getlight(&e->cone->norml, &e->light, &e->cone->color);
		}
		else if (e->c.obj == LIGHT)
		{
			searchlist(e, e->c.objlight, e->c.obj);
			vecsous(&e->light->norm, &e->c.inter, &e->light->pos);
			vecnorm(&e->light->norm);;
			e->c.colorf += rgbtohexa(e->light->color.r * e->light->diff,\
				 e->light->color.g * e->light->diff, \
				 	e->light->color.b * e->light->diff);
		}
	}
	return (-1);
}

void		aff(t_stuff *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	e->c.posy = -1;
	while (++e->c.posy < LENGTH)
	{
		e->c.posx = -1;
		while (++e->c.posx < WIDTH)
		{
			reboot_list_loop(e);
			raydir(e);
			raythingy(e);
			//printf("color : [%f]\n", e->c.colorf);
			if (e->pix > 0)
			{
				j = -1;
				while (++j <= e->pix)
				{
					i = -1;
					while (++i <= e->pix)
						mlx_pixel_put_to_image(e->img, e->c.posx + i, e->c.posy + j, e->c.colorf);
				}
				e->c.posx += e->pix;
			}
			else
			{
				mlx_pixel_put_to_image(e->img, e->c.posx + i, e->c.posy + j, e->c.colorf);
			}
		}
		if (e->pix > 0)
			e->c.posy += e->pix;
	}
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->img.img_ptr, 0, 0);
	reboot_list_loop(e);
}

void		check(t_stuff *e, t_vec *raydir, t_vec *pos, double dist)
{
	//printf("dist : [%f]\n", dist);
	e->c.dist = dist;
	e->c.distsph = 9999;
	e->c.distpla = 9999;
	e->c.distcyl = 9999;
	e->c.distcone = 9999;
	e->c.distlight = 9999;
	if (dist == 9999)
		e->c.obj = -1;
	while (e->sph)
	{
		checksphere(e->sph, raydir, pos);
		if (e->sph->t < e->c.distsph && e->sph->t > 0.00001)
		{
			e->c.distsph = e->sph->t;
			if (dist == 9999)
			{
				e->c.objsph = e->sph->nm;
				e->c.obj = SPHERE;
				e->c.colsph.r = e->sph->color.r;
				e->c.colsph.g = e->sph->color.g;
				e->c.colsph.b = e->sph->color.b;
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
			if (dist == 9999)
			{
				e->c.objpla = e->pla->nm;
				e->c.obj = PLAN;
				e->c.colpla.r = e->pla->color.r;
				e->c.colpla.g = e->pla->color.g;
				e->c.colpla.b = e->pla->color.b;
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
			if (dist == 9999)
			{
				e->c.objcyl = e->cyl->nm;
				e->c.obj = CYLINDRE;
				e->c.colcyl.r = e->cyl->color.r;
				e->c.colcyl.g = e->cyl->color.g;
				e->c.colcyl.b = e->cyl->color.b;
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
			if (dist == 9999)
			{
				e->c.objcone = e->cone->nm;
				e->c.obj = CONE;
				e->c.colcone.r = e->cone->color.r;
				e->c.colcone.g = e->cone->color.g;
				e->c.colcone.b = e->cone->color.b;
			}
		}
		e->cone = e->cone->next;
	}
	while (e->light && dist == 9999)
	{
		checklight(e->light, raydir, pos);
		if (e->light->t < e->c.distlight && e->light->t > 0.00001)
		{
			e->c.distlight = e->light->t;
			if (dist == 9999)
			{
				e->c.objlight = e->light->nm;
				e->c.obj = LIGHT;
			}
		}
		e->light = e->light->next;
	}
}

void		check_dist(t_stuff *e, double dist)
{
	if (e->c.distsph < e->c.dist && e->c.distsph > 0.00001)
	{
		e->c.obj = (e->c.distsph < e->c.dist ? SPHERE : -1);
		e->c.dist = e->c.distsph;
		if (dist == 9999)
		{
			e->c.color.r = e->c.colsph.r;
			e->c.color.g = e->c.colsph.g;
			e->c.color.b = e->c.colsph.b;
		}
	}
	if (e->c.distpla < e->c.dist && e->c.distpla > 0.00001)
	{
		e->c.obj = (e->c.distpla < e->c.dist ? PLAN : e->c.obj);
		e->c.dist = e->c.distpla;
		if (dist == 9999)
		{
			e->c.color.r = e->c.colpla.r;
			e->c.color.g = e->c.colpla.g;
			e->c.color.b = e->c.colpla.b;
		}
	}
	if (e->c.distcyl < e->c.dist && e->c.distcyl > 0.00001)
	{
		e->c.obj = (e->c.distcyl < e->c.dist ? CYLINDRE : e->c.obj);
		e->c.dist = e->c.distcyl;
		if (dist == 9999)
		{
			e->c.color.r = e->c.colcyl.r;
			e->c.color.g = e->c.colcyl.g;
			e->c.color.b = e->c.colcyl.b;
		}
	}
	if (e->c.distcone < e->c.dist && e->c.distcone > 0.00001)
	{
		e->c.obj = (e->c.distcone < e->c.dist ? CONE : e->c.obj);
		e->c.dist = e->c.distcone;
		if (dist == 9999)
		{
			e->c.color.r = e->c.colcone.r;
			e->c.color.g = e->c.colcone.g;
			e->c.color.b = e->c.colcone.b;
		}
	}
	if (e->c.distlight < e->c.dist && e->c.distlight > 0.00001 && dist == 9999)
	{
		e->c.obj = (e->c.distlight < e->c.dist ? LIGHT : e->c.obj);
		e->c.dist = e->c.distlight;
	}
}

void	searchlist(t_stuff *e, int nmail, int nlist)
{
	reboot_list_loop(e);
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
