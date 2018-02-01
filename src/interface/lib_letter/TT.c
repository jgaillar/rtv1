/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TT.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:08:10 by prossi            #+#    #+#             */
/*   Updated: 2018/01/13 13:17:29 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rtv1.h"

void	ft_init_segment_T(t_stuff *e, int option)
{
	if (option == 1)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 2)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - 1 - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 3)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - 2 - (50 * e->lt.coeff);
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
		e->bs.xi = e->lt.posx + 1 + (12.5 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yi = e->lt.posy;
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	if (option == 6)
	{
		e->bs.xi = e->lt.posx + 2 + (12.5 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yi = e->lt.posy;
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
}

void	T(t_stuff *e)
{
	ft_init_segment_T(e, 1);
	ft_segment_letter(e);
	ft_init_segment_T(e, 2);
	ft_segment_letter(e);
	ft_init_segment_T(e, 3);
	ft_segment_letter(e);
	ft_init_segment_T(e, 4);
	ft_segment_letter(e);
	ft_init_segment_T(e, 5);
	ft_segment_letter(e);
	ft_init_segment_T(e, 6);
	ft_segment_letter(e);
}
