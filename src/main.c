/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 10:14:47 by amansour          #+#    #+#             */
/*   Updated: 2017/11/06 13:42:26 by amansour         ###   ########.fr       */
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
	env.mlx = mlx_init();
	if (env.max_x < 250 && env.max_y < 250)
      zoom(&(env.pt), 2, &env);
    decale(&point, env);
	define_dim(&env);
	env.win = mlx_new_window(env.mlx, env.width, env.height, av[1]);
	trace(env);
	mlx_loop(env.mlx); 
    return (0);
}
