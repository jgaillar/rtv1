/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:09:06 by jgaillar          #+#    #+#             */
/*   Updated: 2017/11/22 16:56:22 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		getlight(t_vec *norm, t_rt *rt, t_light *light, t_rgb *colorobj)
{
	t_rgb	rgb;
	double	angle;
	double	color;

	angle = dot_product(norm, &light->lightdir);
//	printf("angle : [%f]\n", angle);
	if (angle > 0)
	{
		rgb.r = colorobj->r * light->diff;
		rgb.g = colorobj->g * light->diff;
		rgb.b = colorobj->b * light->diff;
		if (rgb.r + (light->color.r * angle * 0.25) >= 255)
			rgb.r = 255;
		else if (rgb.r + (light->color.r * angle * 0.25) <= 0)
			rgb.r = 0;
		else
			rgb.r += light->color.r * angle * 0.25;
		if (rgb.g + (light->color.g * angle * 0.25) >= 255)
			rgb.g = 255;
		else if (rgb.g + (light->color.g * angle * 0.25) <= 0)
			rgb.g = 0;
		else
			rgb.g += light->color.g * angle * 0.25;
		if (rgb.b + (light->color.b * angle * 0.25) >= 255)
			rgb.b = 255;
		else if (rgb.b + (light->color.b * angle * 0.25) <= 0)
			rgb.b = 0;
		else
			rgb.b += light->color.b * angle * 0.25;
		color = rgbtohexa(rgb.r, rgb.g, rgb.b);
		return (color);
	}
	color = rgbtohexa(colorobj->r * light->amb, colorobj->g * light->amb, colorobj->b * light->amb);
	return (color);
}

void		raythingy(t_stuff *e, double x, double y)
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
	else if (e->rt.obj != 0)
	{
		getintersection(&e->poscam, &e->raydir, e->rt.dist, &e->rt);
		vecsous(&e->light.lightdir, &e->light.posl, &e->rt.inter);
		vecnorm(&e->light.lightdir);
		if (e->rt.obj == 1)
		{
			vecsous(&e->sphere.normsphere, &e->rt.inter, &e->sphere.poss);
			vecnorm(&e->sphere.normsphere);
			e->rt.colorf = getlight(&e->sphere.normsphere, &e->rt, &e->light, &e->sphere.color);
			mlx_pixel_put_to_image(e->img, x, y, e->rt.colorf);
		}
		else if (e->rt.obj == 2)
		{
			checksphere(&e->sphere, &e->light.lightdir, &e->rt.inter);
			checkplan(&e->plan, &e->light.lightdir, &e->rt.inter);
			if (e->sphere.t > e->plan.t)
			{
		//		printf("st : [%f] | pt : [%f]\n", e->sphere.t, e->plan.t);
				//ft_putendl("oklm");
				mlx_pixel_put_to_image(e->img, x, y, rgbtohexa(e->plan.color.r * e->light.amb, e->plan.color.g * e->light.amb, e->plan.color.b * e->light.amb));
			}
			else
			{
				e->rt.colorf = getlight(&e->plan.normp, &e->rt, &e->light, &e->plan.color);
				mlx_pixel_put_to_image(e->img, x, y, e->rt.colorf);
			}
		}
	}
}

void		aff(t_stuff *e)
{
	double		x;
	double		y;
	int 		i;

	y = -1;
	while (++y < LENGTH)
	{
		x = -1;
		while (++x < WIDTH)
		{
			i = -1;
			while (++i < 1)
				raythingy(e, x, y);
		}
	}
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->img.img_ptr, 0, 0);
}

void		raydir(t_stuff *e, double x, double y)
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
	((poscam->z - sphere->poss.z) * (poscam->z - sphere->poss.z))) - \
	(sphere->rayon * sphere->rayon);
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
