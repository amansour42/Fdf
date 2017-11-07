/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:02:40 by amansour          #+#    #+#             */
/*   Updated: 2017/11/07 15:34:14 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int choose_color(int z)
{
	if (z > 100)
		return (0x4000FF);
	if (z > 40)
		return (0x8000FF);
	if (z > 10)
		return (0x00FF00);
	if (z > 0)
		return (0xFF00FF);
	if (z > -20)
		return (0xFF0000);
	return (0xFFCC00);
}

void isometric_calcul(t_point *pt, t_env *env)
{
	double  x;
	double  y;
	int     p;

	p = (env->dim_z - 1 > 0 && env->nbrx < 100) ? (env->dim_z - 1) * 10 : 1;
	x = p * (pt->x * cos(PHI) + pt->y * cos(PHI + A)) + pt->z * cos(PHI - A);
	y = p * (pt->x * sin(PHI) + pt->y * sin(PHI + A)) + pt->z * sin(PHI - A);
	pt->x = x;
	pt->y = y;
	(env->min_x > x) ? env->min_x = x : 0;
	(env->min_y > y) ? env->min_y = y : 0;
	(env->max_x < x) ? env->max_x = x : 0;
	(env->max_y < y) ? env->max_y = y : 0;
}
