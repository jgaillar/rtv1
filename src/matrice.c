/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:08:00 by prossi            #+#    #+#             */
/*   Updated: 2018/01/31 14:44:46 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rotation_z(t_vec *sujet, double radian)
{
	double	tmpx;
	double	tmpy;
	double	tmpz;
	double	sinus;
	double	cosinus;

	sinus = sin(radian);
	cosinus = cos(radian);
	tmpx = sujet->x;
	tmpy = sujet->y;
	tmpz = sujet->z;
	sujet->x = (cosinus * tmpx) + (-sinus * tmpy);
	sujet->y = (sinus * tmpx) + (cosinus * tmpy);
	sujet->z = tmpz;
}

void	rotation_y(t_vec *sujet, double radian)
{
	double	tmpx;
	double	tmpy;
	double	tmpz;
	double	sinus;
	double	cosinus;

	sinus = sin(radian);
	cosinus = cos(radian);
	tmpx = sujet->x;
	tmpy = sujet->y;
	tmpz = sujet->z;
	sujet->x = (cosinus * tmpx) + (sinus * tmpz);
	sujet->y = tmpy;
	sujet->z = (-sinus * tmpx) + (cosinus * tmpz);
}

void	rotation_x(t_vec *sujet, double	radian)
{
	double	tmpx;
	double	tmpy;
	double	tmpz;
	double	sinus;
	double	cosinus;

	sinus = sin(radian);
	cosinus = cos(radian);
	tmpx = sujet->x;
	tmpy = sujet->y;
	tmpz = sujet->z;
	sujet->x = tmpx;
	sujet->y = (cosinus * tmpy) + (-sinus * tmpz);
	sujet->z = (sinus * tmpy) + (cosinus * tmpz);
}

void	translation_x(t_vec *sujet, double value)
{
	sujet->x += value;
}

void	translation_y(t_vec *sujet, double value)
{
	sujet->y += value;
}

void	translation_z(t_vec *sujet, double value)
{
	sujet->z += value;
}

void	convert_deg_in_rad(int angle_degre, t_stuff *e)
{
	e->m.radian = angle_degre * (M_PI / 180);
}

void	matrice(char type, char axe, t_stuff *e, t_vec *sujet)
{
	if (type == 'r')
	{
		convert_deg_in_rad(e->m.angle, e);
		if (axe == 'x')
		{
			rotation_x(sujet, e->m.radian);
		}
		else if (axe == 'y')
		{
			rotation_y(sujet, e->m.radian);
		}
		else if (axe == 'z')
		{
			rotation_z(sujet, e->m.radian);
		}
		printf("\nUne rotation en [%c] d'un angle de [%.0fº] vient d'etre effectuée\n", axe, e->m.angle);
		printf("\nNouvelle valeur du sujet : x : [%.2f] y : [%.2f] z : [%.2f]\n", sujet->x, sujet->y, sujet->z);
	}
	else if (type == 't')
	{
		if (axe == 'x')
		{
			translation_x(sujet, e->m.value);
		}
		else if (axe == 'y')
		{
			translation_x(sujet, e->m.value);
		}
		else if (axe == 'z')
		{
			translation_x(sujet, e->m.value);
		}
		printf("\nUne translation en [%c] d'une valeur de [%.0f] vient d'etre effectuée\n", axe, e->m.value);
	}
}
