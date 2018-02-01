/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QQ.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:06:20 by prossi            #+#    #+#             */
/*   Updated: 2018/01/13 01:22:43 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rtv1.h"

void	ft_init_segment_Q(t_stuff *e, int option)
{
	if (option == 1)
	{
		e->bs.x_arc = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.y_arc = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.ray_arc = (12.5 * e->lt.coeff);
	}
	if (option == 2)
		e->bs.x_arc += 1;
	if (option == 3)
		e->bs.x_arc += 1;
	if (option == 4)
	{
		e->bs.x_arc = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.y_arc = e->lt.posy - (37.5 * e->lt.coeff);
		e->bs.ray_arc = (12.5 * e->lt.coeff);
	}
	if (option == 5)
	{
		e->bs.x_arc += 1;
	}
	if (option == 6)
	{
		e->bs.x_arc += 1;
	}
	if (option == 7)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi;
		e->bs.yi = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff);
	}
	if (option == 8)
	{
		e->bs.xi = e->lt.posx + 1;
		e->bs.xf = e->bs.xi;
		e->bs.yi = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff);
	}
	if (option == 9)
	{
		e->bs.xi = e->lt.posx + 2;
		e->bs.xf = e->bs.xi;
		e->bs.yi = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff);
	}
	if (option == 10)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yi = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff);
	}
	if (option == 11)
	{
		e->bs.xi = e->lt.posx + 1 + (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yi = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff);
	}
	if (option == 12)
	{
		e->bs.xi = e->lt.posx + 2 + (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yi = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff);
	}
	if (option == 13)
	{
		e->bs.xi = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.yf = e->lt.posy;
	}
	if (option == 14)
	{
		e->bs.xi = e->lt.posx + 1 + (12.5 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.yf = e->lt.posy;
	}
	if (option == 15)
	{
		e->bs.xi = e->lt.posx + 2 + (12.5 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.yf = e->lt.posy;
	}
}

void	Q(t_stuff *e)
{
	ft_init_segment_Q(e, 1);
	ft_arc(e, 4);
	ft_init_segment_Q(e, 2);
	ft_arc(e, 4);
	ft_init_segment_Q(e, 3);
	ft_arc(e, 4);
	ft_init_segment_Q(e, 4);
	ft_arc(e, 3);
	ft_init_segment_Q(e, 5);
	ft_arc(e, 3);
	ft_init_segment_Q(e, 6);
	ft_arc(e, 3);
	ft_init_segment_Q(e, 7);
	ft_segment_letter(e);
	ft_init_segment_Q(e, 8);
	ft_segment_letter(e);
	ft_init_segment_Q(e, 9);
	ft_segment_letter(e);
	ft_init_segment_Q(e, 10);
	ft_segment_letter(e);
	ft_init_segment_Q(e, 11);
	ft_segment_letter(e);
	ft_init_segment_Q(e, 12);
	ft_segment_letter(e);
	ft_init_segment_Q(e, 13);
	ft_segment_letter(e);
	ft_init_segment_Q(e, 14);
	ft_segment_letter(e);
	ft_init_segment_Q(e, 15);
	ft_segment_letter(e);
}
