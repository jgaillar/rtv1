/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_sd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:11:09 by prossi            #+#    #+#             */
/*   Updated: 2017/12/01 12:16:28 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_parsing_sd(t_stuff *e)
{
	int		i;

	i = 0;
	if (!(e->b.tab = ft_strsplit(e->b.buf, '\n')))
		return (-1);
	if ((e->d.nbl = ft_counttabchar(e->b.tab)) == -1)
		return (-1);
	if (check_format(e) == -1)
		return (-1);
	return (0);
}
