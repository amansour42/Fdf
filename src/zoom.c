/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:00:03 by amansour          #+#    #+#             */
/*   Updated: 2017/11/09 12:01:06 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom_result(t_env *env)
{
	int		i;

	if (!env->p && env->zpt)
		env->p = dupp(env->pt, env);
	else if (!env->p && env->pt)
		env->p = dupp(env->pt, env);
	i = NBR;
	while (--i >= 0)
	{
		if (env->z > 0)
		{
			env->p[i].x *= 2;
			env->p[i].y *= 2;
		}
		else
		{
			env->p[i].x /= 2;
			env->p[i].y /= 2;
		}
	}
}

void	right_zoom(t_point *pt, int n, t_env *env)
{
	int     i;
	t_point max;
	t_point min;

	i = env->nbrx * env->nbry; 
	if (!(env->zpt = (t_point*)malloc(sizeof(t_point) * i)))
		return ;
	max.x = 0;
	max.y = 0;
	min.x = 0;
	min.y = 0;
	while (--i >= 0)
	{
		env->zpt[i].x = pt[i].x * n;
		env->zpt[i].y = pt[i].y * n;
		env->zpt[i].c = pt[i].c;
		(max.x < env->zpt[i].x) ? max.x = env->zpt[i].x : 0;
		(max.y < env->zpt[i].y) ? max.y = env->zpt[i].y : 0;
		(min.x > env->zpt[i].x) ? min.x = env->zpt[i].x : 0;
		(min.y > env->zpt[i].y) ? min.y = env->zpt[i].y : 0;
	}
	if ((max.y - min.y) < 400 && (max.x-min.x) < 600)
	{
		free(env->zpt);
		env->zpt = NULL;
		right_zoom(pt, n + 1, env);
	}
	env->min_x = min.x;
	env->min_y = min.y;
	env->max_x = max.x;
	env->max_y = max.y;
	decale(&(env->zpt), env);
}

int			zoom(int keycode, t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 24)//+
		env->z = 1;
	else if (keycode == 27) //-
		env->z = -1;
	zoom_result(env);
	draw(env);
	return (0);
}
