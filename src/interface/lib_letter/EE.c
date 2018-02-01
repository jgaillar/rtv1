/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EE.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:01:23 by prossi            #+#    #+#             */
/*   Updated: 2018/01/12 16:51:48 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rtv1.h"

void	ft_init_segment_E(t_stuff *e, int option)
{
	if (option == 1)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	if (option == 2)
	{
		e->bs.xi = e->lt.posx + 1;
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	if (option == 3)
	{
		e->bs.xi = e->lt.posx + 2;
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	if (option == 4)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 5)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = (e->lt.posy - 1) - (50 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 6)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = (e->lt.posy - 2) - (50 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 7)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 8)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = (e->lt.posy - 1);
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 9)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = (e->lt.posy - 2);
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 10)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 11)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = (e->lt.posy - 1) - (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 12)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = (e->lt.posy - 2) - (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
}

void	E(t_stuff *e)
{
	ft_init_segment_E(e, 1);
	ft_segment_letter(e);
	ft_init_segment_E(e, 2);
	ft_segment_letter(e);
	ft_init_segment_E(e, 3);
	ft_segment_letter(e);
	ft_init_segment_E(e, 4);
	ft_segment_letter(e);
	ft_init_segment_E(e, 5);
	ft_segment_letter(e);
	ft_init_segment_E(e, 6);
	ft_segment_letter(e);
	ft_init_segment_E(e, 7);
	ft_segment_letter(e);
	ft_init_segment_E(e, 8);
	ft_segment_letter(e);
	ft_init_segment_E(e, 9);
	ft_segment_letter(e);
	ft_init_segment_E(e, 10);
	ft_segment_letter(e);
	ft_init_segment_E(e, 11);
	ft_segment_letter(e);
	ft_init_segment_E(e, 12);
	ft_segment_letter(e);
}
