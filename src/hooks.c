/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 10:47:04 by jgaillar          #+#    #+#             */
/*   Updated: 2017/11/24 14:47:16 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		hooks(int keycode, t_stuff *e)
{
	echap(keycode, e);
	movement(keycode, e);
	aff(e);
	return (0);
}

void	echap(int keycode, t_stuff *e)
{
	if (keycode == 53)
    {
		free(e->img.data);
		mlx_destroy_image(e->img.mlx_ptr, e->img.win_ptr);
		exit(0);
    }
}

void	cleanexit(t_stuff *e)
{
	free(e->img.data);
	mlx_destroy_image(e->img.mlx_ptr, e->img.win_ptr);
	exit(0);
}

void	movement(int keycode, t_stuff *e)
{
	if (keycode == 2)
		e->light.pos.y -= 0.5;
	if (keycode == 0)
		e->light.pos.y += 0.5;
	if (keycode == 1)
		e->light.pos.x -= 0.5;
	if (keycode == 13)
		e->light.pos.x += 0.5;
	if (keycode == 49)
		e->light.pos.z += 0.5;
	if (keycode == 8)
		e->light.pos.z -= 0.5;
	if (keycode == 125)
		e->sphere.poss.x -= 0.5;
	if (keycode == 126)
		e->sphere.poss.x += 0.5;
	if (keycode == 123)
		e->sphere.poss.y += 0.5;
	if (keycode == 124)
		e->sphere.poss.y -= 0.5;
	if (keycode == 78)
		e->sphere.poss.z -= 0.5;
	if (keycode == 69)
		e->sphere.poss.z += 0.5;
	if (keycode == 27)
		e->sphere.rayon -= 0.5;
	if (keycode == 24)
		e->sphere.rayon += 0.5;
	if (keycode == 91)
		e->plan.normp.x += 0.1;
	if (keycode == 86)
		e->plan.normp.y += 0.1;
	if (keycode == 87)
		e->plan.normp.x -= 0.1;
	if (keycode == 88)
		e->plan.normp.y -= 0.1;
	if (keycode == 89)
		e->plan.normp.z -= 0.5;
	if (keycode == 92)
		e->plan.normp.z += 0.5;
	if (keycode == 83)
		e->plan.plan.y -= 0.1;
	if (keycode == 84)
		e->plan.plan.x += 0.1;
	if (keycode == 85)
		e->plan.plan.y += 0.1;
	if (keycode == 82)
		e->plan.plan.x -= 0.1;
	if (keycode == 81 && e->light.rayon - 0.1 > -0.00001)
		e->light.rayon -= 0.1;
	if (keycode == 75)
		e->light.rayon += 0.1;
}
