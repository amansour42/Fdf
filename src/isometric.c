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
    //printf("envminy = %lf/n", env.min_y);
	(!env.min_x) ? env.min_x = -50 : 0;
    (!env.min_y) ? env.min_y = -50 : 0; 
    if (!env.min_x && !env.min_y)
		return ;
	while (--i >= 0)
	{
		(*pt)[i].x -= env.min_x;
		(*pt)[i].y -= env.min_y; 
	}
    //display_point(*pt, env.nbrx * env.nbry);
}

void	zoom(t_point **pt, int n, t_env *env)
{
	int     i;
	t_point *r;
	t_point max;
	t_point min;

    //printf("N  = %d\n", n);
    i = env->nbrx * env->nbry;  
	//printf("nbry  = %d\n", env->nbry); 
    if (!(r = (t_point*)malloc(sizeof(t_point) * i)))
        return ;
	max.x = 0;
	max.y = 0;
	min.x = 0;
	min.y = 0;;
	while (--i >= 0)
	{
		r[i].x = (*pt)[i].x * n;
    	r[i].y = (*pt)[i].y * n;
		r[i].c = (*pt)[i].c;
		(max.x < r[i].x) ? max.x = r[i].x : 0;
		(max.y < r[i].y) ? max.y = r[i].y : 0;
		(min.x > r[i].x) ? min.x = r[i].x : 0;
		(min.y > r[i].y) ? min.y = r[i].y : 0;
	}
	if ((max.y - min.y) > 600 || (max.x-min.x) > 1100)
	{
		free(*pt);
		env->min_x = min.x;
		env->min_y = min.y;
		env->max_x = max.x;
		env->max_y = max.y;
		*pt = r;
		return ;
	}
	free(r);
	zoom(pt, n + 1, env);
}
