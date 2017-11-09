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
	env->height = HEIGHT;
	env->width =  WIDTH;
	env->win = mlx_new_window(env->mlx, env->width, env->height, str);
}
static void  clean(t_check c)
{
    clean_split(c.s);
    clean_split(c.line);
    free(c.str);
    if (c.rest)
        free(c.rest);
    free(c.s1);

}             
static int  length(char **str, t_env *env)
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

static void  check(t_check *c, t_env *env)
{
    int i;

    i = ft_strlen(c->s1) - 1; 
    while (i >= 0 && c->s1[i] != '\n')
        i -= 1;
    free(c->rest);
    c->rest = ft_strdup(c->s1 + i + 1);
    c->j = (c->rest) ? -1 : 0;    
    c->line = ft_strsplit(c->s1, '\n');
    env->nbry += length(c->line, env) + c->j;
    i = -1;
    while (c->line[++i])
    {
        if (c->j == -1 && !(c->line[i + 1]))
            break ;
        c->s = ft_strsplit(c->line[i], ' ');
        (!(env->nbrx)) ? env->nbrx = length(c->s, env): 0;
        if (env->nbrx != length(c->s, env))
        {
            error(PARSEERROR);
            clean(*c);
        }
        clean_split(c->s);
    }
    clean_split(c->line);
    free(c->s1);
}




int     nbr_line(int fd, t_env *env)
{
	t_check c;
	int     ret;

    c.j = 0;
	init_env(env);
    if (!(c.str = (char*)malloc(sizeof(char) * (BUFF + 1))))
        return (0);
	c.rest = NULL;
    while ((ret = read(fd, c.str, BUFF)))
	{   
        c.str[ret] = '\0';
        c.s1 =  (c.rest) ? ft_strjoin(c.rest, c.str) : ft_strdup(c.str);
        if (!belong(c.s1, '\n'))
        {   
            if (c.rest)
                free(c.rest);
            c.rest = c.s1;
            continue;
        }
        check(&c, env);
    }
    env->nbry += 1;
    free(c.str);
    printf("NBRX = %d\nNBRY = %d\nDimZ = %d\n", env->nbrx, env->nbry, env->dim_z); 
    return (1);
}
