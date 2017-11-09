/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:25:49 by amansour          #+#    #+#             */
/*   Updated: 2017/11/09 13:00:16 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	error(char *s)
{
	write(1, s, ft_strlen(s));
	exit(0);
}

int	ft_open(char *path)
{
	char *str;

	if (!path || !(str = ft_strrchr(path, '.')) || ft_strcmp(str, ".fdf"))
		return (-1);
	return (open(path, O_RDONLY));
}
