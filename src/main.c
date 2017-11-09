/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 10:14:47 by amansour          #+#    #+#             */
/*   Updated: 2017/11/09 11:51:20 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	int		fd;
	t_env	env;

	if (ac != 2)
		error(USAGE);
	if ((fd = ft_open(av[1])) == -1)
		error(READERROR);
	if (!checking(fd, &env))
		error(PARSEERROR);
	close(fd);
	fd = ft_open(av[1]);
	stocking(fd, &env);
	(!(env.pt)) ? error(PARSEERROR) : 0;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.width, env.height, av[1]);
	decale(&(env.pt), &env);
	if (env.max_x < 250 && env.max_y < 250)
		right_zoom(env.pt, 1, &env);
	draw(&env);
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
