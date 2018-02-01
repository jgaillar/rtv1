/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AA.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:59:24 by prossi            #+#    #+#             */
/*   Updated: 2018/02/01 18:08:05 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rtv1.h"

void	ft_init_segment_A(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	if (option == 1)
	{
		e->bs.xi = e->lt.posx + 1;
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	if (option == 2)
	{
		e->bs.xi = e->lt.posx + 2;
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	if (option == 3)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	if (option == 4)
	{
		e->bs.xi = (e->lt.posx + 1) + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	if (option == 5)
	{
		e->bs.xi = (e->lt.posx + 2) + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	if (option == 6)
	{
		e->bs.xi = e->lt.posx + (6.25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 7)
	{
		e->bs.xi = (e->lt.posx + 1) + (6.25 * e->lt.coeff);
		e->bs.yi = (e->lt.posy - (25 * e->lt.coeff) + 1);
		e->bs.xf = (e->bs.xi + (12.5 * e->lt.coeff));
		e->bs.yf = e->bs.yi;
	}
	if (option == 8)
	{
		e->bs.xi = (e->lt.posx + 2) + (6.25 * e->lt.coeff);
		e->bs.yi = (e->lt.posy - (25 * e->lt.coeff) + 2);
		e->bs.xf = (e->bs.xi + (12.5 * e->lt.coeff));
		e->bs.yf = e->bs.yi;
	}
}
void	A(t_stuff *e)
{
	ft_init_segment_A(e, 0);
	ft_segment_letter(e);
	ft_init_segment_A(e, 1);
	ft_segment_letter(e);
	ft_init_segment_A(e, 2);
	ft_segment_letter(e);
	ft_init_segment_A(e, 3);
	ft_segment_letter(e);
	ft_init_segment_A(e, 4);
	ft_segment_letter(e);
	ft_init_segment_A(e, 5);
	ft_segment_letter(e);
	ft_init_segment_A(e, 6);
	ft_segment_letter(e);
	ft_init_segment_A(e, 7);
	ft_segment_letter(e);
	ft_init_segment_A(e, 8);
	ft_segment_letter(e);
}
