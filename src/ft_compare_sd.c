/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_sd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:32:14 by prossi            #+#    #+#             */
/*   Updated: 2017/12/01 15:08:49 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_compare_cone_sd(char *str, int i)
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
	if (i == 9)
		if (ft_strcmp(str, "angle =") == 0)
			return (0);
	return (-1);
}

int		ft_compare_cone(char *str, int i)
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
	if (ft_compare_cone_sd(str, i) == 0)
		return (0);
	return (-1);
}

int		ft_compare_cylindre_sd(char *str, int i)
{
	if (i == 6)
		if (ft_strcmp(str, "ray =") == 0)
			return (0);
	if (i == 7)
		if (ft_strcmp(str, "r =") == 0)
			return (0);
	if (i == 8)
		if (ft_strcmp(str, "g =") == 0)
			return (0);
	if (i == 9)
		if (ft_strcmp(str, "b =") == 0)
			return (0);
	return (-1);
}

int		ft_compare_cylindre(char *str, int i)
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
		if (ft_strcmp(str, "normX =") == 0)
			return (0);
	if (i == 4)
		if (ft_strcmp(str, "normY =") == 0)
			return (0);
	if (i == 5)
		if (ft_strcmp(str, "normZ =") == 0)
			return (0);
	if (ft_compare_cylindre_sd(str, i) == 0)
		return (0);
	return (-1);
}

int		ft_compare_light_sd(char *str, int i)
{
	if (i == 6)
		if (ft_strcmp(str, "b =") == 0)
			return (0);
	if (i == 7)
		if (ft_strcmp(str, "amb =") == 0)
			return (0);
	if (i == 8)
		if (ft_strcmp(str, "diff =") == 0)
			return (0);
	return (-1);
}

int		ft_compare_light(char *str, int i)
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
	if (ft_compare_light_sd(str, i) == 0)
		return (0);
	return (-1);
}
