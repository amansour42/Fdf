/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:30:09 by amansour          #+#    #+#             */
/*   Updated: 2017/11/06 13:31:56 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void decale(t_point **pt, t_env env)
{
    int     i;

    i = env.nbrx * env.nbry;
    if (!env.min_x && !env.min_y)
		return ;
	while (--i >= 0)
	{
		(*pt)[i].x -= env.min_x;
		(*pt)[i].y -= env.min_y; 
	}
}

static t_point *dupp(t_point *pt, t_env *env)
{
	t_point *p;
	int		i;
	int		j;

	i = env->nbrx * env->nbry;
	if (!(p = (t_point*)malloc(sizeof(t_point) * i)))
		return (NULL);
	j = -1;
	while (++j < i)
	{
		p[j].x = pt[j].x;
		p[j].y = pt[j].y;
		p[j].c = pt[j].c;
	}
	return (p);
}

void	zoom_result(t_env *env)
{
	int		i;

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
	//env->z = n;
	//printf("ZOOM = %d\n", n);
	decale(&(env->zpt), *env);
	//printf("**POINT**\n");
	//display_point(env->zpt, env->nbrx * env->nbry);
	//printf("**POINT**\n");
	return ;
	
}
