/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 22:17:03 by jgaillar          #+#    #+#             */
/*   Updated: 2017/11/30 09:32:28 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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

static void		ft_usage(t_stuff *e)
{
	ft_putendl("Usage: ./rtv1 <map>");
	ft_exit(0, e);
}

int				main(int ac, char **av)
{
	t_stuff e;

	if (ac != 2 || !av[1])
		ft_usage(&e);
	// if ((e.fd = open(av[1], O_RDONLY)) < 0)
	// 	ft_exit(-1, &e);
	e.img.mlx_ptr = mlx_init();
	e.img.win_ptr = mlx_new_window(e.img.mlx_ptr, WIDTH, LENGTH,\
			"RTv1");
	// e.buf[read(e.fd, e.buf, BUFF_SIZE)] = '\0';
	// close(e.fd);
	init_struct(&e);
	aff(&e);
	mlx_hook(e.img.win_ptr, 2, (1L << 0), hooks, &e);
	mlx_hook(e.img.win_ptr, 17, (1L << 17), (int(*)())cleanexit, &e);
	mlx_loop(e.img.mlx_ptr);
	return (0);
}
