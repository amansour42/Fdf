#include "fdf.h"

int	zoom(int keycode, t_env *env)
{
	//mlx_clear_window(env->mlx, env->win);
	if (keycode == 24)//+
		env->z = 1;
	else if (keycode == 27) //-
		env->z = -1;
	zoom_result(env);
	draw(env);
	return (0);
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