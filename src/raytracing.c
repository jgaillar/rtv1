/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:09:06 by jgaillar          #+#    #+#             */
/*   Updated: 2017/11/28 17:12:22 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		getlight(t_vec *norm, t_rt *rt, t_light *light, t_rgb *colorobj)
{
	t_rgb	rgb;
	double	angle;
	double	color;

	angle = (light->ray > 0.00001 ? (dot_product(norm, &light->lightdir)) \
	 		* light->ray : (dot_product(norm, &light->lightdir)));
	if (light->ray > 0.00001 && angle > 0)
	{
		rgb.r = colorobj->r * light->amb;
		rgb.g = colorobj->g * light->amb;
		rgb.b = colorobj->b * light->amb;
		rgb.r += light->color.r * angle * light->diff;
		rgb.g += light->color.g * angle * light->diff;
		rgb.b += light->color.b * angle * light->diff;
		color = rgbtohexa(rgb.r, rgb.g, rgb.b);
		return (color);
	}
	color = rgbtohexa(colorobj->r * light->amb, colorobj->g * light->amb, colorobj->b * light->amb);
	return (color);
}

void		raythingy(t_stuff *e)
{
	e->rt.dist = 9999;
	e->rt.obj = 0;
	raydir(e);
	checksphere(&e->sphere, &e->raydir, &e->poscam);
	if (e->sphere.t < e->rt.dist && e->sphere.t > 0.00001)
	{
		e->rt.dist = e->sphere.t;
		e->rt.obj = 1;
	}
	checkcone(&e->con, &e->raydir, &e->poscam);
	if (e->con.t < e->rt.dist && e->con.t > 0.00001)
	{
		e->rt.dist = e->con.t;
		e->rt.obj = 5;
	}
	checklight(&e->light, &e->raydir, &e->poscam);
	if (e->light.t < e->rt.dist && e->light.t > 0.00001)
	{
		e->rt.dist = e->light.t;
		e->rt.obj = 3;
	}
	checkcyl(&e->cyl, &e->raydir, &e->poscam);
	if (e->cyl.t < e->rt.dist && e->cyl.t > 0.00001)
	{
		e->rt.dist = e->cyl.t;
		e->rt.obj = 4;
	}
	checkplan(&e->plan, &e->raydir, &e->poscam);
	if (e->plan.t < e->rt.dist && e->plan.t > 0.00001)
	{
		e->rt.dist = e->plan.t;
		e->rt.obj = 2;
	}
	if (e->rt.obj == 0)
		mlx_pixel_put_to_image(e->img, e->c.posx, e->c.posy, 0x000000);
	else if (e->rt.obj != 0)
	{
		getintersection(&e->poscam, &e->raydir, e->rt.dist, &e->rt);
		vecsous(&e->light.lightdir, &e->light.pos, &e->rt.inter);
		vecnorm(&e->light.lightdir);
		if (e->rt.obj == 1)
		{
			vecsous(&e->sphere.norm, &e->rt.inter, &e->sphere.pos);
			vecnorm(&e->sphere.norm);
			e->rt.colorf = getlight(&e->sphere.norm, &e->rt, &e->light, &e->sphere.color);
			mlx_pixel_put_to_image(e->img, e->c.posx, e->c.posy, e->rt.colorf);
		}
		else if (e->rt.obj == 2)
		{
			checksphere(&e->sphere, &e->light.lightdir, &e->rt.inter);
			checklight(&e->light, &e->light.lightdir, &e->rt.inter);
			if (e->light.ray > 0.00001 && e->sphere.t <= e->light.t && e->sphere.t > 0.00001)
				mlx_pixel_put_to_image(e->img, e->c.posx, e->c.posy, rgbtohexa(e->plan.color.r * e->light.amb, e->plan.color.g * e->light.amb, e->plan.color.b * e->light.amb));
			else
			{
				e->rt.colorf = getlight(&e->plan.norm, &e->rt, &e->light, &e->plan.color);
				mlx_pixel_put_to_image(e->img, e->c.posx, e->c.posy, e->rt.colorf);
			}
		}
		else if (e->rt.obj == 3)
		{
			vecsous(&e->light.norm, &e->rt.inter, &e->light.pos);
			vecnorm(&e->light.norm);
			mlx_pixel_put_to_image(e->img, e->c.posx, e->c.posy, rgbtohexa(e->light.color.r, e->light.color.g, e->light.color.b));
		}
		else if (e->rt.obj == 4)
		{
			vecsous(&e->cyl.norm, &e->rt.inter, &e->cyl.pos);
			vecnorm(&e->cyl.norm);
			e->rt.colorf = getlight(&e->cyl.norm, &e->rt, &e->light, &e->cyl.color);
			mlx_pixel_put_to_image(e->img, e->c.posx, e->c.posy, e->rt.colorf);
		}
		else if (e->rt.obj == 5)
		{
			vecsous(&e->con.norm, &e->rt.inter, &e->con.pos);
			vecnorm(&e->con.norm);
			e->rt.colorf = getlight(&e->con.norm, &e->rt, &e->light, &e->con.color);
			mlx_pixel_put_to_image(e->img, e->c.posx, e->c.posy, e->rt.colorf);
		}
	}
}

void		aff(t_stuff *e)
{
	int 		i;

	e->c.posy = -1;
	while (++e->c.posy < LENGTH)
	{
		e->c.posx = -1;
		while (++e->c.posx < WIDTH)
		{
			i = -1;
			while (++i < 1)
				raythingy(e);
		}
	}
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->img.img_ptr, 0, 0);
}

void		raydir(t_stuff *e)
{
	t_vec	tmp;
	t_vec	tmp2;

	e->rt.xindent = e->c.largvue / WIDTH * e->c.posx;
	e->rt.yindent = e->c.longvue / LENGTH * e->c.posy;
	tmp.x = e->vecdroit.x * e->rt.xindent;
	tmp.y = e->vecdroit.y * e->rt.xindent;
	tmp.z = e->vecdroit.z * e->rt.xindent;
	tmp2.x = e->vech.x * e->rt.yindent;
	tmp2.y = e->vech.y * e->rt.yindent;
	tmp2.z = e->vech.z * e->rt.yindent;
	vecadd(&e->raydir, &e->vecupleft, &tmp);
	vecsous(&e->raydir, &e->raydir, &tmp2);
	vecnorm(&e->raydir);
}

void		checksphere(t_sphere *sphere, t_vec *raydir, t_vec *poscam)
{
	double	a;
	double	b;
	double	c;

	a = (raydir->x * raydir->x) + (raydir->y * raydir->y) + (raydir->z * \
		raydir->z);
	b = 2 * (raydir->x * (poscam->x - sphere->pos.x) + raydir->y * \
	(poscam->y - sphere->pos.y) + raydir->z * (poscam->z - sphere->pos.z));
	c = (((poscam->x - sphere->pos.x) * (poscam->x - sphere->pos.x)) + \
	((poscam->y - sphere->pos.y) * (poscam->y - sphere->pos.y)) + \
	((poscam->z - sphere->pos.z) * (poscam->z - sphere->pos.z))) - \
	(sphere->ray * sphere->ray);
	sphere->det = (b * b) - 4 * a * c;
	if (sphere->det < 0)
		sphere->t = -1;
	else if (sphere->det == 0)
		sphere->t = (-b + sqrt(sphere->det)) / (2 * a);
	else if (sphere->det > 0)
	{
		sphere->t1 = ((b * -1) + sqrt(sphere->det)) / (2 * a);
		sphere->t2 = ((b * -1) - sqrt(sphere->det)) / (2 * a);
		sphere->t = (sphere->t1 <= sphere->t2 ? sphere->t1 : sphere->t2);
	}
}

void		checklight(t_light *light, t_vec *raydir, t_vec *poscam)
{
	double	a;
	double	b;
	double	c;

	a = (raydir->x * raydir->x) + (raydir->y * raydir->y) + (raydir->z * \
		raydir->z);
	b = 2 * (raydir->x * (poscam->x - light->pos.x) + raydir->y * \
	(poscam->y - light->pos.y) + raydir->z * (poscam->z - light->pos.z));
	c = (((poscam->x - light->pos.x) * (poscam->x - light->pos.x)) + \
	((poscam->y - light->pos.y) * (poscam->y - light->pos.y)) + \
	((poscam->z - light->pos.z) * (poscam->z - light->pos.z))) - \
	(light->ray * light->ray);
	light->det = (b * b) - 4 * a * c;
	if (light->det < 0)
		light->t = -1;
	else if (light->det == 0)
		light->t = (-b + sqrt(light->det)) / (2 * a);
	else if (light->det > 0)
	{
		light->t1 = ((b * -1) + sqrt(light->det)) / (2 * a);
		light->t2 = ((b * -1) - sqrt(light->det)) / (2 * a);
		light->t = (light->t1 <= light->t2 ? light->t1 : light->t2);
	}
}

void		checkplan(t_plan *plan, t_vec *raydir, t_vec *poscam)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = poscam->x - plan->pos.x;
	b = poscam->y - plan->pos.y;
	c = poscam->z - plan->pos.z;
	d = plan->pos.x + plan->pos.y + plan->pos.z;

	plan->t = -((plan->norm.x * a + plan->norm.y * b + plan->norm.z * c + d) \
	/ (plan->norm.x * raydir->x + plan->norm.y * \
		raydir->y + plan->norm.z * raydir->z));
}

void		checkcyl(t_cyl *cyl, t_vec *raydir, t_vec *poscam)
{
	double a;
	double b;
	double c;

	a = ((raydir->x) * (raydir->x) + \
	(raydir->y) * (raydir->y));
	b = 2 * (raydir->x * (poscam->x - cyl->pos.x) + \
	raydir->y * (poscam->y - cyl->pos.y));
	c = (((poscam->x - cyl->pos.x) * (poscam->x - cyl->pos.x)) + \
	((poscam->y - cyl->pos.y) * (poscam->y - cyl->pos.y)) - ((cyl->ray) \
	* (cyl->ray)));
	cyl->det = (b * b) - 4 * a * c;
	cyl->t1 = (-b - sqrt(cyl->det)) / (2 * a);
	cyl->t2 = (-b + sqrt(cyl->det)) / (2 * a);
	cyl->t = (cyl->t1 <= cyl->t2 ? cyl->t1 : cyl->t2);
	//printf("det : [%f] | t1 : [%f] | t2 : [%f]\n", cyl->det, cyl->t1, cyl->t2);
}

void		checkcone(t_con *con, t_vec *raydir, t_vec *poscam)
{
	double	new_z;
	double	a;
	double	b;
	double	c;

	new_z = 0.7 * raydir->z;
	a = (raydir->x * raydir->x) + (raydir->y * raydir->y) - (new_z * new_z);
	b = 2 * (raydir->x * (poscam->x - con->pos.x) + \
	raydir->y * (poscam->y - con->pos.y) - raydir->z * new_z);
	c = ((poscam->x - con->pos.x) * (poscam->x - con->pos.x)) + ((poscam->y - con->pos.y) * (poscam->y - con->pos.y)) - ((poscam->z - con->pos.z) * (poscam->z - con->pos.z));
	con->det = b * b - 4 * a * c;
	con->t1 = -b - sqrt(con->det) / (2 * a);
	con->t2 = -b + sqrt(con->det) / (2 * a);
	con->t = (con->t2 > con->t1 ? con->t1 : con->t2);
}
