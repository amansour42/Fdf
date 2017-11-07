/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:35:29 by amansour          #+#    #+#             */
/*   Updated: 2017/11/06 13:39:52 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void segment_point_x(t_point pt, t_env env, int color)
{
	int		cumul;
	int		i;
	//int		inc;

	i = 0;
	cumul = env.dx / 2;
	while (++i < env.dx)
	{
		//inc = (i == (env.dx - 1)) ? color : 0xFFFFFF;
        //if (pt.c != color)
        //pt.c += inc;
		pt.x += env.incx;
		cumul += env.dy;
		if (cumul >= env.dx)
		{
			cumul -= env.dx;
			pt.y += env.incy;
		}
        mlx_pixel_put(env.mlx, env.win,(int)pt.x, (int)pt.y, color);
	}
}

static void segment_point_y(t_point pt, t_env env, int color)
{
	int	cumul;
	int	i;
	
    i = 0;
	cumul = env.dy / 2;
    //inc = (pt.c < color) ? 10 : -10;
	while (++i < env.dy)
	{
		pt.y += env.incy;
		cumul += env.dx;
		if (cumul >= env.dy)
		{
			cumul -= env.dy;
			pt.x += env.incx;
		}
		mlx_pixel_put(env.mlx, env.win, (int)pt.x, (int)pt.y, color); 
	}
}

void        segment(t_point pti, t_point ptf, t_env env)
{
	t_point pt;

	env.dx = (int)(ptf.x - pti.x);
	env.dy = (int)(ptf.y - pti.y);
	env.incx = (env.dx > 0) ? 1 : -1;
	env.incy = (env.dy > 0) ? 1 : -1;
	env.dx = abs(env.dx);
	env.dy = abs(env.dy);
	pt.x = pti.x;
	pt.y = pti.y;
	pt.c = pti.c;
	mlx_pixel_put(env.mlx, env.win, (int)pt.x, (int)pt.y, pt.c);
	if (env.dx > env.dy)
		segment_point_x(pt, env, ptf.c);
	else
		segment_point_y(pt, env, ptf.c);
	return ;
}
