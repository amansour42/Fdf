/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:11:31 by amansour          #+#    #+#             */
/*   Updated: 2017/11/09 10:30:33 by amansour         ###   ########.fr       */
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

static int	fill_point(t_point **point, char **str, t_env *env, int *k)
{
	int		i;
	t_point	p;

	i = -1;
	while (str[++i])
	{
		p.x = i;
		p.y = (int)((*k) / NBRX);
		//printf("I = %d Y = %lf K = %d\n", i, p.y, *k);
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
	return (1);
}

static int	stock_per_line(t_point **pt, t_check *c, t_env *env, int *k)
{
	int		i;

	i = ft_strlen(c->s1) - 1;
	while (i >= 0 && c->s1[i] != '\n')
		i -= 1;
	if (c->rest)
		free(c->rest);
	c->rest = ft_strdup(c->s1 + i + 1);
	c->j = (c->rest && *(c->rest)) ? -1 : 0;
	c->line = ft_strsplit(c->s1, '\n');
	i = -1;
	while (c->line[++i])
	{
		if (c->j == -1 && !(c->line[i + 1]))
				break ;
		if (!(fill_point(pt, ft_strsplit(c->line[i], ' '), env, k)))
		{
			free(*pt);
			*pt = NULL;
			return(0);
		}
	}
	clean_split(c->line);
	free(c->s1);
	return (1);
}

void	stocking(int fd, t_env *env)
{
	t_check		c;
	int			ret;
	int			k;

	k = 0;
	NBR = NBRX * NBRY;
	c.rest = NULL;
	if (!(env->pt = (t_point*)malloc(sizeof(t_point) * NBR)) ||
			!(c.str = (char*)malloc(BUFF + 1)))
		return ;
	while ((ret = read(fd, c.str,  BUFF)))
	{
		c.str[ret] = '\0';
		c.s1 =  (c.rest) ? ft_strjoin(c.rest, c.str) : ft_strdup(c.str);
		if (!belong(c.s1, '\n'))
		{
			printf("ICI\n");
			if (c.rest)
				free(c.rest);
			c.rest = ft_strdup(c.s1);
			continue;
		}
		if (!(stock_per_line(&(env->pt), &c, env, &k)))
			return ;
	}
	free(c.str);
	//clean(c);
	printf("env_minx = %lf\n, env_miny = %lf\n", env->min_x, env->min_y);
}
