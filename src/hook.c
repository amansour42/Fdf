/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:57:24 by amansour          #+#    #+#             */
/*   Updated: 2017/11/07 15:57:36 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			quit(t_env *env)
{
	mlx_destroy_window(env->mlx, e->win);
	exit(0);
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == 53 || keycode == 12) //esc && q
		quit(e);
	else if (keycode == 49) //tab
		mlx_clear_window(e->mlx, e->win);
	else if (keycode == 15) //rotate , r
		rotate(e);
	else if (keycode == 14) //trace , t
		trace(e);
	else if (keycode == 27 || keycode == 24) //zoom +, -
		zoom(keycode, e);
	return (0);
}

static void	init_picture(t_env *e)
{
	e->pict = mlx_new_image(e->mlx, e->width, e->height);
	e->data = (int *)mlx_get_data_addr(e->pict, &e->bpp, &e->size, &e->endian);
}

int			expose_hook(t_env *e)
{
	init_picture(e);
	set(e);
	if (e->o.iso)
	{
		iso(e);
		draw(e->o.t2, e);
	}
	else
		draw(e->o.tab, e);
	return (0);
}

