/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 10:47:04 by jgaillar          #+#    #+#             */
/*   Updated: 2018/02/02 23:40:35 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	choose_sujet(t_stuff *e)
{
	e->c.obj = e->i.objet;
	if (e->c.obj == SPHERE)
	{
		searchlist(e, e->c.objsph, SPHERE);
		matrice(e->m.type, e->m.axe, e, &e->sph->pos);
	}
	else if (e->c.obj == LIGHT)
	{
		searchlist(e, e->c.objlight, LIGHT);
		matrice(e->m.type, e->m.axe, e, &e->light->pos);
	}
	else if (e->c.obj == CYLINDRE)
	{
		searchlist(e, e->c.objcyl, CYLINDRE);
		if (e->m.type_sujet == 1)
			matrice(e->m.type, e->m.axe, e, &e->cyl->pos);
		else
			matrice(e->m.type, e->m.axe, e, &e->cyl->norm);
	}
	else if (e->c.obj == PLAN)
	{
		searchlist(e, e->c.objpla, PLAN);
		if (e->m.type_sujet == 1)
			matrice(e->m.type, e->m.axe, e, &e->pla->pos);
		else
			matrice(e->m.type, e->m.axe, e, &e->pla->norm);
	}
	else if (e->c.obj == CONE)
	{
		searchlist(e, e->c.objcone, CONE);
		if (e->m.type_sujet == 1)
			matrice(e->m.type, e->m.axe, e, &e->cone->pos);
		else
			matrice(e->m.type, e->m.axe, e, &e->cone->norm);
	}
	else if (e->c.obj == -1)
	{
		if (e->m.type_sujet == 1)
			matrice(e->m.type, e->m.axe, e, &e->poscam);
		else
			matrice(e->m.type, e->m.axe, e, &e->dircam);
	}
}

void	movement_matrice(int keycode, t_stuff *e)
{
	if (keycode == 17)
	{
		if (e->m.type == '\0' || e->m.type == 'r')
		{
			e->m.type = 't';
			printf("\nActivation translation\n");
		}
		else
		{
			e->m.type = '\0';
			printf("\nDesactivation translation\n");
		}
	}
	else if (keycode == 15)
	{
		if (e->m.type == '\0' || e->m.type == 't')
		{
			e->m.type = 'r';
			printf("\nActivation rotation\n");
		}
		else
		{
			e->m.type = '\0';
			printf("\nDesactivation rotation\n");
		}
	}
	else if (keycode == 7)
	{
		e->m.axe = 'x';
		printf("\nL'axe de la matrice est en x\n");
	}
	else if (keycode == 16)
	{
		e->m.axe = 'y';
		printf("\nL'axe de la matrice est en y\n");
	}
	else if (keycode == 6)
	{
		e->m.axe = 'z';
		printf("\nL'axe de la matrice est en z\n");
	}
	else if (keycode == 8)
	{
		if (e->m.type_sujet == 0)
		{
			e->m.type_sujet = 1;
			printf("\nLa matrice s'effectuera sur la pos. de l'objet\n");
		}
		else if (e->m.type_sujet == 1)
		{
			e->m.type_sujet = 2;
			printf("\nLa matrice s'effectuera sur la direction de l'objet\n");
		}
		else if (e->m.type_sujet == 2)
		{
			e->m.type_sujet = 0;
			printf("\nAucun type de sujet selectionné\n");
		}
	}
	if (keycode == 36 && e->m.type != '\0' && e->m.axe != '\0' && e->m.type_sujet != 0)
		choose_sujet(e);
}

int		hooks(int keycode, t_stuff *e)
{
	movement_matrice(keycode, e);
	echap(keycode, e);
	movement(keycode, e);
	aff(e);
	return (0);
}

void	echap(int keycode, t_stuff *e)
{
	if (keycode == 53)
    {
		free(e->img.data);
		mlx_destroy_image(e->img.mlx_ptr, e->img.win_ptr);
		exit(0);
    }
}

void	cleanexit(t_stuff *e)
{
	free(e->img.data);
	mlx_destroy_image(e->img.mlx_ptr, e->img.win_ptr);
	exit(0);
}

void	movement(int keycode, t_stuff *e)
{
	if (keycode == 2)
	{
 		e->poscam.y -= 0.5;
		vectorcalc(e);
	}
 	if (keycode == 0)
	{
 		e->poscam.y += 0.5;
		vectorcalc(e);
	}
 	if (keycode == 1)
	{
 		e->poscam.x -= 0.5;
		vectorcalc(e);
	}
 	if (keycode == 13)
	{
 		e->poscam.x += 0.5;
		vectorcalc(e);
	}
 	if (keycode == 49)
	{
 		e->poscam.z += 0.5;
		vectorcalc(e);
	}
	// if (keycode == 8)
	// {
	// 	e->poscam.z -= 0.5;
	// 	vectorcalc(e);
	// }
	if (keycode == 125)
	{
		e->pr.x -= 0.5;
		vectorcalc(e);
	}
	if (keycode == 126)
	{
		e->pr.x += 0.5;
		vectorcalc(e);
	}
	if (keycode == 123)
	{
		e->pr.y += 0.5;
		vectorcalc(e);
	}
	if (keycode == 124)
	{
		e->pr.y -= 0.5;
		vectorcalc(e);
	}
	if (keycode == 78)
	{
		e->pr.z -= 0.5;
		vectorcalc(e);
	}
	if (keycode == 69)
	{
		e->pr.z += 0.5;
		vectorcalc(e);
	}
	if (keycode == 43 && e->pix - 2 >= 0)
		e->pix -= 2;
	if (keycode == 47 && e->pix + 2 < 20)
		e->pix += 2;
}
