/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:00:03 by amansour          #+#    #+#             */
/*   Updated: 2017/11/09 12:16:29 by amansour         ###   ########.fr       */
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

static void	zoom_instr(t_env *env, int i, int n, t_limit *l)
{
		env->zpt[i].x = env->pt[i].x * n;
		env->zpt[i].y = env->pt[i].y * n;
		env->zpt[i].c = env->pt[i].c;
		((l->max).x < env->zpt[i].x) ? (l->max).x = env->zpt[i].x : 0;
		((l->max).y < env->zpt[i].y) ? (l->max).y = env->zpt[i].y : 0;
		((l->min).x > env->zpt[i].x) ? (l->min).x = env->zpt[i].x : 0;
		((l->min).y > env->zpt[i].y) ? (l->min).y = env->zpt[i].y : 0;
}

void	right_zoom(int n, t_env *env)
{
	int		i;
	t_limit	l;

	i = NBR;
	if (!(env->zpt = (t_point*)malloc(sizeof(t_point) * i)))
		return ;
	(l.max).x = 0;
	(l.max).y = 0;
	(l.min).x = 0;
	(l.min).y = 0;
	while (--i >= 0)
		zoom_instr(env, i, n, &l);
	if ((l.max).y - (l.min).y < 400 && ((l.max).x - (l.min).x) < 600)
	{
		free(env->zpt);
		env->zpt = NULL;
		right_zoom(n + 1, env);
	}
	env->min_x = (l.min).x;
	env->min_y = (l.min).y;
	env->max_x = (l.max).x;
	env->max_y = (l.max).y;
	decale(&(env->zpt), env);
}

int			zoom(int keycode, t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 24)
		env->z = 1;
	else if (keycode == 27)
		env->z = -1;
	zoom_result(env);
	draw(env);
	return (0);
}
