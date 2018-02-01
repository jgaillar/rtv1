/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FF.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:01:39 by prossi            #+#    #+#             */
/*   Updated: 2018/01/12 16:57:32 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rtv1.h"

void	ft_init_segment_F(t_stuff *e, int option)
{
	if (option == 1)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi  = e->lt.posy;
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
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 5)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yi = (e->lt.posy - 1) - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 6)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yi = (e->lt.posy - 2) - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 7)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 8)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yi = (e->lt.posy - 1) - (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 9)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yi = (e->lt.posy - 2) - (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
}

void	F(t_stuff *e)
{
	ft_init_segment_F(e, 1);
	ft_segment_letter(e);
	ft_init_segment_F(e, 2);
	ft_segment_letter(e);
	ft_init_segment_F(e, 3);
	ft_segment_letter(e);
	ft_init_segment_F(e, 4);
	ft_segment_letter(e);
	ft_init_segment_F(e, 5);
	ft_segment_letter(e);
	ft_init_segment_F(e, 6);
	ft_segment_letter(e);
	ft_init_segment_F(e, 7);
	ft_segment_letter(e);
	ft_init_segment_F(e, 8);
	ft_segment_letter(e);
	ft_init_segment_F(e, 9);
	ft_segment_letter(e);
}
