/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:28:57 by prossi            #+#    #+#             */
/*   Updated: 2017/12/01 12:33:11 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_compare_plan_sd(char *str, int i)
{
	if (i == 6)
		if (ft_strcmp(str, "normX =") == 0)
			return (0);
	if (i == 7)
		if (ft_strcmp(str, "normY =") == 0)
			return (0);
	if (i == 8)
		if (ft_strcmp(str, "normZ =") == 0)
			return (0);
	return (-1);
}

int		ft_compare_plan(char *str, int i)
{
	if (i == 0)
		if (ft_strcmp(str, "x =") == 0)
			return (0);
	if (i == 1)
		if (ft_strcmp(str, "y =") == 0)
			return (0);
	if (i == 2)
		if (ft_strcmp(str, "z =") == 0)
			return (0);
	if (i == 3)
		if (ft_strcmp(str, "r =") == 0)
			return (0);
	if (i == 4)
		if (ft_strcmp(str, "g =") == 0)
			return (0);
	if (i == 5)
		if (ft_strcmp(str, "b =") == 0)
			return (0);
	if (ft_compare_plan_sd(str, i) == 0)
		return (0);
	return (-1);
}

int		ft_compare_sphere(char *str, int i)
{
	if (i == 0)
		if (ft_strcmp(str, "x =") == 0)
			return (0);
	if (i == 1)
		if (ft_strcmp(str, "y =") == 0)
			return (0);
	if (i == 2)
		if (ft_strcmp(str, "z =") == 0)
			return (0);
	if (i == 3)
		if (ft_strcmp(str, "ray =") == 0)
			return (0);
	if (i == 4)
		if (ft_strcmp(str, "r =") == 0)
			return (0);
	if (i == 5)
		if (ft_strcmp(str, "g =") == 0)
			return (0);
	if (i == 6)
		if (ft_strcmp(str, "b =") == 0)
			return (0);
	return (-1);
}

int		ft_compare_camera_sd(char *str, int i)
{
	if (i == 6)
		if (ft_strcmp(str, "Vhaut.x =") == 0)
			return (0);
	if (i == 7)
		if (ft_strcmp(str, "Vhaut.y =") == 0)
			return (0);
	if (i == 8)
		if (ft_strcmp(str, "Vhaut.z =") == 0)
			return (0);
	return (-1);
}

int		ft_compare_camera(char *str, int i)
{
	if (i == 0)
		if (ft_strcmp(str, "Poscam.x =") == 0)
			return (0);
	if (i == 1)
		if (ft_strcmp(str, "Poscam.y =") == 0)
			return (0);
	if (i == 2)
		if (ft_strcmp(str, "Poscam.z =") == 0)
			return (0);
	if (i == 3)
		if (ft_strcmp(str, "Ptregard.x =") == 0)
			return (0);
	if (i == 4)
		if (ft_strcmp(str, "Ptregard.y =") == 0)
			return (0);
	if (i == 5)
		if (ft_strcmp(str, "Ptregard.z =") == 0)
			return (0);
	if (ft_compare_camera_sd(str, i) == 0)
		return (0);
	return (-1);
}
