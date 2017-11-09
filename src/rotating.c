/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:03:28 by amansour          #+#    #+#             */
/*   Updated: 2017/11/09 12:00:06 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_result(t_env *env)
{
	int		i;
	double	x;
	double	y;

	if (!env->p)
	{
		if (env->zpt)
			env->p = dupp(env->zpt, env);
		else
			env->p = dupp(env->pt, env);
	}
	i = env->nbrx * env->nbry;
	while (--i >= 0)
	{
		x = env->p[i].x;
		y = env->p[i].y;
		env->p[i].x  = x * cos(R) - y * sin(R);
		env->p[i].y  = x * sin(R) + y * cos(R);
		(env->min_x > env->p[i].x) ?
		env->min_x = env->p[i].x : 0;
		(env->min_y > env->p[i].y) ?
		env->min_y = env->p[i].y : 0; 
	}
	decale(&(env->p), env);
}

int			rotate(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
    rotate_result(env);
    draw(env);
	return (0);
}

