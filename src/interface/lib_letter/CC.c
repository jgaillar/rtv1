/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CC.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:00:43 by prossi            #+#    #+#             */
/*   Updated: 2018/01/15 19:01:55 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rtv1.h"

void	ft_init_segment_C(t_stuff *e, int option)
{
	// ARC GAUCHE
	if (option == 1)
	{
		e->bs.x_arc = e->lt.posx + (25 * e->lt.coeff);
		e->bs.y_arc = e->lt.posy - (25 * e->lt.coeff);
		e->bs.ray_arc = (25 * e->lt.coeff);
	}
	if (option == 2)
	{
		e->bs.x_arc = (e->lt.posx + 1) + (25 * e->lt.coeff);
		// e->bs.y_arc = e->lt.posy - (25 * e->lt.coeff);
		// e->bs.ray_arc = (25 * e->lt.coeff) - 1;
	}
	if (option == 3)
	{
		e->bs.x_arc = (e->lt.posx + 2) + (25 * e->lt.coeff);
		// e->bs.ray_arc = (25 * e->lt.coeff) - 2;
	}
}

void	C(t_stuff *e)
{
	ft_init_segment_C(e, 1);
	ft_arc(e, 2);
	ft_init_segment_C(e, 2);
	ft_arc(e, 2);
	ft_init_segment_C(e, 3);
	ft_arc(e, 2);
}
