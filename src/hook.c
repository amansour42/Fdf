/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:57:24 by amansour          #+#    #+#             */
/*   Updated: 2017/11/09 12:24:40 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		quit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53 || keycode == 12)
		quit(e);
	else if (keycode == 48)
		mlx_clear_window(e->mlx, e->win);
	else if (keycode == 17)
		trace(e);
	else if (keycode == 27 || keycode == 24)
		zoom(keycode, e);
	else if (keycode == 15)
		rotate(e);
	return (0);
}

void	init_imag(t_env *e)
{
	e->imag = mlx_new_image(e->mlx, e->width, e->height);
	e->data = mlx_get_data_addr(e->imag, &(e->bit), &(e->size), &(e->endian));
}

int		expose_hook(t_env *e)
{
	init_imag(e);
	draw(e);
	return (0);
}
