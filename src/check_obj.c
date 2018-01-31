/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:57:18 by jgaillar          #+#    #+#             */
/*   Updated: 2017/12/05 10:26:51 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
	double	a;
	double	b;
	double	c;
	t_vec	l;

	vecsous(&l, poscam, &cyl->pos);
	a = dot_product(raydir, raydir) - (dot_product(raydir, &cyl->norm) \
	* dot_product(raydir, &cyl->norm));
	b = 2 * (dot_product(raydir, &l) - (dot_product(raydir, &cyl->norm) \
	* dot_product(&l, &cyl->norm)));
	c = dot_product(&l, &l) - (dot_product(&l, &cyl->norm) \
	* dot_product(&l, &cyl->norm)) - cyl->ray * cyl->ray;
	cyl->det = (b * b) - 4 * a * c;
	// if (cyl->det != 0)
	// {
		cyl->t1 = (-b - sqrt(cyl->det)) / (2 * a);
		cyl->t2 = (-b + sqrt(cyl->det)) / (2 * a);
		cyl->t = (cyl->t1 <= cyl->t2 ? cyl->t1 : cyl->t2);
	// }
	// else
		// cyl->t = (-b / 2 * a);
}

void		checkcone(t_cone *cone, t_vec *raydir, t_vec *poscam)
{
	t_vec tmp;
	t_vec	l;
	double	a;
	double	b;
	double	c;

	tmp.x = 1;
	tmp.y = 0;
	tmp.z = 0;
	vecsous(&l ,poscam, &cone->pos);
	a = dot_product(raydir, raydir) - (1 + tan(cone->angle) * tan(cone->angle)) \
	* (dot_product(raydir, &cone->norm) * dot_product(raydir, &cone->norm));
	b = 2 * (dot_product(raydir, &l) - (1 + tan(cone->angle) * \
	tan(cone->angle)) * (dot_product(raydir, &cone->norm) * dot_product(&l, &cone->norm)));
	c = dot_product(&l, &l) - (1 + tan(cone->angle) * tan(cone->angle)) \
	* (dot_product(&l, &cone->norm) * dot_product(&l, &cone->norm));
	cone->det = (b * b) - 4 * a * c;
	if (cone->det < 0)
		cone->t = -1;
	else if (cone->det != 0)
	{
		cone->t1 = -b - sqrt(cone->det) / (2 * a);
		cone->t2 = -b + sqrt(cone->det) / (2 * a);
		cone->t = (cone->t1 <= cone->t2 ? cone->t1 : cone->t2);
	}
	else
		cone->t = (-b / 2 * a);
}
