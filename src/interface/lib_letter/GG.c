/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GG.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:01:55 by prossi            #+#    #+#             */
/*   Updated: 2018/01/12 22:51:13 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rtv1.h"

void	ft_init_segment_G(t_stuff *e, int option)
{
	if (option == 1)
	{
		e->bs.x_arc = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.y_arc = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.ray_arc = (12.5 * e->lt.coeff);
	}
	if (option == 2)
	{
		e->bs.x_arc = (e->lt.posx + 1) + (12.5 * e->lt.coeff);
	}
	if (option == 3)
	{
		e->bs.x_arc = (e->lt.posx + 2) + (12.5 * e->lt.coeff);
	}
	if (option == 4)
	{
		e->bs.x_arc = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.y_arc = e->lt.posy - (37.5 * e->lt.coeff);
		e->bs.ray_arc = (12.5 * e->lt.coeff);
	}
	if (option == 5)
	{
		e->bs.x_arc = (e->lt.posx + 1) + (12.5 * e->lt.coeff);
	}
	if (option == 6)
	{
		e->bs.x_arc = (e->lt.posx + 2) + (12.5 * e->lt.coeff);
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
		e->bs.x_arc = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.y_arc = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.ray_arc = (12.5 * e->lt.coeff);
	}
	if (option == 11)
	{
		e->bs.x_arc = e->lt.posx + 1 + (12.5 * e->lt.coeff);
	}
	if (option == 12)
	{
		e->bs.x_arc = e->lt.posx + 2 + (12.5 * e->lt.coeff);
	}
	if (option == 13)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yi = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (12.5 * e->lt.coeff);
	}
	if (option == 14)
	{
		e->bs.xi = e->lt.posx + 1 + (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yi = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (12.5 * e->lt.coeff);
	}
	if (option == 15)
	{
		e->bs.xi = e->lt.posx + 2 + (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yi = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (12.5 * e->lt.coeff);
	}
	if (option == 16)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 17)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - 1 -  (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 18)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - 2 - (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
}

void	G(t_stuff *e)
{
	ft_init_segment_G(e, 1);
	ft_arc(e, 5);
	ft_init_segment_G(e, 2);
	ft_arc(e, 5);
	ft_init_segment_G(e, 3);
	ft_arc(e, 5);
	ft_init_segment_G(e, 4);
	ft_arc(e, 7);
	ft_init_segment_G(e, 5);
	ft_arc(e, 7);
	ft_init_segment_G(e, 6);
	ft_arc(e, 7);
	ft_init_segment_G(e, 7);
	ft_segment_letter(e);
	ft_init_segment_G(e, 8);
	ft_segment_letter(e);
	ft_init_segment_G(e, 9);
	ft_segment_letter(e);
	ft_init_segment_G(e, 10);
	ft_arc(e, 6);
	ft_init_segment_G(e, 11);
	ft_arc(e, 6);
	ft_init_segment_G(e, 12);
	ft_arc(e, 6);
	ft_init_segment_G(e, 13);
	ft_segment_letter(e);
	ft_init_segment_G(e, 14);
	ft_segment_letter(e);
	ft_init_segment_G(e, 15);
	ft_segment_letter(e);
	ft_init_segment_G(e, 16);
	ft_segment_letter(e);
	ft_init_segment_G(e, 17);
	ft_segment_letter(e);
	ft_init_segment_G(e, 18);
	ft_segment_letter(e);
}
