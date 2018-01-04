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
	if (button == 1 && (x >= 0 && x <= WIDTH) && (y >= 0 && y <= LENGTH))
	{
		reboot_list_loop(e, 3);
		raydir(e, x, y);
		check(e, &e->raydir, &e->poscam, 9999);
		check_dist(e, 9999);
		ft_putnbr(e->c.obj);
		ft_putchar('\n');
		if (e->c.obj == 0)
			ft_putnbr(e->c.objsph);
		else if (e->c.obj == 1)
			ft_putnbr(e->c.objpla);
		else if (e->c.obj == 2)
			ft_putnbr(e->c.objcyl);
		else if (e->c.obj == 3)
			ft_putnbr(e->c.objcone);
		else if (e->c.obj == 4)
			ft_putnbr(e->c.objlight);
		ft_putchar('\n');
		ft_segment(e, x, y, 0x9148D0 + x + y);
		mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->img.img_ptr, 0, 0);
	}
	return (0);
}
