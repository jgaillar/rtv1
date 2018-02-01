/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 23:46:25 by prossi            #+#    #+#             */
/*   Updated: 2018/02/01 18:32:01 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rtv1.h"

void	ft_arc(t_stuff *e, int option)
{
	int		x;
	int		y;
	int		d;

	x = 0;
	y = e->bs.ray_arc;
	d = 5 - (4 * e->bs.ray_arc);
	while (x <= y)
	{
		// DEMI CERCLE DROITE
		if (option == 1)
		{
			pixel_put_to_img(&e->i.mlx, x + e->bs.x_arc, y + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, y + e->bs.x_arc, x + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, x + e->bs.x_arc, -y + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, y + e->bs.x_arc, -x + e->bs.y_arc, e->lt.couleur);
		}
		// DEMI CERCLE GAUCHE
		else if (option == 2)
		{
			pixel_put_to_img(&e->i.mlx, -x + e->bs.x_arc, y + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, -y + e->bs.x_arc, x + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, -x + e->bs.x_arc, -y + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, -y + e->bs.x_arc, -x + e->bs.y_arc, e->lt.couleur);
		}
		// DEMI CERCLE HAUT
		else if (option == 3)
		{
			pixel_put_to_img(&e->i.mlx, x + e->bs.x_arc, -y + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, y + e->bs.x_arc, -x + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, -x + e->bs.x_arc, -y + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, -y + e->bs.x_arc, -x + e->bs.y_arc, e->lt.couleur);
		}
		// DEMI CERCLE BAS
		else if (option == 4)
		{
			pixel_put_to_img(&e->i.mlx, x + e->bs.x_arc, y + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, y + e->bs.x_arc, x + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, -x + e->bs.x_arc, y + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, -y + e->bs.x_arc, x + e->bs.y_arc, e->lt.couleur);
		}
		// QUART BAS GAUCHE
		else if (option == 5)
		{
			pixel_put_to_img(&e->i.mlx, -x + e->bs.x_arc, y + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, -y + e->bs.x_arc, x + e->bs.y_arc, e->lt.couleur);
		}
		// QUART BAS DROITE
		else if (option == 6)
		{
			pixel_put_to_img(&e->i.mlx, x + e->bs.x_arc, y + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, y + e->bs.x_arc, x + e->bs.y_arc, e->lt.couleur);
		}
		// QUART HAUT GAUCHE
		else if (option == 7)
		{
			pixel_put_to_img(&e->i.mlx, -x + e->bs.x_arc, -y + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, -y + e->bs.x_arc, -x + e->bs.y_arc, e->lt.couleur);
		}
		// QUART HAUT DROIT
		else if (option == 8)
		{
			pixel_put_to_img(&e->i.mlx, -x + e->bs.x_arc, -y + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, -y + e->bs.x_arc, -x + e->bs.y_arc, e->lt.couleur);
		}
		// CERCLE ENTIER
		else if (option == 9)
		{
			pixel_put_to_img(&e->i.mlx, x + e->bs.x_arc, y + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, y + e->bs.x_arc, x + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, x + e->bs.x_arc, -y + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, y + e->bs.x_arc, -x + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, -x + e->bs.x_arc, y + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, -y + e->bs.x_arc, x + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, -x + e->bs.x_arc, -y + e->bs.y_arc, e->lt.couleur);
			pixel_put_to_img(&e->i.mlx, -y + e->bs.x_arc, -x + e->bs.y_arc, e->lt.couleur);
		}
		if (d > 0)
		{
			y--;
			d -= 8 * y;
		}
		x++;
		d += 8 * x + 4;
	}
}
