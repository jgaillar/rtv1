/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:09:06 by jgaillar          #+#    #+#             */
/*   Updated: 2017/12/04 16:46:10 by jgaillar         ###   ########.fr       */
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
	if ((*light)->ray > 0.00001 && angle > 0)
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

void		raythingy(t_stuff *e)
{
	check(e);
	check_dist(e);
	e->c.colorf = 0;
	if (e->c.obj > -1)
	{
		getintersection(e, e->c.dist);
		if (e->c.obj == 0)
		{
			searchlist(e, e->c.objsph, e->c.obj);
			vecsous(&e->sph->norm, &e->c.inter, &e->sph->pos);
			vecnorm(&e->sph->norm);
			e->c.colorf = getlight(&e->sph->norm, &e->light, &e->sph->color);
		}
		if (e->c.obj == 1)
		{
			searchlist(e, e->c.objpla, e->c.obj);
			e->c.colorf = getlight(&e->pla->norm, &e->light, &e->pla->color);
		}
		if (e->c.obj == 2)
		{
			searchlist(e, e->c.objcyl, e->c.obj);
			vecsous(&e->cyl->norml, &e->c.inter, &e->cyl->pos);
			vecnorm(&e->cyl->norml);
			e->c.colorf = getlight(&e->cyl->norml, &e->light, &e->cyl->color);
		}
		if (e->c.obj == 3)
		{
			searchlist(e, e->c.objcone, e->c.obj);
			vecsous(&e->cone->norm, &e->c.inter, &e->cone->pos);
			vecnorm(&e->cone->norm);
			e->c.colorf = getlight(&e->cone->norm, &e->light, &e->cone->color);
		}
		if (e->c.obj == 4)
		{
			searchlist(e, e->c.objlight, e->c.obj);
			e->c.colorf = 0xFFFFFF;
		}
	}
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
			mlx_pixel_put_to_image(e->img, e->c.posx + i, e->c.posy + j, e->c.colorf);
		}
		if (e->pix > 0)
			e->c.posy += e->pix;
	}
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->img.img_ptr, 0, 0);
	reboot_list_loop(e);
}

void		check(t_stuff *e)
{
	e->c.dist = 9999;
	e->c.distsph = 9999;
	e->c.distpla = 9999;
	e->c.distcyl = 9999;
	e->c.distcone = 9999;
	e->c.distlight = 9999;
	e->c.obj = -1;
	while (e->sph)
	{
		checksphere(e->sph, &e->raydir, &e->poscam);
		if (e->sph->t < e->c.distsph && e->sph->t > 0.00001)
		{
			e->c.distsph = e->sph->t;
			e->c.objsph = e->sph->nm;
			e->c.obj = 0;
		}
		e->sph = e->sph->next;
	}
	while (e->pla)
	{
		checkplan(e->pla, &e->raydir, &e->poscam);
		if (e->pla->t < e->c.distpla && e->pla->t > 0.00001)
		{
			e->c.distpla = e->pla->t;
			e->c.objpla = e->pla->nm;
			e->c.obj = 1;
		}
		e->pla = e->pla->next;
	}
	while (e->cyl)
	{
		checkcyl(e->cyl, &e->raydir, &e->poscam);
		if (e->cyl->t < e->c.distcyl && e->cyl->t > 0.00001)
		{
			e->c.distcyl = e->cyl->t;
			e->c.objcyl = e->cyl->nm;
			e->c.obj = 2;
		}
		e->cyl = e->cyl->next;
	}
	while (e->cone)
	{
		checkcone(e->cone, &e->raydir, &e->poscam);
		if (e->cone->t < e->c.distcone && e->cone->t > 0.00001)
		{
			e->c.distcone = e->cone->t;
			e->c.objcone = e->cone->nm;
			e->c.obj = 3;
		}
		e->cone = e->cone->next;
	}
	while (e->light)
	{
		checklight(e->light, &e->raydir, &e->poscam);
		if (e->light->t < e->c.distlight && e->light->t > 0.00001)
		{
			e->c.distlight = e->light->t;
			e->c.objlight = e->light->nm;
			e->c.obj = 4;
		}
		e->light = e->light->next;
	}
}

void		check_dist(t_stuff *e)
{
	if (e->c.distsph < e->c.dist && e->c.distsph > 0.00001)
	{
		e->c.obj = (e->c.distsph < e->c.dist ? 0 : -1);
		e->c.dist = e->c.distsph;
	}
	if (e->c.distpla < e->c.dist && e->c.distpla > 0.00001)
	{
		e->c.obj = (e->c.distpla < e->c.dist ? 1 : e->c.obj);
		e->c.dist = e->c.distpla;
	}
	if (e->c.distcyl < e->c.dist && e->c.distcyl > 0.00001)
	{
		e->c.obj = (e->c.distcyl < e->c.dist ? 2 : e->c.obj);
		e->c.dist = e->c.distcyl;
	}
	if (e->c.distcone < e->c.dist && e->c.distcone > 0.00001)
	{
		e->c.obj = (e->c.distcone < e->c.dist ? 3 : e->c.obj);
		e->c.dist = e->c.distcone;
	}
	if (e->c.distlight < e->c.dist && e->c.distlight > 0.00001)
	{
		e->c.obj = (e->c.distcone < e->c.dist ? 4 : e->c.obj);
		e->c.dist = e->c.distlight;
	}
}

void	searchlist(t_stuff *e, int nmail, int nlist)
{
	reboot_list_loop(e);
	if (nlist == 0)
	{
		while (e->sph->nm != nmail)
			e->sph = e->sph->next;
	}
	if (nlist == 1)
	{
		while (e->pla->nm != nmail)
		e->pla = e->pla->next;
	}
	if (nlist == 2)
	{
		while (e->cyl->nm != nmail)
			e->cyl = e->cyl->next;
	}
	if (nlist == 3)
	{
		while (e->cone->nm != nmail)
			e->cone = e->cone->next;
	}
	if (nlist == 4)
	{
		while (e->light->nm != nmail)
			e->light = e->light->next;
	}
}
