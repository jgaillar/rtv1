/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 19:01:12 by prossi            #+#    #+#             */
/*   Updated: 2018/01/31 10:21:50 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_check_fih(t_stuff *e)
{
	double		d;

	if ((d = ft_myatod(e->b.tmp3)) == 2147483647)
		return (-1);
	if (!e->b.tabd)
		if (!(e->b.tabd = (double *)malloc(sizeof(double) * e->b.y)))
			return (-1);
	if (e->b.i < e->b.y)
	{
		e->b.tabd[e->b.i] = d;
		e->b.i++;
	}
	return (0);
}

int		ft_check_fh(t_stuff *e)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (e->b.tmp2[0] != ' ')
		return (-1);
	if ((e->b.tmp2[1] < 48 || e->b.tmp2[1] > 57) && e->b.tmp2[1] != '-')
		return (-1);
	if (!(e->b.tmp3 = ft_strsub(e->b.tmp2, 1, ft_strlen(e->b.tmp2) - 1)))
		return (-1);
	while (e->b.tmp3[i])
	{
		if ((e->b.tmp3[i] < 48 || e->b.tmp3[i] > 57) && e->b.tmp3[i] != '.')
			return (-1);
		if (e->b.tmp3[i] == '.')
			j++;
		if (j > 1)
			return (-1);
		i++;
	}
	if (ft_check_fih(e) == -1)
		return (-1);
	return (0);
}

int		ft_check_td(t_stuff *e, int x, int y, int i)
{
	if (!(e->b.tmp = ft_strsub(e->b.tab[y], 0, x + 1)))
		return (-1);
	if (ft_compare_camera(e->b.tmp, i) == -1)
		return (-1);
	if (!(e->b.tmp2 = ft_strsub(e->b.tab[y], x + 1, \
		ft_strlen(e->b.tab[y]) - x)))
		return (-1);
	if (ft_check_fh(e) == -1)
		return (-1);
	ft_strdel(&e->b.tmp);
	ft_strdel(&e->b.tmp2);
	ft_strdel(&e->b.tmp3);
	return (0);
}

int		ft_check_sd(t_stuff *e, int y)
{
	if (e->b.tab[y][0] <= 65 || e->b.tab[y][0] > 90)
		return (-1);
	if (e->b.tab[y][ft_strlen(e->b.tab[y]) - 1] < '0' || \
	e->b.tab[y][ft_strlen(e->b.tab[y]) - 1] > '9')
		return (-1);
	return (0);
}

int		ft_check(t_stuff *e)
{
	int		x;
	int		y;
	int		i;

	y = -1;
	i = 0;
	while (e->b.tab[++y])
	{
		if (ft_check_sd(e, y) == -1)
			return (-1);
		x = -1;
		while (e->b.tab[y][++x])
		{
			if (e->b.tab[y][x] == '=')
			{
				if (ft_check_td(e, x, y, i) == -1)
					return (-1);
				free(e->b.tab[y]);
				i++;
			}
		}
	}
	free(e->b.tab);
	return (0);
}
