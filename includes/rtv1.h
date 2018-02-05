/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:06:29 by jgaillar          #+#    #+#             */
/*   Updated: 2018/02/05 08:13:11 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H

# define RTV1_H
# define WIDTH 1280
# define LENGTH 720
# define MT 16
# define BUFF_SIZE 0xfffff
# define SPHERE 0
# define PLAN 1
# define CYLINDRE 2
# define CONE 3
# define LIGHT 4
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
// Define de la taille de la fenetre avec interface
# define WIN_X 1800
# define WIN_Y 1000

typedef struct		s_vec
{
	double 			x;
	double 			y;
	double 			z;
	double 			length;
}					t_vec;

typedef struct	s_mat   // Structure matrice
{
	double		angle;   // Angle de rotation en degre
	double		radian;  // Angle en radian ---> obvious no ?
	double		value;  // Valeur de la translation
	char		type;  // 'r' rotation / 't' translation
	char		axe; // Axe de rotation x, y ou z
	int			type_sujet;  // 1 : pos obj // 2 : direction de l obj
}				t_mat;

typedef struct	s_seg
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_seg;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_d
{
	int				nbmsph;
	int				nbmpla;
	int				nbmlight;
	int				nbmcyl;
	int				nbmcone;
	int				nbl;
	int				equal;
	int				dot;
	int				i;
	double			*tabd;
	double			*tabdpla;
	double			*tabdlight;
	double			*tabdcyl;
	double			*tabdcone;
	t_rgb			color;
	t_rgb			colsph;
	t_rgb			colpla;
	t_rgb			colcyl;
	t_rgb			colcone;
}					t_d;

typedef struct		s_c
{
	double			distvue;
	double			longvue;
	double			largvue;
	int				posx;
	int				posy;
	double			xindent;
	double			yindent;
	int				i;
	int				n;
	double			dist;
	double			distsph;
	double			distpla;
	double			distcyl;
	double			distcone;
	double			distlight;
	int				obj;
	int				objsph;
	int				objpla;
	int				objcyl;
	int				objcone;
	int				objlight;
	t_rgb			colorf;
	t_vec			inter;

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

typedef struct		s_texture
{
	t_rgb			c1;
	t_rgb			c2;
	t_rgb			c3;
}					t_texture;

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
	t_texture		text;
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
	t_texture		text;
	double			t;
	int				nm;
	struct s_plan	*next;
}					t_plan;

typedef struct		s_cyl
{
	struct s_cyl	*prev;
	t_vec			norm;
	t_vec			norml;
	t_vec			pos;
	double			ray;
	t_rgb			color;
	t_texture		text;
	double			t1;
	double			t2;
	double			t;
	double			det;
	int				nm;
	struct s_cyl	*next;
}					t_cyl;

typedef struct		s_cone
{
	struct s_cone	*prev;
	t_vec			norm;
	t_vec			norml;
	t_vec			pos;
	t_rgb			color;
	t_texture		text;
	double			angle;
	double			t1;
	double			t2;
	double			t;
	double			det;
	int				nm;
	struct s_cone	*next;
}					t_cone;

typedef struct		s_light
{
	struct s_light	*prev;
	t_vec			pos;
	t_vec			norm;
	t_vec			lightdir;
	t_rgb			color;
	t_texture		text;
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

typedef struct		s_data
{
	t_vec			pos;
	t_vec			dir;
	t_rgb			color;
	t_texture		text;
	double			ray;
}					t_data;

typedef struct		s_mlx
{
	struct s_mlx	*prev;
	void			*img;
	char			*map;
	int				bpp;
	int				size_line;
	int				endian;
	int				nmail;
	double			img_x;
	double			img_y;
	t_data			data;
	struct s_mlx	*next;
}					t_mlx;

typedef	struct		s_ntmgtk
{
	int				nb_img;
	t_mlx			*mlx;
	t_mlx			*tmp_mlx;
	int				first;
	int				img_x;
	int				img_y;
	t_vec			poscam;
	t_vec			preg;
	t_vec			dircam;
	t_vec			vecdroit;
	t_vec			upleft;
	int				objet;
	int				each_obj;
	int				term;
}					t_ntmgtk;

typedef struct		s_letter
{
	char			charac;
	int				couleur;
	int				posx;
	int				posy;
	double			coeff;
	int				space;
}					t_letter;

typedef struct		s_bres
{
	int				dx;
	int				dy;
	int				xi;
	int				xf;
	int				yi;
	int				yf;
	int				cumul;
	int				xinc;
	int				yinc;
	int				ray_arc;
	int	 			x_arc;
	int				y_arc;
}					t_bres;

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
	t_sphere		*sph;
	t_sphere		*tmp;
	t_plan			*pla;
	t_plan			*tmppla;
	t_light			*light;
	t_light			*tmplight;
	t_cyl			*cyl;
	t_cyl			*tmpcyl;
	t_cone			*cone;
	t_cone			*tmpcone;
	t_seg			seg;
	int				pix;
	int				fd;
	char			buf[BUFF_SIZE + 1];
	int				l;
	t_mat			m;
	t_ntmgtk		i;
	t_letter		lt;
	t_bres			bs;
}					t_stuff;

void				vectorcalc(t_stuff *e);
void				reboot_list(t_stuff *e);
void				print_list(t_stuff *e);
void				reboot_list_loop(t_stuff *e, int option);
int					ft_check(t_stuff *e);
int					ft_parsing(t_stuff *e);
int					ft_parsing_sd(t_stuff *e);
int					ft_compare_camera(char *str, int i);
int					check_format(t_stuff *e);
int					check_data_sphere(t_stuff *e, int y);
int					ft_compare_sphere(char *str, int i);
int					init_list_sph(t_sphere **sph);
void				fill_list_sph(t_sphere **sph, double *tabd, int nbm);
int					check_data_plan(t_stuff *e, int y);
int					init_list_pla(t_plan **pla);
int					ft_compare_plan(char *str, int i);
void				fill_list_pla(t_plan **pla, double *tabdpla, int nbmpla);
int					ft_compare_light(char *str, int i);
int					check_data_light(t_stuff *e, int y);
int					init_list_light(t_light **light);
void				fill_list_light(t_light **light, double *tabdlight, int nbmlight);
int					init_list_cyl(t_cyl **cyl);
int					check_data_cylindre(t_stuff *e, int y);
void				fill_list_cyl(t_cyl **cyl, double *tabdcyl, int nbmcyl);
int					ft_compare_cylindre(char *str, int i);
t_rgb		getlight(t_vec *norm, t_light **light, t_rgb *colorobj, t_stuff *es);
void				ft_exit(int code, t_stuff *e);
void				ft_init_struct(t_stuff *e, int option);
void				create_image(t_stuff *e);
void				aff(t_stuff *e);
void				vecsous(t_vec *res, t_vec *i, t_vec *j);
void				vecadd(t_vec *res, t_vec *i, t_vec *j);
double				dot_product(t_vec *i, t_vec *j);
void				cross_product(t_vec *res, t_vec *i, t_vec *j);
void				vecpuivec(t_vec *res, t_vec *i, t_vec *j);
void				upleft(t_stuff *e);
void				raydir(t_stuff *e, int x, int y);
void				checksphere(t_sphere *sphere, t_vec *raydir, t_vec *poscam);
void				checkplan(t_plan *plan, t_vec *raydir, t_vec *poscam);
void				mlx_pixel_put_to_image(t_img img, int x, int y ,int color);
int					hooks(int keycode, t_stuff *e);
void				echap(int keycode, t_stuff *e);
void				cleanexit(t_stuff *e);
void				vecnorm(t_vec *i);
void				veclength(t_vec *i);
void				getintersection(t_stuff *e, double dist);
void				movement(int keycode, t_stuff *e);
int				raythingy(t_stuff *e);
double				rgbtohexa(int r, int g, int b);
void		checklight(t_light *light, t_vec *raydir, t_vec *poscam);
void		checkcyl(t_cyl *cyl, t_vec *raydir, t_vec *poscam);
void		checkcone(t_cone *cone, t_vec *raydir, t_vec *poscam);
int			cone(t_stuff *e, int y);
int			init_list_cone(t_cone **cone);
int		check_data_cone(t_stuff *e, int y);
void	fill_list_cone(t_cone **cone, double *tabdcone, int nbmcone);
int		ft_compare_cone(char *str, int i);
void	searchlist(t_stuff *e, int nmail, int nlist);
void		check_dist(t_stuff *e, int option);
void		check(t_stuff *e, t_vec *raydir, t_vec *pos, int option);
int		cylindre(t_stuff *e, int y);
int		light(t_stuff *e, int y);
int		plan(t_stuff *e, int y);
int		sphere(t_stuff *e, int y);
int		cone(t_stuff *e, int y);
int		ft_compare_cone_sd(char *str, int i);
double		shadows(t_stuff *e, t_vec *inter, t_rgb color);
int		mouse_hook(int button, int x, int y, t_stuff *e);
void			ft_segment(t_stuff *e, int x1, int y1, double color);
void			rgb_add(t_rgb *res, t_rgb i, t_rgb j, double k);
void		getlightdir(t_stuff *e, t_vec inter);
void		getspeclight(t_stuff *e, t_vec *norm, t_rgb *color, t_light **light);
t_vec		getrefray(t_stuff *e, t_vec *norm, t_vec *light);
void		oklm(t_stuff *e);
int		raythingydebug(t_stuff *e);
void	matrice(char type, char axe, t_stuff *e, t_vec *sujet);


//			INTERFACE

int				launch_interface(t_stuff *e);
void			pixel_put_to_img(t_mlx **mlx, int x, int y, int color);
int				new_img(t_stuff *e);
int				init_img(t_mlx **mlx);
void			fill_img(t_mlx **mlx, int nbmail, t_stuff *e);
void			objet_courant(t_stuff *e);
void			reboot_list_interface(t_stuff *e, int option);
void			searchlist_interface(t_stuff *e, int nmail);
void			apercu_courant(t_stuff *e);
void			fill_value_current(t_stuff *e);
void			get_value_current(t_stuff *e);
void			terminal(t_stuff *e);


//			LIB_LETTER

void				A(t_stuff *e);
void				B(t_stuff *e);
void				C(t_stuff *e);
void				D(t_stuff *e);
void				E(t_stuff *e);
void				F(t_stuff *e);
void				G(t_stuff *e);
void				H(t_stuff *e);
void				I(t_stuff *e);
void				J(t_stuff *e);
void				K(t_stuff *e);
void				L(t_stuff *e);
void				M(t_stuff *e);
void				N(t_stuff *e);
void				O(t_stuff *e);
void				P(t_stuff *e);
void				Q(t_stuff *e);
void				R(t_stuff *e);
void				S(t_stuff *e);
void				T(t_stuff *e);
void				U(t_stuff *e);
void				V(t_stuff *e);
void				W(t_stuff *e);
void				X(t_stuff *e);
void				Y(t_stuff *e);
void				Z(t_stuff *e);
void				ft_segment_letter(t_stuff *e);
void				ft_arc(t_stuff *e, int option);
void				awklm_string_put(char *str, t_stuff *e);
#endif
