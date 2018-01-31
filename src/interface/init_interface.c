/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:25:42 by prossi            #+#    #+#             */
/*   Updated: 2018/01/31 18:51:54 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void 	init_struct(t_stuff *e)
{
	e->i.i = 10;
	ft_putnbr(e->i.i);
}

int		first_launch_interface(t_stuff *e)
{
	e->i.init = mlx_init();
	e->i.wdow = mlx_new_window(a->i.init, WIN_X, WIN_Y)
	init_struct(e);
}
