/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:09:06 by jgaillar          #+#    #+#             */
/*   Updated: 2017/10/04 11:09:07 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		getlight(t_vec *norm, t_vec *inter, t_light *light, double colorobj)
{
	t_vec	lightdir;
	double	angle;
	double color;

	color = 0x000000;
	lightdir = getvec(inter, &light->posl);
	vecnorm(&lightdir);
	angle = acos(dot_product(norm, &lightdir));
	if (angle > 0)
		color = (colorobj * light->color * angle) / 1000000;
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
	double color;

	e->rt.dist = 9999;
	e->rt.obj = 0;
	raydir(e, x, y);
	checksphere(&e->sphere, &e->raydir, &e->poscam);
	if (e->sphere.t < e->rt.dist && e->sphere.t > 0)
	{
		e->rt.dist = e->sphere.t;
		e->rt.obj = 1;
	}
	// checkplan(&e->plan, &e->raydir, &e->poscam);
	// if (e->plan.t < e->rt.dist && e->plan.t > 0)
	// {
	// 	e->rt.dist = e->plan.t;
	// 	e->rt.obj = 2;
	// }
	if (e->rt.obj == 0)
		mlx_pixel_put_to_image(e->img, x, y, 0x000000);
	if (e->rt.obj != 0)
	{
		getintersection(&e->poscam, &e->raydir, e->rt.dist, &e->rt);
		if (e->rt.obj == 1)
		{
			e->sphere.normsphere = getvec(&e->sphere.poss, &e->rt.inter);
			vecnorm(&e->sphere.normsphere);
			color = getlight(&e->sphere.normsphere, &e->rt.inter, &e->light, e->sphere.color);
			printf("color : [%f]\n", color);
			mlx_pixel_put_to_image(e->img, x, y, color);
		}
		else if (e->rt.obj == 2)
		{
			color = getlight(&e->plan.normp, &e->rt.inter, &e->light, e->plan.color);
			printf("color : [%f]\n", color);
			mlx_pixel_put_to_image(e->img, x, y, color);
		}
	}
	// if (e->rt.obj == 1)
	// 	mlx_pixel_put_to_image(e->img, x, y, 0x551A8B);
	// else if (e->rt.obj == 2)
	// 	mlx_pixel_put_to_image(e->img, x, y, 0xFB6500);
	// else if (e->rt.obj == 0)
	// 	mlx_pixel_put_to_image(e->img, x, y, 0x000000);
}

void		aff(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < LENGTH)
	{
		x = -1;
		while (++x < WIDTH)
		{
			raythingy(e, x, y);
		}
	}
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->img.img_ptr, 0, 0);
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
