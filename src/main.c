/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 22:17:03 by jgaillar          #+#    #+#             */
/*   Updated: 2018/02/05 08:22:24 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_affich(t_stuff *e, int option)
{
	(void)e;
	if (option == 0)
	{
		ft_putstr("usage : ./rtv1 scene/camera scene/objets\n");
		ft_putstr("---> run ./rtv1 scene/exemple_camera scene/exemple_objets");
		ft_putstr("  to know how to set values\n");
	}
	if (option == 1)
		ft_putstr("\nError in Open or Read functions (scene/Camera)\n\n");
	if (option == 2)
		ft_putstr("\nError in Parsing function (scene/camera)\n\n");
	if (option == 3)
		ft_putstr("\nError in Open or Read functions (scene/objets)\n\n");
	if (option == 4)
		ft_putstr("\nError in Parsing function (scene/objets)");
	ft_exit (option, e);
}

int		ft_open(t_stuff *e, char *argv)
{
	if ((e->b.fd = open(argv, O_RDONLY)) < 0)
		return (-1);
	e->b.buf[read(e->b.fd, e->b.buf, BUFF_SIZE)] = '\0';
	close(e->b.fd);
	return (0);
}

void			ft_exit(int code, t_stuff *e)
{
	int i;
	i = -1;
	if (e->img.data)
		free(e->img.data);
	ft_putstr("Error happened: ");
	ft_putnbr(code);
	ft_putendl("\nExiting.");
	exit(code);
}

int		main_sd(t_stuff *e, char **argv)
{
	if (ft_open(e, argv[2]) == -1)
		ft_affich(e, 3);
	ft_init_struct(e, 1);
	if (ft_parsing_sd(e) == -1)
		ft_affich(e, 4);
	ft_init_struct(e, 2);
	vectorcalc(e);
	return (0);
}

//			DON'T TOUCH

// void			color_window(t_stuff *e)
// {
// 	int		x;
// 	int		y;
//
// 	y = -1;
// 	while (++y < WIN_Y)
// 	{
// 		x = -1;
// 		while (++x < WIN_X)
// 		{
// 			mlx_pixel_put(e->img.mlx_ptr, e->img.win_ptr, x, y, 0x6C0277);
// 		}
// 	}
// }

int				main(int ac, char **av)
{
	t_stuff e;

	if (ac != 3 || !av[1] || !av[2])
		ft_affich(&e, 0);
	if (ft_open(&e, av[1]) == -1)
		ft_affich(&e, 1);
	ft_init_struct(&e, 0);
	if (ft_parsing(&e) == -1)
		ft_affich(&e, 2);
	main_sd(&e, av);
	e.img.mlx_ptr = mlx_init();
	// DON'T TOUCH
	// e.img.win_ptr = mlx_new_window(e.img.mlx_ptr, WIN_X, WIN_Y,\
	// 		"Raytracer");
	e.img.win_ptr = mlx_new_window(e.img.mlx_ptr, WIDTH, LENGTH,\
			"Raytracer");
	// DON'T TOUCH
	// color_window(&e);
	create_image(&e);
	aff(&e);
	mlx_hook(e.img.win_ptr, 2, (1L << 0), hooks, &e);
	mlx_hook(e.img.win_ptr, 17, (1L << 17), (int(*)())cleanexit, &e);
	mlx_hook(e.img.win_ptr, 4, (1L << 2), mouse_hook, &e);
	mlx_loop(e.img.mlx_ptr);
	return (0);
}
