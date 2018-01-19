/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counttabchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:10:10 by prossi            #+#    #+#             */
/*   Updated: 2017/12/01 12:18:20 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_counttabchar(char **tab)
{
	int		y;
	int		x;

	if (!tab)
		return (-1);
	y = -1;
	while (tab[++y])
	{
		x = -1;
		while (tab[y][++x])
			;
	}
	return (y);
}
