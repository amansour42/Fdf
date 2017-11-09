/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 10:03:36 by amansour          #+#    #+#             */
/*   Updated: 2017/11/09 11:33:54 by amansour         ###   ########.fr       */
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
# define WIDTH		1000
# define HEIGHT		800
# define PHI		(PI / 180) * 30
# define A			(PI / 180) * 120
# define R			(PI / 4)
# define USAGE		"Usage: {PATH}/fdf some_file.fdf"
# define READERROR	"Read error"
# define PARSEERROR	"Parse error"
# define NOTFOUND	"File not found or wrong format"
# define BUFF		2048
# define GREEN		0x009688
# define YELLOW		0xfeff77
# define BLUE		0x4162ff
# define PINK		0xff0097
# define WHITE		0xFFFFFF
# define BROWN		0x654432
# define NBR		env->nbr
# define NBRX		env->nbrx
# define NBRY		env->nbry

typedef struct		s_point
{
	double			x;
	double			y;
	int				z;
	int				c;
}					t_point;

typedef struct      s_check
{
    char			*str;
    char			**line;
    char			**s;
    char			*rest;
    char			*s1;
    int				j;
}					t_check;

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
	int				nbr;
	int				incx;
	int				incy;
	int				dx;
	int				dy;
	t_point			*pt;
	t_point			*zpt;
	t_point			*p;
	int 			bit;
	int 			endian;
	char 			*data;
	int     		size;
	int 			exist;
}					t_env;

/*
 * tools
*/
void				decale(t_point **pt, t_env *env);
t_point				*dupp(t_point *pt, t_env *env);
int					choose_color(int z, t_env *e);
void				isometric_calcul(t_point *pt, t_env *env);
void				write_one_pixel(t_dot pt, t_env *env, int color);

/*
 * zoom.c
*/
int 				zoom(int key, t_env *env);
void				right_zoom(t_point *pt, int n, t_env *env);

/*
 *rotating
*/
int					rotate(t_env *env);
/*
 * checking and stocking
*/
void				clean_split(char **s);
void				clean(t_check c);
int					checking(int fd, t_env *env);
void				stocking(int fd, t_env *env);
/*
 * hook
*/

void				isometric_calcul(t_point *point, t_env *env);
int					key_hook(int keycode, t_env *e);
int					expose_hook(t_env *e);
void				init_imag(t_env *e);
int					quit(t_env *env);
/*
 * error
*/

void				define_dim(t_env *env, char *str);
int					ft_open(char *s);
int					error(char *s);

/*
 * draw
*/
void				trace(t_env *env);
int 				draw(t_env *e);
void				segment(t_point i, t_point f, t_env *env);
/*
 * main
 */

int					main(int ac, char **av);

void				display_point(t_point *point, int n);
#endif
