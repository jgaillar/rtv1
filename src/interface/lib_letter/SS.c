/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SS.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:07:48 by prossi            #+#    #+#             */
/*   Updated: 2018/01/13 01:47:47 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rtv1.h"

void	ft_init_segment_S(t_stuff *e, int option)
{
	if (option == 1)
	{
		e->bs.x_arc = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.y_arc = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.ray_arc = 12.5 * e->lt.coeff;
	}
	if (option == 2)
	{
		e->bs.y_arc--;
	}
	if (option == 3)
	{
		e->bs.y_arc--;
	}
	if (option == 4)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy;
		e->bs.yf = e->bs.yi;
	}
	if (option == 5)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - 1;
		e->bs.yf = e->bs.yi;
	}
	if (option == 6)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - 2;
		e->bs.yf = e->bs.yi;
	}
	if (option == 7)
	{
		e->bs.x_arc = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.y_arc = e->lt.posy - (37.5 * e->lt.coeff);
		e->bs.ray_arc = 12.5 * e->lt.coeff;
	}
	if (option == 8)
	{
		e->bs.y_arc--;
	}
	if (option == 9)
	{
		e->bs.y_arc--;
	}
	if (option == 10)
	{
		e->bs.xi = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 11)
	{
		e->bs.xi = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - 1 - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 12)
	{
		e->bs.xi = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - 2 - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
}

void	S(t_stuff *e)
{
	ft_init_segment_S(e, 1);
	ft_arc(e, 1);
	ft_init_segment_S(e, 2);
	ft_arc(e, 1);
	ft_init_segment_S(e, 3);
	ft_arc(e, 1);
	ft_init_segment_S(e, 4);
	ft_segment_letter(e);
	ft_init_segment_S(e, 5);
	ft_segment_letter(e);
	ft_init_segment_S(e, 6);
	ft_segment_letter(e);
	ft_init_segment_S(e, 7);
	ft_arc(e, 2);
	ft_init_segment_S(e, 8);
	ft_arc(e, 2);
	ft_init_segment_S(e, 9);
	ft_arc(e, 2);
	ft_init_segment_S(e, 10);
	ft_segment_letter(e);
	ft_init_segment_S(e, 11);
	ft_segment_letter(e);
	ft_init_segment_S(e, 12);
	ft_segment_letter(e);
}
