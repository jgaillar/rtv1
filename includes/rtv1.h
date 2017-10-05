/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:06:29 by jgaillar          #+#    #+#             */
/*   Updated: 2017/10/03 14:06:30 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H

# define RTV1_H
# define WIDTH 1280
# define LENGTH 720
# define BUFF_SIZE 0xfffff
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>

typedef	struct		s_rt
{
	double			det;
	double			t;
	double			t1;
	double			t2;
}					t_rt;

typedef struct		s_sphere
{
	int 			cx;
	int				cy;
	int				cz;
	int				rayon;
	int				color;
}					t_sphere;

typedef struct		s_plan
{
	int				normx;
	int				normy;
	int				normz;
	int				planx;
	int				plany;
	int				planz;
	int				color;
}					t_plan;

typedef struct		s_cylindre
{
	int				normx;
	int				normy;
	int				normz;
	int				axex;
	int				axey;
	int				axez;
	int				rayon;
	int				color;
}					t_cylindre;

typedef struct		s_lumiere
{
	int				posx;
	int				posy;
	int				posz;
	int				color;
	double			coefdif;
}					s_lumiere;

typedef struct		s_vec
{
	int x;
	int y;
	int z;
}					t_vec;

typedef struct		s_img
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				size;
	char			*data;
}					t_img;

typedef	struct		s_stuff
{
	t_img			img;
	t_vec			poscam;
	t_vec			pr;
	t_vec			vech;
	t_vec			vecupleft;
	t_vec			vecdroit;
	t_vec			raydir;
	t_vec			dircam;
	t_sphere		sphere;
	t_rt			rt;
	double			distvue;
	double			longvue;
	double			largvue;
	int				fd;
	char			buf[BUFF_SIZE + 1];
}					t_stuff;

void				ft_exit(int code, t_stuff *e);
void				init_struct(t_stuff *e);
void				create_image(t_stuff *e);
void				raycast(t_stuff *e);
void				vecsous(t_vec *res, t_vec *i, t_vec *j);
void				vecadd(t_vec *res, t_vec *i, t_vec *j);
int					dot_product(t_vec *i, t_vec *j);
void				cross_product(t_vec *res, t_vec *i, t_vec *j);
void				vecpuivec(t_vec *res, t_vec *i, t_vec *j);
void				upleft(t_stuff *e);
void				raydir(t_stuff *e, int x, int y);
void				checksphere(t_stuff *e, int x, int y);
void				mlx_pixel_put_to_image(t_img img, int x, int y, int color);
int					hooks(int keycode, t_stuff *e);
void				echap(int keycode, t_stuff *e);
void				cleanexit(t_stuff *e);

#endif
