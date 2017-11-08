/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:32:28 by amansour          #+#    #+#             */
/*   Updated: 2017/11/07 15:02:07 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_split(char **s)
{
	int	nbr;

	nbr = 0;
	while (s[nbr])
		++nbr;
	while (--nbr >= 0)
	{
		free(*(s + nbr));
		*(s + nbr) = NULL;
	}
	free(s);
	return ;
}

static int	ft_hexa(char *str, t_point *p)
{
	char **s;

	s = ft_strsplit(str, ',');
	if((p->z = ft_atoi(s[0])) == -1 && ft_strcmp(s[0], "-1"))
	{
		clean_split(s);
		free(s);
		return (0);
	}
	p->c = ft_convert_base(s[1] + 2, 16);
	clean_split(s);
	return (1);
}

static int  fill_point(t_point **point, char **str, t_env *env, int *k)
{
	int     i;
	t_point p;

	i = -1;
	while (str[++i])
	{
		p.x = i;
		p.y = env->nbry;
        p.c = 0;
		if (belong(str[i], ',') && !ft_hexa(str[i], &p))
		{
			clean_split(str);
			return (0);
		}
		else if ((p.z = ft_atoi(str[i])) == -1 && ft_strcmp(str[i], "-1"))
		{
			clean_split(str);
			return(0);
		}
        (p.c == 0) ? p.c = choose_color(p.z, env) : 0;
		isometric_calcul(&p, env);
		(*point)[(*k)++] = p;
	}
	clean_split(str);
	env->nbry += 1;
	return (1);
}

t_point      *collect(int fd, t_env *env, char *str)
{
	char	*line;
	int		ret;
	t_point *pt;
    int     i;

	if (!nbr_line(fd, env))
		return (NULL);
	close(fd);
	fd = open(str, O_RDONLY);
	if (!(pt = (t_point*)malloc(sizeof(t_point) * (env->nbry * env->nbrx))))
		return (NULL);
	env->nbry = 0;
	i = 0;
	while (get_next_line(fd, &line) == 1 &&
			((ret = fill_point(&pt, ft_strsplit(line, ' '), env, &i))))
		free(line);
	if (!ret)
	{
		free(pt);
		return (0);
	}
	printf("env_minx = %lf\n, env_miny = %lf\n", env->min_x, env->min_y);
	return (pt);
}
