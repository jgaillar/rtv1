/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   II.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:02:26 by prossi            #+#    #+#             */
/*   Updated: 2018/01/12 18:37:18 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rtv1.h"

void 	ft_init_segment_I(t_stuff *e, int option)
{
	if (option == 1)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy;
		e->bs.yf = e->bs.yi;
	}
	if (option == 2)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - 1;
		e->bs.yf = e->bs.yi;
	}
	if (option == 3)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - 2;
		e->bs.yf = e->bs.yi;
	}
	if (option == 4)
	{
		e->bs.xi = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yi = e->lt.posy;
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	if (option == 5)
	{
		e->bs.xi = (e->lt.posx + 1) + (12.5 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yi = e->lt.posy;
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	if (option == 6)
	{
		e->bs.xi = (e->lt.posx + 2) + (12.5 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yi = e->lt.posy;
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	if (option == 7)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 8)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yi = (e->lt.posy - 1) - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 9)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yi = (e->lt.posy - 2) - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
}

void	I(t_stuff *e)
{
	ft_init_segment_I(e, 1);
	ft_segment_letter(e);
	ft_init_segment_I(e, 2);
	ft_segment_letter(e);
	ft_init_segment_I(e, 3);
	ft_segment_letter(e);
	ft_init_segment_I(e, 4);
	ft_segment_letter(e);
	ft_init_segment_I(e, 5);
	ft_segment_letter(e);
	ft_init_segment_I(e, 6);
	ft_segment_letter(e);
	ft_init_segment_I(e, 7);
	ft_segment_letter(e);
	ft_init_segment_I(e, 8);
	ft_segment_letter(e);
	ft_init_segment_I(e, 9);
	ft_segment_letter(e);
}
