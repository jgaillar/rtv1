/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   YY.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:09:50 by prossi            #+#    #+#             */
/*   Updated: 2018/01/15 07:58:10 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rtv1.h"

void	ft_init_segment_Y(t_stuff *e, int option)
{
	if (option == 1)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi + (25 * e->lt.coeff);
	}
	if (option == 2)
	{
		e->bs.xi = e->lt.posx + 1;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi + (25 * e->lt.coeff);
	}
	if (option == 3)
	{
		e->bs.xi = e->lt.posx + 2;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi + (25 * e->lt.coeff);
	}
	if (option == 4)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi + (25 * e->lt.coeff);
	}
	if (option == 5)
	{
		e->bs.xi = e->lt.posx + 1 + (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi + (25 * e->lt.coeff);
	}
	if (option == 6)
	{
		e->bs.xi = e->lt.posx + 2 + (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi + (25 * e->lt.coeff);
	}
	if (option == 7)
	{
		e->bs.xi = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yi = e->lt.posy;
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff);
	}
	if (option == 8)
	{
		e->bs.xi = e->lt.posx + 1 + (12.5 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yi = e->lt.posy;
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff);
	}
	if (option == 9)
	{
		e->bs.xi = e->lt.posx + 2 + (12.5 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yi = e->lt.posy;
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff);
	}
}

void	Y(t_stuff *e)
{
	ft_init_segment_Y(e, 1);
	ft_segment_letter(e);
	ft_init_segment_Y(e, 2);
	ft_segment_letter(e);
	ft_init_segment_Y(e, 3);
	ft_segment_letter(e);
	ft_init_segment_Y(e, 4);
	ft_segment_letter(e);
	ft_init_segment_Y(e, 5);
	ft_segment_letter(e);
	ft_init_segment_Y(e, 6);
	ft_segment_letter(e);
	ft_init_segment_Y(e, 7);
	ft_segment_letter(e);
	ft_init_segment_Y(e, 8);
	ft_segment_letter(e);
	ft_init_segment_Y(e, 9);
	ft_segment_letter(e);
}
