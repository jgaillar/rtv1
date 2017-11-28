/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:06:29 by jgaillar          #+#    #+#             */
/*   Updated: 2017/11/28 15:47:41 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H

# define RTV1_H
# define WIDTH 1280
# define LENGTH 720
# define MT 16
# define BUFF_SIZE 0xfffff
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
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

typedef struct		s_d
{
	int				nbmsph;
	int				nbmpla;
	int				nbmlight;
	int				nbmcyl;
	int				nbl;
	int				equal;
	int				dot;
	int				i;
	double			*tabd;
	double			*tabdpla;
	double			*tabdlight;
	double			*tabdcyl;
}					t_d;

typedef struct		s_c
{
	double			distvue;
	double			longvue;
	double			largvue;
	int				posx;
	int				posy;
}					t_c;

typedef struct		s_b
{
	int				fd;
	char			buf[BUFF_SIZE + 1];
	char			**tab;
	char			*tmp;
	char			*tmp2;
	char			*tmp3;
	double			*tabd;
	int				i;
	int				y;
}					t_b;

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
	struct s_sphere	*prev;
	t_vec			pos;
	double			ray;
	t_rgb			color;
	double			det;
	double			t1;
	double			t2;
	double			t;
	t_vec			norm;
	int				nm;
	struct s_sphere	*next;
}					t_sphere;

typedef struct		s_plan
{
	struct s_plan	*prev;
	t_vec			norm;
	t_vec			norml;
	t_vec			pos;
	t_rgb			color;
	double			t;
	int				nm;
	struct s_plan	*next;
}					t_plan;

typedef struct		s_cyl
{
	struct s_cyl	*prev;
	t_vec			norm;
	t_vec			pos;
	double			ray;
	t_rgb			color;
	double			t1;
	double			t2;
	double			t;
	double			det;
	int				nm;
	struct s_cyl	*next;
}					t_cyl;

typedef struct		s_con
{
	struct s_cyl	*prev;
	t_vec			norm;
	t_vec			pos;
	t_rgb			color;
	double			t1;
	double			t2;
	double			t;
	double			det;
	int				nm;
	struct s_cyl	*next;
}					t_con;

typedef struct		s_light
{
	struct s_light	*prev;
	t_vec			pos;
	t_vec			norm;
	t_vec			lightdir;
	t_rgb			color;
	double			ray;
	double			det;
	double			t1;
	double			t2;
	double			t;
	double			amb;
	double			diff;
	int				nm;
	struct s_light	*next;
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
	t_b				b;
	t_c				c;
	t_d				d;
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
	t_cyl			cyl;
	t_con			con;
	pthread_t		*th;
	double			start;
	double			end;
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
void				raydir(t_stuff *e);
void				checksphere(t_sphere *sphere, t_vec *raydir, t_vec *poscam);
void				checkplan(t_plan *plan, t_vec *raydir, t_vec *poscam);
void				mlx_pixel_put_to_image(t_img img, int x, int y ,int color);
int					hooks(int keycode, t_stuff *e);
void				echap(int keycode, t_stuff *e);
void				cleanexit(t_stuff *e);
void				vecnorm(t_vec *i);
void				veclength(t_vec *i);
void				getintersection(t_vec *poscam, t_vec *raydir, double dist, \
					t_rt *rt);
void				movement(int keycode, t_stuff *e);
void				raythingy(t_stuff *e);
double				rgbtohexa(int r, int g, int b);
void		checklight(t_light *light, t_vec *raydir, t_vec *poscam);
void		checkcyl(t_cyl *cyl, t_vec *raydir, t_vec *poscam);
void		checkcone(t_con *con, t_vec *raydir, t_vec *poscam);

#endif
