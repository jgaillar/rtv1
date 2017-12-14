/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_light->c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:30:28 by prossi            #+#    #+#             */
/*   Updated: 2017/12/01 11:12:40 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		check_data_light_fh(t_stuff *e, char *nb)
{
	double		d;

	if ((d = ft_myatod(nb)) == 2147483647)
		return (-1);
	e->d.tabdlight[++e->d.i] = d;
	return (0);
}

int		check_data_light_td(t_stuff *e, char *str)
{
	int		i;
	char	*nb;

	i = -1;
	if (str[0] != ' ')
		return (-1);
	while (str[++i])
	{
		if (str[i] == ' ' && i != 0)
			return (-1);
		if ((str[i] < 48 || str[i] > 57) && str[i] != '.' && str[i] != ' ' \
		&& str[i] != '-')
			return (-1);
		if (str[i] == '-' && i != 1)
			return (-1);
	}
	if (!(nb = ft_strsub(str, 1, ft_strlen(str) - 1)))
		return (-1);
	if (check_data_light_fh(e, nb) == -1)
		return (-1);
	ft_strdel(&nb);
	return (0);
}

int		check_data_light_sd(t_stuff *e, char *str)
{
	int		i;
	int		nbequal;
	int		nbdot;

	i = -1;
	nbequal = 0;
	nbdot = 0;
	while (str[++i])
	{
		if (str[i] == '=')
		{
			e->d.equal = i;
			nbequal++;
		}
		if (str[i] == '.')
			nbdot++;
	}
	if (nbequal != 1)
		return (-1);
	if (nbdot != 1)
		return (-1);
	return (0);
}

int		check_data_light(t_stuff *e, int y)
{
	int		tmp;
	char	*str;
	int		i;

	tmp = y - 1;
	i = 0;
	while (++tmp < y + 9)
	{
		if (check_data_light_sd(e, e->b.tab[tmp]) == -1)
			return (-1);
		if (!(str = ft_strsub(e->b.tab[tmp], 0, e->d.equal + 1)))
			return (-1);
		if (ft_compare_light(str, i) == -1)
			return (-1);
		ft_strdel(&str);
		if (!(str = ft_strsub(e->b.tab[tmp], e->d.equal + 1, \
			ft_strlen(e->b.tab[tmp]) - e->d.equal)))
			return (-1);
		if (check_data_light_td(e, str) == -1)
			return (-1);
		i++;
		ft_strdel(&str);
	}
	e->d.i = -1;
	return (0);
}
