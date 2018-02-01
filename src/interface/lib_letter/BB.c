/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BB.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:00:25 by prossi            #+#    #+#             */
/*   Updated: 2018/01/12 14:37:54 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rtv1.h"

void	ft_init_segment_B(t_stuff *e, int option)
{
	// BARRE DU B gauche
	if (option == 0)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	// BARRE DU B centre
	else if (option == 1)
	{
		e->bs.xi = e->lt.posx + 1;
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	// BARRE DU B droite
	else if (option == 2)
	{
		e->bs.xi = e->lt.posx + 2;
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	// PREMIERE BARRE HAUT
	else if (option == 3)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (13.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	// DEUXIEME BARRE HAUT
	else if (option == 4)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (13.5 * e->lt.coeff);
		e->bs.yi = (e->lt.posy - 1) - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	// TROISIEME BARRE HAUT
	else if (option == 5)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (13.5 * e->lt.coeff);
		e->bs.yi = (e->lt.posy - 2) - (50 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	// PREMIERE BARRE BAS
	else if (option == 6)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (13.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy;
		e->bs.yf = e->bs.yi;
	}
	// DEUXIEME BARRE BAS
	else if (option == 7)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (13.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - 1;
		e->bs.yf = e->bs.yi;
	}
	// TROISIEME BARRE BAS
	else if (option == 8)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->bs.xi + (13.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - 2;
		e->bs.yf = e->bs.yi;
	}
	// PREMIER DEMI CERCLE (superieur)
	else if (option == 9)
	{
		e->bs.x_arc = e->lt.posx + (13.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy;
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
		e->bs.y_arc = ((e->bs.yi - e->bs.yf) / 4) + e->bs.yf;
		e->bs.ray_arc = 12.5 * e->lt.coeff;
	}
	// SECOND DEMI CERCLE (superieur)
	else if (option == 10)
		e->bs.y_arc--;
	// TROISIEME DEMI CERCLE (superieur)
	else if (option == 11)
		e->bs.y_arc--;
	// PREMIER DEMI CERCLE (inferieur)
	else if (option == 12)
	{
		e->bs.yi = e->lt.posy;
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
		e->bs.y_arc = (((e->bs.yi - e->bs.yf) / 4) * 3) + e->bs.yf;
	}
	// DEUXIEME DEMI CERCLE (inferieur)
	else if (option == 13)
		e->bs.y_arc--;
	// TROISIEME DEMI CERCLE (inferieur)
	else if (option == 14)
		e->bs.y_arc--;
}

void	B(t_stuff *e)
{
	ft_init_segment_B(e, 0);
	ft_segment_letter(e);
	ft_init_segment_B(e, 1);
	ft_segment_letter(e);
	ft_init_segment_B(e, 2);
	ft_segment_letter(e);
	ft_init_segment_B(e, 3);
	ft_segment_letter(e);
	ft_init_segment_B(e, 4);
	ft_segment_letter(e);
	ft_init_segment_B(e, 5);
	ft_segment_letter(e);
	ft_init_segment_B(e, 6);
	ft_segment_letter(e);
	ft_init_segment_B(e, 7);
	ft_segment_letter(e);
	ft_init_segment_B(e, 8);
	ft_segment_letter(e);
	ft_init_segment_B(e, 9);
	ft_arc(e, 1);
	ft_init_segment_B(e, 10);
	ft_arc(e, 1);
	ft_init_segment_B(e, 11);
	ft_arc(e, 1);
	ft_init_segment_B(e, 12);
	ft_arc(e, 1);
	ft_init_segment_B(e, 13);
	ft_arc(e, 1);
	ft_init_segment_B(e, 14);
	ft_arc(e, 1);
}
