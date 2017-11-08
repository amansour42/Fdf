/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 10:14:47 by amansour          #+#    #+#             */
/*   Updated: 2017/11/08 14:43:53 by amansour         ###   ########.fr       */
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
	if (!(env.pt = collect(fd, &env, av[1])))
		error(PARSEERROR);
	//display_point(env.pt, 10);
	env.mlx = mlx_init();
	decale(&(env.pt), env);
	if (env.max_x < 250 && env.max_y < 250)
		right_zoom(env.pt, 1, &env);
	define_dim(&env, av[1]);
	//display_point(env.zpt, 10);
	draw(&env);
	//mlx_loop_hook(env.mlx, draw, &env);
	//mlx_hook(env.win, 17, (1L << 17), quit, &env);
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
