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

/*
static int check_line(char *str, t_env *env, int *rest)
{
    int i;
    //int f;
    int n;
    //int dim;

	n = 0;
	i = -1;
	//dim = 0;
	//f =  *rest;
	printf("REST = %d\n", *rest);
	printf("%s\n", str);
    while(str[++i])
	{
                     
		if (str[i] == ' ')
		{
            
			++(*rest);
            ++i;
			while (str[i] && belong("0123456789xabcdef,", str[i]))
            {
                printf("%c", str[i]); 
				++i;
            }
            printf("\n");
			//(dim > env->dim_z) ? env->dim_z = dim  : 0;
            
            printf("I = %d\n", i);
            printf("str sortie = %c\n", str[i]);
        }
        if (str[i] == '\n')
		{
			printf("nbr_x = %d\n", env->nbrx);
            (env->nbrx == 0) ? env->nbrx = *rest : 0;
			if (env->nbrx != *rest && *rest)
			{
				printf("rest = %d", *rest);
				return (0);
			}
			++n;
			//f = 0;
            *rest = 0;
		}
        else if (str[i] == ' ')
            ++i;
       
    }
	env->nbry += n;
	if (!env->nbr)
		*rest = f;
	else
	rest = f;
	printf("ok\n");
    return (1);
}
*/
static  int length(char **str, t_env *env)
{
    int len;

    len = 0;
    while (str[len])
    {
        if (belong(str[len], ','))
            env->exist = 1;
        ++len;
    }
    return (len);
}

int     nbr_line(int fd, t_env *env)
{
	char    *str;
	int     ret;
	int     rest;
    char    **s;

	rest = 0;
	init_env(env);
	while ((ret = get_next_line(fd, &str)))
	{
		if (ret == -1)
			return (0);
        s = ft_strsplit(str, ' ');
        if (str)
		{
		    (env->nbrx == 0) ? env->nbrx = length(s, env) : 0;
			if (env->nbrx != length(s, env))
			{
				printf("ERROR\n");
				return (0);
            }
            clean_split(s);
		}
        free(str);
        env->nbry += 1;
	}
    printf("NBRX = %d\nNBRY = %d\nDimZ = %d\n", env->nbrx, env->nbry, env->dim_z); 
    return (1);
}
