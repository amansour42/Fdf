/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 10:03:36 by amansour          #+#    #+#             */
/*   Updated: 2017/11/07 14:55:10 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <math.h>
# include "../minilibx/mlx.h"
# define PI			3.14
# define PT			t_point
# define WIDTH		1000
# define HEIGHT		800
# define PHI		(PI / 180) * 30
# define A			(PI / 180) * 120
# define USAGE		"Usage: {PATH}/fdf some_file.fdf"
# define READERROR	"Read error"
# define PARSEERROR	"Parse error"
# define NOTFOUND	"File not found or wrong format"

# define GREEN		0x009688
# define YELLOW		0xfeff77
# define BLUE		0x4162ff
# define PINK		0xff0097
# define WHITE		0xFFFFFF
# define BROWN		0x654432

typedef struct		s_point
{
	double			x;
	double			y;
	int				z;
	int				c;
}					t_point;
typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
	int				c;
}					t_dot;

typedef struct      s_env
{
	void			*mlx;
	void			*win;
	void			*imag;
	int				width;
	int				height;
	int 			z;
	double			max_x;
	double			max_y;
	double			min_x;
	double			min_y;
	int				dim_z;
	int				nbrx;
	int				nbry;
	int				incx;
	int				incy;
	int				dx;
	int				dy;
   	t_point         *pt;
   	t_point         *zpt;
   	t_point			*p;
   	int 			bit;
   	int 			endian;
   	char 			*data;
   	int     		size;
   	int 			exist;
}					t_env;

int					main(int ac, char **av);
t_point				*collect(int fd, t_env *env, char *str);
void				display_point(t_point *point, int n);
void				segment(t_point pointi, t_point pointf, t_env *env);
t_point				*isometric(t_point *point, t_env *env, int p, int n);
void				define_dim(t_env *env, char *str);
int                 nbr_line(int fd, t_env *env);
void				decale(t_point **point, t_env env);
int					error(char *s);
int					ft_open(char *s);
void				right_zoom(t_point *pt, int n, t_env *env);
void				zoom_result(t_env *env);
void				init_env(t_env *env);
void				isometric_calcul(t_point *point, t_env *env);
int 				choose_color(int z, t_env *env);
void				trace(t_env *env);
int 				draw(t_env *e);
int					quit(t_env *env);
void				init_imag(t_env *e);
int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
int 				zoom(int key, t_env *env);
void				write_one_pixel(t_dot pt, t_env *env, int color);
void                clean_split(char **s);
#endif
