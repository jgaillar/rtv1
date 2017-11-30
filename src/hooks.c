/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 10:47:04 by jgaillar          #+#    #+#             */
/*   Updated: 2017/11/30 16:27:22 by jgaillar         ###   ########.fr       */
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
		e->sphere.pos.x -= 0.5;
	if (keycode == 126)
		e->sphere.pos.x += 0.5;
	if (keycode == 123)
		e->sphere.pos.y += 0.5;
	if (keycode == 124)
		e->sphere.pos.y -= 0.5;
	if (keycode == 78)
		e->sphere.pos.z -= 0.5;
	if (keycode == 69)
		e->sphere.pos.z += 0.5;
	if (keycode == 27)
		e->sphere.ray -= 0.5;
	if (keycode == 24)
		e->sphere.ray += 0.5;
	if (keycode == 91)
		e->plan.norm.x += 0.1;
	if (keycode == 86)
		e->plan.norm.y += 0.1;
	if (keycode == 87)
		e->plan.norm.x -= 0.1;
	if (keycode == 88)
		e->plan.norm.y -= 0.1;
	if (keycode == 89)
		e->plan.norm.z -= 0.5;
	if (keycode == 92)
		e->plan.norm.z += 0.5;
	if (keycode == 83)
		e->plan.pos.y -= 0.1;
	if (keycode == 84)
		e->plan.pos.x += 0.1;
	if (keycode == 85)
		e->plan.pos.y += 0.1;
	if (keycode == 82)
		e->plan.pos.x -= 0.1;
	if (keycode == 81 && e->light.ray - 0.1 > -0.00001)
		e->light.ray -= 0.1;
	if (keycode == 75)
		e->light.ray += 0.1;
	if (keycode == 34)
		e->cyl.pos.x += 0.5;
	if (keycode == 38)
		e->cyl.pos.y += 0.5;
	if (keycode == 40)
		e->cyl.pos.x -= 0.5;
	if (keycode == 37)
		e->cyl.pos.y -= 0.5;
	if (keycode == 17)
		e->con.pos.x += 0.1;
	if (keycode == 3)
		e->con.pos.y += 0.1;
	if (keycode == 5)
		e->con.pos.x -= 0.1;
	if (keycode == 4)
		e->con.pos.y -= 0.1;
	if (keycode == 15)
		e->con.pos.z -= 0.1;
	if (keycode == 16)
		e->con.pos.z += 0.1;
	if (keycode == 43 && e->pix - 2 >= 0)
		e->pix -= 2;
	if (keycode == 47 && e->pix + 2 < 20)
		e->pix += 2;
}
