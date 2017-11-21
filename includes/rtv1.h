/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:06:29 by jgaillar          #+#    #+#             */
/*   Updated: 2017/11/21 09:49:41 by jgaillar         ###   ########.fr       */
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

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_vec
{
	double 			x;
	double 			y;
	double 			z;
	double 			length;
}					t_vec;

typedef	struct		s_rt
{
	double			dist;
	double			xindent;
	double			yindent;
	int				obj;
	t_rgb			color;
	double			colorf;
	t_vec			inter;
}					t_rt;

typedef struct		s_sphere
{
	t_vec			poss;
	double			rayon;
	t_rgb			color;
	double			det;
	double			t1;
	double			t2;
	double			t;
	t_vec			normsphere;
}					t_sphere;

typedef struct		s_plan
{
	t_vec			normp;
	t_vec			plan;
	t_rgb			color;
	double			t;
}					t_plan;

typedef struct		s_cylindre
{
	double			normx;
	double			normy;
	double			normz;
	double			axex;
	double			axey;
	double			axez;
	double			rayon;
	t_rgb			color;
}					t_cylindre;

typedef struct		s_light
{
	t_vec			posl;
	t_vec			lightdir;
	t_rgb			color;
	double			amb;
	double			diff;
}					t_light;

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
	t_plan			plan;
	t_rt			rt;
	t_light			light;
	double			distvue;
	double			longvue;
	double			largvue;
	int				fd;
	char			buf[BUFF_SIZE + 1];
}					t_stuff;

double		getlight(t_vec *norm, t_rt *rt, t_light *light, t_rgb *colorobj);
void				ft_exit(int code, t_stuff *e);
void				init_struct(t_stuff *e);
void				create_image(t_stuff *e);
void				aff(t_stuff *e);
void				vecsous(t_vec *res, t_vec *i, t_vec *j);
void				vecadd(t_vec *res, t_vec *i, t_vec *j);
double				dot_product(t_vec *i, t_vec *j);
void				cross_product(t_vec *res, t_vec *i, t_vec *j);
void				vecpuivec(t_vec *res, t_vec *i, t_vec *j);
void				upleft(t_stuff *e);
void				raydir(t_stuff *e, double x, double y);
void				checksphere(t_sphere *sphere, t_vec *raydir, t_vec *poscam);
void				checkplan(t_plan *plan, t_vec *raydir, t_vec *poscam);
void				mlx_pixel_put_to_image(t_img img, int x, int y, int color);
int					hooks(int keycode, t_stuff *e);
void				echap(int keycode, t_stuff *e);
void				cleanexit(t_stuff *e);
void				vecnorm(t_vec *i);
void				veclength(t_vec *i);
void				getintersection(t_vec *poscam, t_vec *raydir, double dist, \
					t_rt *rt);
void				movement(int keycode, t_stuff *e);
void				raythingy(t_stuff *e, double x, double y);
double				rgbtohexa(int r, int g, int b);

#endif
