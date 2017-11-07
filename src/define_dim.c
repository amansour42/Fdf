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
}


void    	define_dim(t_env *env)
{
	env->height = (env->max_y - env->min_y)  + 100;//- pmin.y + 100;
	env->width =  (env->max_x - env->min_x) + 100;//- pmin.x + 100;
}

static int 	dim_z(char *str, int *i)
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
		while (ft_isdigit(str[(*i)]) || belong("xabcdef", str[*i]))
			(*i) += 1;
	}
	return (dim);
}

static int check_line(char *str, t_env *env, int *rest)
{
    int i;
    int f;
    int n;
    int dim;

	n = 0;
	i = -1;
	dim = 0;
	f =  *rest;
	while(str[++i])
	{
		dim = dim_z(str, &i);
		if (str[i] == ' ')
		{
			while (str[++i] == ' ')
				;
			if (str[i] != '\n')
				++f;
			(dim > env->dim_z) ? env->dim_z = dim  : 0;
			--i;
		}
		if (str[i] == '\n')
		{
			(env->nbrx == 0) ? env->nbrx = f : 0;
			if (env->nbrx != f && f)
				return (0);
			++n;
			f = 0;
		}
	}
	env->nbry += n;
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
	if (!(str = (char*)malloc(sizeof(char) * 4028)))
		return (0);
	while ((ret = read(fd, str, 4028)))
	{
		if (ret == -1)
			return (0);
		if (ret != 4028)
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
