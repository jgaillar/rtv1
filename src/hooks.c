/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 10:47:04 by jgaillar          #+#    #+#             */
/*   Updated: 2017/11/10 15:56:11 by jgaillar         ###   ########.fr       */
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
		e->light.posl.y -= 1;
	if (keycode == 0)
		e->light.posl.y += 1;
	if (keycode == 1)
		e->light.posl.x -= 1;
	if (keycode == 13)
		e->light.posl.x += 1;
}
