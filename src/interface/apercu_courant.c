/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apercu_courant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 18:10:46 by prossi            #+#    #+#             */
/*   Updated: 2018/02/05 07:56:00 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void	fill_value_apercu(t_stuff *e)
{
	if (e->i.objet == -1)
	{
		e->i.mlx->data.pos = e->poscam;
		e->i.mlx->data.dir = e->dircam;
	}
	else if (e->i.objet == SPHERE)
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
	else if (e->i.objet == LIGHT)
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
	else if (e->i.objet == CYLINDRE)
	{
		e->i.mlx->data.pos = e->cyl->pos;
		e->i.mlx->data.dir = e->cyl->norm;
		e->i.mlx->data.color = e->cyl->color;
		e->i.mlx->data.text = e->cyl->text;
		e->i.mlx->data.ray = e->cyl->ray;
		//DONT FORGET MATERIAUX
	}
	else if (e->i.objet == PLAN)
	{
		e->i.mlx->data.pos = e->pla->pos;
		e->i.mlx->data.dir = e->pla->norm;
		e->i.mlx->data.color = e->pla->color;
		e->i.mlx->data.text = e->pla->text;
		e->i.mlx->data.ray = 0;
		//DONT FORGET MATERIAUX
	}
	else if (e->i.objet == CONE)
	{
		e->i.mlx->data.pos = e->cone->pos;
		e->i.mlx->data.dir = e->cone->norm;
		e->i.mlx->data.color = e->cone->color;
		e->i.mlx->data.text = e->cone->text;
		e->i.mlx->data.ray = 0;
		//DONT FORGET MATERIAUX
	}
}

void	get_value_apercu(t_stuff *e)
{
	reboot_list_loop(e, 3);
	if (e->i.objet == SPHERE)
		searchlist(e, e->i.each_obj, SPHERE);
	else if (e->i.objet == LIGHT)
		searchlist(e, e->i.each_obj, LIGHT);
	else if (e->i.objet == CYLINDRE)
		searchlist(e, e->i.each_obj, CYLINDRE);
	else if (e->i.objet == PLAN)
		searchlist(e, e->i.each_obj, PLAN);
	else if (e->i.objet == CONE)
		searchlist(e, e->i.each_obj, CONE);
	fill_value_apercu(e);
}

void	upleft_apercu(t_stuff *e)
{
	t_vec tmp;
	t_vec tmp2;
	t_vec tmp3;
	t_vec o;

	o.x = 0;
	o.y = 0;
	o.z = 0;
	tmp.x = e->c.distvue * e->i.dircam.x;
	tmp.y = e->c.distvue * e->i.dircam.y;
	tmp.z = e->c.distvue * e->i.dircam.z;
	tmp2.x = (e->c.longvue / 2) * e->vech.x;
	tmp2.y = (e->c.longvue / 2) * e->vech.y;
	tmp2.z = (e->c.longvue / 2) * e->vech.z;
	tmp3.x = (e->c.largvue / 2) * e->i.vecdroit.x;
	tmp3.y = (e->c.largvue / 2) * e->i.vecdroit.y;
	tmp3.z = (e->c.largvue / 2) * e->i.vecdroit.z;
	vecadd(&e->i.upleft, &o, &tmp);
	vecadd(&e->i.upleft, &e->i.upleft, &tmp2);
	vecsous(&e->i.upleft, &e->i.upleft, &tmp3);
	vecnorm(&e->i.upleft);
}

void	vectorcalc_apercu(t_stuff *e)
{
	e->i.poscam.x = e->i.mlx->data.pos.x - 20;
	e->i.poscam.y = e->i.mlx->data.pos.y;
	e->i.poscam.z = e->i.mlx->data.pos.z;
	e->i.preg.x = e->i.mlx->data.pos.x;
	e->i.preg.y = e->i.mlx->data.pos.y;
	e->i.preg.z = e->i.mlx->data.pos.z;
	vecsous(&e->i.dircam, &e->i.preg, &e->i.poscam);
	vecnorm(&e->i.dircam);
	cross_product(&e->i.vecdroit, &e->i.dircam, &e->vech);
	vecnorm(&e->i.vecdroit);
	upleft_apercu(e);
}

void		raydir_apercu(t_stuff *e, int x, int y)
{
	t_vec	tmp;
	t_vec	tmp2;

	e->c.xindent = e->c.largvue / e->i.mlx->img_x * x;
	e->c.yindent = e->c.longvue / e->i.mlx->img_y * y;
	tmp.x = e->i.vecdroit.x * e->c.xindent;
	tmp.y = e->i.vecdroit.y * e->c.xindent;
	tmp.z = e->i.vecdroit.z * e->c.xindent;
	tmp2.x = e->vech.x * e->c.yindent;
	tmp2.y = e->vech.y * e->c.yindent;
	tmp2.z = e->vech.z * e->c.yindent;
	vecadd(&e->raydir, &e->i.upleft, &tmp);
	vecsous(&e->raydir, &e->raydir, &tmp2);
	vecnorm(&e->raydir);
}

void		aff_apercu(t_stuff *e)
{
	double color;
	t_vec	tmp_poscam;

	vectorcalc_apercu(e);
	tmp_poscam = e->poscam;
	e->c.posy = -1;
	while (++e->c.posy < e->i.mlx->img_y)
	{
		e->c.posx = -1;
		while (++e->c.posx < e->i.mlx->img_x)
		{
			reboot_list_loop(e, 3);
			raydir_apercu(e, e->c.posx, e->c.posy);
			e->poscam = e->i.poscam;
			raythingy(e);
			color = rgbtohexa(e->c.colorf.r, e->c.colorf.g, e->c.colorf.b);
			pixel_put_to_img(&e->i.mlx, e->c.posx, e->c.posy, color);
		}
	}
	reboot_list_loop(e, 3);
	// e->c.obj = -1;
	e->poscam = tmp_poscam;
}

void	apercu_courant(t_stuff *e)
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
		searchlist_interface(e, 1);
	}
	// cadre_apercu(e);
	get_value_apercu(e);
	aff_apercu(e);
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->i.mlx->img, 0, WIN_Y - LENGTH);
}
