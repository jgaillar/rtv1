/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:09:06 by jgaillar          #+#    #+#             */
/*   Updated: 2017/11/10 18:02:03 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		getlight(t_vec *norm, t_vec *inter, t_light *light, t_rgb *colorobj)
{
	t_vec	lightdir;
	t_rgb	rgb;
	double	angle;
	double	color;
	double 	val;

	val = 180 / M_PI;
	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	angle = 0;
	lightdir = getvec(inter, &light->posl);
	vecnorm(&lightdir);
	angle = dot_product(norm, &lightdir) * val;
	if (angle > 0)
	{
	// rgb.r += (colorobj->r * 200) * light->coefdif;
	// rgb.g += (colorobj->g * 1) * light->coefdif;
	// rgb.b += (colorobj->b * 1) * light->coefdif;
		if (rgb.r += light->color.r * angle * light->coefdif >= 255)
			rgb.r = 255;
		else if (rgb.r += light->color.r * angle * light->coefdif <= 0)
			rgb.r = 0;
		else
			rgb.r += light->color.r * angle * light->coefdif;
		if (rgb.g += light->color.g * angle * light->coefdif >= 255)
			rgb.g = 255;
		else if (rgb.g += light->color.g * angle * light->coefdif <= 0)
			rgb.g = 0;
		else
			rgb.g += light->color.g * angle * light->coefdif;
		if (rgb.b += light->color.b * angle * light->coefdif >= 255)
			rgb.b = 255;
		else if (rgb.b += light->color.b * angle * light->coefdif <= 0)
			rgb.b = 0;
		else
			rgb.b += light->color.b * angle * light->coefdif;
	}
	color = rgbtohexa(rgb.r, rgb.g, rgb.b);
	return (color);
}

void		getintersection(t_vec *poscam, t_vec *raydir, double dist, t_rt *rt)
{
	rt->inter.x = poscam->x + raydir->x * dist;
	rt->inter.y = poscam->y + raydir->y * dist;
	rt->inter.z = poscam->z + raydir->z * dist;
}

void		raythingy(t_stuff *e, int x, int y)
{
	e->rt.dist = 9999;
	e->rt.obj = 0;
	raydir(e, x, y);
	checksphere(&e->sphere, &e->raydir, &e->poscam);
	if (e->sphere.t < e->rt.dist && e->sphere.t > 0)
	{
		e->rt.dist = e->sphere.t;
		e->rt.obj = 1;
	}
	checkplan(&e->plan, &e->raydir, &e->poscam);
	if (e->plan.t < e->rt.dist && e->plan.t > 0)
	{
		e->rt.dist = e->plan.t;
		e->rt.obj = 2;
	}
	if (e->rt.obj == 0)
		mlx_pixel_put_to_image(e->img, x, y, 0x000000);
	if (e->rt.obj != 0)
	{
		getintersection(&e->poscam, &e->raydir, e->rt.dist, &e->rt);
		if (e->rt.obj == 1)
		{
			e->sphere.normsphere = getvec(&e->sphere.poss, &e->rt.inter);
			vecnorm(&e->sphere.normsphere);
			mlx_pixel_put_to_image(e->img, x, y, getlight(&e->sphere.normsphere, &e->rt.inter, &e->light, &e->sphere.color));
		}
		else if (e->rt.obj == 2)
			mlx_pixel_put_to_image(e->img, x, y, getlight(&e->plan.normp, &e->rt.inter, &e->light, &e->plan.color));
	}
}

void		aff(t_stuff *e)
{
	int		x;
	int		y;
	int i;

	y = -1;
	while (++y < LENGTH)
	{
		x = -1;
		while (++x < WIDTH)
		{
			i = -1;
			while (++i < 4)
				raythingy(e, x, y);
		}
		mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->img.img_ptr, 0, 0);
	}

}

void		raydir(t_stuff *e, int x, int y)
{
	t_vec	tmp;
	t_vec	tmp2;

	e->rt.xindent = e->largvue / WIDTH * x;
	e->rt.yindent = e->longvue / LENGTH * y;
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
	b = 2 * (raydir->x * (poscam->x - sphere->poss.x) + raydir->y * \
	(poscam->y - sphere->poss.y) + raydir->z * (poscam->z - sphere->poss.z));
	c = (((poscam->x - sphere->poss.x) * (poscam->x - sphere->poss.x)) + \
	((poscam->y - sphere->poss.y) * (poscam->y - sphere->poss.y)) + \
	((poscam->z = sphere->poss.z) * (poscam->z = sphere->poss.z)) - \
	(sphere->rayon * sphere->rayon));
	sphere->det = (b * b) - 4 * a * c;
	if (sphere->det < 0)
		sphere->t = -1;
	else if (sphere->det == 0)
		sphere->t = (-b + sqrt(sphere->det)) / (2 * a);
	else if (sphere->det > 0)
	{
		sphere->t1 = (-b + sqrt(sphere->det)) / (2 * a);
		sphere->t2 = (-b - sqrt(sphere->det)) / (2 * a);
		sphere->t = (sphere->t1 < sphere->t2 ? sphere->t1 : sphere->t2);
	}

}

void		checkplan(t_plan *plan, t_vec *raydir, t_vec *poscam)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = poscam->x - plan->plan.x;
	b = poscam->y - plan->plan.y;
	c = poscam->z - plan->plan.z;
	d = plan->plan.x + plan->plan.y + plan->plan.z;

	plan->t = -(plan->normp.x * a + plan->normp.y * b + plan->normp.z * c + d) \
	/ (plan->normp.x * raydir->x + plan->normp.y * \
		raydir->y + plan->normp.z * raydir->z);
}
