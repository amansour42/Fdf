#include "fdf.h"

void	init_env(t_env *env)
{
	env->max_y = 0;
	env->max_x = 0;
	env->min_x = 0;
	env->min_y = 0;
	env->nbrx = 0;
	env->nbry = 0;
	env->dim_z = 0;
	env->z = 0;
	env->exist = 0;
	env->zpt = NULL;
	env->p = NULL;
}


void	define_dim(t_env *env, char *str)
{
	env->height = HEIGHT;//(env->max_y - env->min_y)  + 300;
	env->width =  WIDTH;//(env->max_x - env->min_x) + 300;
	env->win = mlx_new_window(env->mlx, env->width, env->height, str);
}

/*static int 	dim_z(char *str, int *i, t_env *env)
{
	int dim;

	dim = 0;
	(str[*i] == '-') ? (*i) += 1 : 0;
	while (str[*i] && ft_isdigit(str[(*i)]))
	{
		(*i) += 1;
		++dim;
	}
	if (str[*i] == ',')
	{
		(*i) += 1;
		env->exist = 1;
		while (ft_isdigit(str[(*i)]) || belong("xabcdef", str[*i]))
			(*i) += 1;
	}
	return (dim);
}*/

static int check_line(char *str, t_env *env, int *rest)
{
    int i;
    int f;
    int n;
    //int dim;

	n = 0;
	i = -1;
	//dim = 0;
	f =  *rest;
	printf("REST = %d\n", *rest);
	while(str[++i])
	{
		if (str[i] == '\n')
		{
			(env->nbrx == 0) ? env->nbrx = f : 0;
			if (env->nbrx != f && f)
			{
				printf("F = %d", f);
				return (0);
			}
			++n;
			f = 0;
		}
		//dim = dim_z(str, &i, env);
		if (ft_isdigit(str[i]))
		{
			++f;
			while (str[i] && !belong(" \n", str[i]))
				++i;
			//(dim > env->dim_z) ? env->dim_z = dim  : 0;
		}
		
	}
	env->nbry += n;
	/*if (!env->nbr)
		*rest = f;
	else*/
	*rest = f;
	return (1);
}

int     nbr_line(int fd, t_env *env)
{
	char *str;
	int     ret;
	int     rest;

	rest = 0;
	init_env(env);
	if (!(str = (char*)malloc(sizeof(char) * 2049)))
		return (0);
	while ((ret = read(fd, str, 2048)))
	{
		if (ret == -1)
			return (0);
		str[ret] =  '\0';
		if ((check_line(str, env, &rest)) == 0)
		{
			printf("NBRX = %d\n", env->nbrx);
			printf("OK\n");
			return (0);
		}
	}
	env->nbrx += 1;
	free(str);
    printf("NBRX = %d\nNBRY = %d\nDimZ = %d\n", env->nbrx, env->nbry, env->dim_z); 
    return (1);
}