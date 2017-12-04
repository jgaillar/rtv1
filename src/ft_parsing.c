/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:00:46 by prossi            #+#    #+#             */
/*   Updated: 2017/12/01 12:28:20 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_set_value(t_stuff *e)
{
	e->poscam.x = e->b.tabd[0];
	e->poscam.y = e->b.tabd[1];
	e->poscam.z = e->b.tabd[2];
	e->pr.x = e->b.tabd[3];
	e->pr.y = e->b.tabd[4];
	e->pr.z = e->b.tabd[5];
	e->vech.x = e->b.tabd[6];
	e->vech.y = e->b.tabd[7];
	e->vech.z = e->b.tabd[8];
	free(e->b.tabd);
	return (0);
}

int		ft_parsing(t_stuff *e)
{
	if (!(e->b.tab = ft_strsplit(e->b.buf, '\n')))
		return (-1);
	while (e->b.tab[++e->b.y])
		;
	if (e->b.y != 9)
		return (-1);
	// NE PAS OUBLIER DE MODIFIER LA VALEUR 9 SI SCENE NECESSITE PLUS DE 9 VALEUR
	if (ft_check(e) == -1)
		return (-1);
	ft_set_value(e);
	return (0);
}
