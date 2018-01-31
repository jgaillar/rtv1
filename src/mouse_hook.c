/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:14:48 by jgaillar          #+#    #+#             */
/*   Updated: 2018/01/04 16:14:49 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		mouse_hook(int button, int x, int y, t_stuff *e)
{
	double color;

	if (button == 1 && (x >= 0 && x <= WIDTH) && (y >= 0 && y <= LENGTH))
	{
		mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->img.img_ptr, 0, 0);
		reboot_list_loop(e, 3);
		raydir(e, x, y);
		check(e, &e->raydir, &e->poscam, 1);
		check_dist(e, 1);
		if (e->c.obj == 0)
		{
			color = 0x6a74af;
			ft_putstr("SPHERE : ");
			ft_putnbr(e->c.objsph);
			ft_putchar('\n');
		}
		else if (e->c.obj == 1)
		{
			color = 0xf3a1d1;
			ft_putstr("PLAN : ");
			ft_putnbr(e->c.objpla);
			ft_putchar('\n');
		}
		else if (e->c.obj == 2)
		{
			color = 0xff5370;
			ft_putstr("CYLINDRE : ");
			ft_putnbr(e->c.objcyl);
			ft_putchar('\n');
		}
		else if (e->c.obj == 3)
		{
			color = 0x73d1c8;
			ft_putstr("CONE : ");
			ft_putnbr(e->c.objcone);
			ft_putchar('\n');
		}
		else if (e->c.obj == 4)
		{
			color = 0xff9966;
			ft_putstr("LIGHT : ");
			ft_putnbr(e->c.objlight);
			ft_putchar('\n');
		}
		if (e->c.obj > -1)
			ft_segment(e, x, y, color);
	}
	return (0);
}
