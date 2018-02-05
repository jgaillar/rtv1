/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_courant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 22:13:22 by prossi            #+#    #+#             */
/*   Updated: 2018/02/05 08:07:17 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void	fill_value_current(t_stuff *e)
{
	if (e->c.obj == -1)
	{
		e->i.mlx->data.pos = e->poscam;
		e->i.mlx->data.dir = e->dircam;
	}
	else if (e->c.obj == SPHERE)
	{
		e->i.mlx->data.pos = e->sph->pos;
		e->i.mlx->data.dir.x = 0;
		e->i.mlx->data.dir.y = 0;
		e->i.mlx->data.dir.z = 0;
		e->i.mlx->data.color = e->sph->color;
		e->i.mlx->data.text = e->sph->text;
		e->i.mlx->data.ray = e->sph->ray;
		//DONT FORGET MATERIAUX
	}
	else if (e->c.obj == LIGHT)
	{
		e->i.mlx->data.pos = e->light->pos;
		e->i.mlx->data.dir.x = 0;
		e->i.mlx->data.dir.y = 0;
		e->i.mlx->data.dir.z = 0;
		e->i.mlx->data.color = e->light->color;
		e->i.mlx->data.text = e->light->text;
		e->i.mlx->data.ray = e->light->ray;
		//DONT FORGET MATERIAUX
	}
	else if (e->c.obj == CYLINDRE)
	{
		e->i.mlx->data.pos = e->cyl->pos;
		e->i.mlx->data.dir = e->cyl->norm;
		e->i.mlx->data.color = e->cyl->color;
		e->i.mlx->data.text = e->cyl->text;
		e->i.mlx->data.ray = e->cyl->ray;
		//DONT FORGET MATERIAUX
	}
	else if (e->c.obj == PLAN)
	{
		e->i.mlx->data.pos = e->pla->pos;
		e->i.mlx->data.dir = e->pla->norm;
		e->i.mlx->data.color = e->pla->color;
		e->i.mlx->data.text = e->pla->text;
		e->i.mlx->data.ray = 0;
		//DONT FORGET MATERIAUX
	}
	else if (e->c.obj == CONE)
	{
		e->i.mlx->data.pos = e->cone->pos;
		e->i.mlx->data.dir = e->cone->norm;
		e->i.mlx->data.color = e->cone->color;
		e->i.mlx->data.text = e->cone->text;
		e->i.mlx->data.ray = 0;
		//DONT FORGET MATERIAUX
	}
}

void	get_value_current(t_stuff *e)
{
	reboot_list_loop(e, 3);
	if (e->c.obj == SPHERE)
		searchlist(e, e->c.objsph, SPHERE);
	else if (e->c.obj == LIGHT)
		searchlist(e, e->c.objlight, LIGHT);
	else if (e->c.obj == CYLINDRE)
		searchlist(e, e->c.objcyl, CYLINDRE);
	else if (e->c.obj == PLAN)
		searchlist(e, e->c.objpla, PLAN);
	else if (e->c.obj == CONE)
		searchlist(e, e->c.objcone, CONE);
	fill_value_current(e);
}

void	cadre_current(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->i.mlx->img_y)
	{
		x = -1;
		while (++x < e->i.mlx->img_x)
		{
			//	COULEUR DE L IMAGE
			pixel_put_to_img(&e->i.mlx, x, y, 0x6C0277);
			// if (x == e->i.mlx->img_x - 1 || x == e->i.mlx->img_x - 2 || x == 0 || x == 1)
			// 	pixel_put_to_img(&e->i.mlx, x, y, 0x000000);
			// if (y == e->i.mlx->img_y - 1 || y == e->i.mlx->img_y - 2 || y == 0 || y == 1)
			// 	pixel_put_to_img(&e->i.mlx, x, y, 0x000000);
			if (((y == 5 || y == 6) && x >= 150 && x <= 370) || \
			((y == 60 || y == 61) && x >= 150 && x <= 370) || \
			(y >= 5 && y <= 60 && ((x == 150 || x == 151) || \
			(x == 369 || x == 370))))
				pixel_put_to_img(&e->i.mlx, x, y, 0x000000);
			if (y >= 7 && y <= 59 && x >= 152 && x <= 368)
				pixel_put_to_img(&e->i.mlx, x, y, 0x6A455D);
		}
	}
}

void	title_current(t_stuff *e)
{
	e->lt.posx = 200;
	e->lt.posy = 50;
	e->lt.coeff = 0.5;
	e->lt.couleur = 0x000000;
	e->lt.space = 40;
	if (e->c.obj == -1)
		awklm_string_put("CAMERA", e);
	if (e->c.obj == 0)
		awklm_string_put("SPHERE", e);
	if (e->c.obj == 1)
		awklm_string_put("PLAN", e);
	if (e->c.obj == 2)
	{
		e->lt.posx = 180;
		awklm_string_put("CYLINDRE", e);
	}
	if (e->c.obj == 3)
		awklm_string_put("CONE", e);
	if (e->c.obj == 4)
	{
		e->lt.posx = 210;
		awklm_string_put("LIGHT", e);
	}
}

void	draw_position_current(t_stuff *e)
{
	int		x;
	int		y;

	y = e->lt.posy - 30 - 1;
	while (++y < e->lt.posy + 10)
	{
		x = e->lt.posx - 10 - 1;
		while (++x < e->lt.posx + 110)
		{
			if (((y == e->lt.posy - 30 || y == e->lt.posy - 29 || y == e->lt.posy + 8 || y == e->lt.posy + 9) && x >= e->lt.posx - 10 && x <= e->lt.posx + 109))
				pixel_put_to_img(&e->i.mlx, x, y, 0x000000);
			else if (x == e->lt.posx - 10 || x == e->lt.posx - 9 || x == e->lt.posx + 109 || x == e->lt.posx + 108)
				pixel_put_to_img(&e->i.mlx, x, y, 0x000000);
			else
				pixel_put_to_img(&e->i.mlx, x, y, 0x6A455D);
		}
	}
}

void	position_current(t_stuff *e)
{
	e->lt.posx = 20;
	e->lt.posy = 105;
	e->lt.coeff = 0.3;
	e->lt.couleur = 0x000000;
	e->lt.space = 40;
	draw_position_current(e);
	awklm_string_put("POSITION", e);
	e->lt.posx = 150;
	draw_position_current(e);
	e->lt.posx = 275;
	draw_position_current(e);
	e->lt.posx = 400;
	draw_position_current(e);
}

void	direction_current(t_stuff *e)
{
	e->lt.posx = 20;
	e->lt.posy = 147;
	e->lt.coeff = 0.27;
	e->lt.couleur = 0x000000;
	e->lt.space = 40;
	draw_position_current(e);
	awklm_string_put("DIRECTION", e);
	e->lt.posx = 150;
	draw_position_current(e);
	e->lt.posx = 275;
	draw_position_current(e);
	e->lt.posx = 400;
	draw_position_current(e);
}

void	color_current(t_stuff *e)
{
	e->lt.posx = 20;
	e->lt.posy = 189;
	e->lt.coeff = 0.3;
	e->lt.couleur = 0x000000;
	e->lt.space = 40;
	draw_position_current(e);
	e->lt.posx = 25;
	awklm_string_put("COULEUR", e);
	e->lt.posx = 150;
	draw_position_current(e);
	e->lt.posx = 275;
	draw_position_current(e);
	e->lt.posx = 400;
	draw_position_current(e);
}

void	texture_current(t_stuff *e)
{
	e->lt.posx = 20;
	e->lt.posy = 231;
	e->lt.coeff = 0.27;
	e->lt.couleur = 0x000000;
	e->lt.space = 40;
	draw_position_current(e);
	e->lt.posx = 30;
	awklm_string_put("TEXTURE", e);
	e->lt.posx = 150;
	draw_position_current(e);
	e->lt.posx = 275;
	draw_position_current(e);
	e->lt.posx = 400;
	draw_position_current(e);
}

void	draw_ray_current(t_stuff *e)
{
	int		x;
	int		y;

	y = e->lt.posy - 30 - 1;
	while (++y < e->lt.posy)
	{
		x = e->lt.posx - 10 - 1;
		while (++x < e->lt.posx + 110)
		{
			if (((y == e->lt.posy - 30 || y == e->lt.posy - 29 || y == e->lt.posy - 2 || y == e->lt.posy - 1) && x >= e->lt.posx - 10 && x <= e->lt.posx + 109))
				pixel_put_to_img(&e->i.mlx, x, y, 0x000000);
			else if (x == e->lt.posx - 10 || x == e->lt.posx - 9 || x == e->lt.posx + 109 || x == e->lt.posx + 108)
				pixel_put_to_img(&e->i.mlx, x, y, 0x000000);
			else
				pixel_put_to_img(&e->i.mlx, x, y, 0x6A455D);
		}
	}
}

void	ray_current(t_stuff *e)
{
	e->lt.posx = 20;
	e->lt.posy = 273;
	e->lt.coeff = 0.24;
	e->lt.couleur = 0x000000;
	e->lt.space = 40;
	draw_ray_current(e);
	e->lt.posx = 275;
	draw_ray_current(e);
	e->lt.posx = 45;
	e->lt.posy = 268;
	awklm_string_put("RAYON", e);
}

void	string_put_current(t_stuff *e)
{
	char	*buf;

	buf = ft_strnew(50);
	//		POSITION OBJET
	sprintf(buf, "%.2f", e->i.mlx->data.pos.x);
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 166, 83, 0x000000, buf);
	sprintf(buf, "%.2f", e->i.mlx->data.pos.y);
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 291, 83, 0x000000, buf);
	sprintf(buf, "%.2f", e->i.mlx->data.pos.z);
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 416, 83, 0x000000, buf);
	//
	//		DIRECTION OBJET
	if (e->c.obj != 0 && e->c.obj != 4)
	{
		sprintf(buf, "%.2f", e->i.mlx->data.dir.x);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 166, 125, 0x000000, buf);
		sprintf(buf, "%.2f", e->i.mlx->data.dir.y);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 291, 125, 0x000000, buf);
		sprintf(buf, "%.2f", e->i.mlx->data.dir.z);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 416, 125, 0x000000, buf);
	}
	//
	//		COULEUR OBJET
	if (e->c.obj != -1)
	{
		sprintf(buf, "%d", e->i.mlx->data.color.r);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 190, 167, 0x000000, buf);
		sprintf(buf, "%d", e->i.mlx->data.color.g);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 315, 167, 0x000000, buf);
		sprintf(buf, "%d", e->i.mlx->data.color.b);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 440, 167, 0x000000, buf);
	}
	//
	//		TEXTURE OBJET
	if (e->c.obj != -1)
	{
		e->i.mlx->data.text.c1.r = 0;
		e->i.mlx->data.text.c1.g = 0;
		e->i.mlx->data.text.c1.b = 0;
		e->i.mlx->data.text.c2.r = 0;
		e->i.mlx->data.text.c2.g = 0;
		e->i.mlx->data.text.c2.b = 0;
		e->i.mlx->data.text.c3.r = 0;
		e->i.mlx->data.text.c3.g = 0;
		e->i.mlx->data.text.c3.b = 0;
		sprintf(buf, "%d", e->i.mlx->data.text.c1.r);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 150, 209, 0x000000, buf);
		sprintf(buf, "%d", e->i.mlx->data.text.c1.g);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 185, 209, 0x000000, buf);
		sprintf(buf, "%d", e->i.mlx->data.text.c1.b);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 220, 209, 0x000000, buf);
		sprintf(buf, "%d", e->i.mlx->data.text.c2.r);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 275, 209, 0x000000, buf);
		sprintf(buf, "%d", e->i.mlx->data.text.c2.g);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 310, 209, 0x000000, buf);
		sprintf(buf, "%d", e->i.mlx->data.text.c2.b);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 345, 209, 0x000000, buf);
		sprintf(buf, "%d", e->i.mlx->data.text.c3.r);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 400, 209, 0x000000, buf);
		sprintf(buf, "%d", e->i.mlx->data.text.c3.g);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 435, 209, 0x000000, buf);
		sprintf(buf, "%d", e->i.mlx->data.text.c3.b);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 470, 209, 0x000000, buf);
	}
	//
	//		RAYON OBJET
	if (e->c.obj == 0 || e->c.obj == 2 || e->c.obj == 4)
	{
		sprintf(buf, "%.2f", e->i.mlx->data.ray);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 291, 251, 0x000000, buf);
	}
	ft_strdel(&buf);
}

void	objet_courant(t_stuff *e)
{
	if (e->i.first == 0)
	{
		e->i.img_x = WIN_X - WIDTH;
		e->i.img_y = WIN_Y - LENGTH;
		new_img(e);
	}
	else
	{
		reboot_list_interface(e, 1);
		searchlist_interface(e, 0);
	}
	get_value_current(e);
	cadre_current(e);
	title_current(e);
	position_current(e);
	if (e->c.obj != 0 || e->c.obj != 4)
		direction_current(e);
	color_current(e);
	texture_current(e);
	ray_current(e);
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->i.mlx->img, 0, 0);
	string_put_current(e);
}
