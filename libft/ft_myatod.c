/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myatod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:35:27 by prossi            #+#    #+#             */
/*   Updated: 2017/12/01 12:20:08 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double		put_dot(int nb, int dot)
{
	double	new;
	int		i;

	i = 0;
	new = nb;
	while (i < dot)
	{
		new /= 10;
		i++;
	}
	return (new);
}

static int			dot_value(char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	while (i != 0)
	{
		if (str[i] == '.')
			break ;
		i--;
	}
	i = (ft_strlen(str) - 1) - i;
	return (i);
}

static char		*deletechar(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	if (!(tmp = ft_strnew(ft_strlen(str) - 1)))
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != '.')
		{
			tmp[j] = str[i];
			j++;
		}
	}
	return (tmp);
}

static int			checkchar(char *str)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if ((str[i] < 48 || str[i] > 57) && ((str[i] != '.') && str[i] != '-'))
			return (-1);
		if (str[i] == '.')
		{
			j++;
			if (j > 1 || i == 0)
				return (-1);
		}
		if (str[i] == '-')
			if (i != 0)
				return (-1);
	}
	if (j == 0 || (str[0] == '-' && i > 10) || (str[0] != '-' && i > 8))
		return (-1);
	return (0);
}

double		ft_myatod(char *str)
{
	char	*newstr;
	int		dot;
	int		nb;
	double	newnb;

	if (!str)
		return (2147483647);
	if (checkchar(str) == -1)
		return (2147483647);
	if (!(newstr = deletechar(str)))
		return (2147483647);
	dot = dot_value(str);
	nb = ft_atoi(newstr);
	newnb = put_dot(nb, dot);
	ft_strdel(&newstr);
	return (newnb);
}
