/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:45:36 by amansour          #+#    #+#             */
/*   Updated: 2017/11/09 12:26:32 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 		decale(t_point **pt, t_env *env)
{
	int i;

	i = NBR;
	if (!env->min_x && !env->min_y)
		return ;
	while (--i >= 0)
	{
		(*pt)[i].x -= env->min_x;
		(*pt)[i].y -= env->min_y; 
	}
}

t_point		*dupp(t_point *pt, t_env *env)
{
	t_point	*p;
	int		j;

	if (!(p = (t_point*)malloc(sizeof(t_point) * NBR)))
		return (NULL);
	j = -1;
	while (++j < NBR)
	{
		p[j].x = pt[j].x;
		p[j].y = pt[j].y;
		p[j].c = pt[j].c;
	}
	return (p);
}

int 		choose_color(int z, t_env *e)
{
	if (e->exist)
		return (WHITE);
	if (z < 0)
		return (BLUE);
	if (z < 10)
		return (GREEN);
	if (z < 100)
		return (YELLOW);
	if (z < 1000)
		return(BROWN);
	return (0);
}

void 		isometric_calcul(t_point *pt, t_env *env)
{
	double  x;
	double  y;
	int     p;

	p = 1;
	x = p * (pt->x * cos(PHI) + pt->y * cos(PHI + A)) + pt->z * cos(PHI - A);
	y = p * (pt->x * sin(PHI) + pt->y * sin(PHI + A)) + pt->z * sin(PHI - A);
	pt->x = x;
	pt->y = y;
	(env->min_x > x) ? env->min_x = x : 0;
	(env->min_y > y) ? env->min_y = y : 0;
	(env->max_x < x) ? env->max_x = x : 0;
	(env->max_y < y) ? env->max_y = y : 0;
}
void	write_one_pixel(t_dot pt, t_env *env, int color)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (color)
	{
	    b = (color & 0xFF0000) >> 16;
	    g = (color & 0xFF00) >> 8;
	    r = (color & 0xFF);
	}
	if (pt.x >= 0 && pt.y >= 0 && pt.x < env->width && pt.y < env->height)
	{
		env->data[pt.y * env->size + pt.x * (env->bit / 8)] = r;
		env->data[pt.y * env->size + pt.x * (env->bit / 8) + 1] = g;
		env->data[pt.y * env->size + pt.x * (env->bit / 8) + 2] = b; 
	}
}
