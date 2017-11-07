/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:59:21 by amansour          #+#    #+#             */
/*   Updated: 2017/10/19 12:03:26 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_blanks(char const *str)
{
	int i;

	i = 0;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

static int	ft_result(char const *str, int sign, int start)
{
	int	long	n;
	int			i;

	i = 0;
	n = 0;
	while (str[start] && ft_isdigit(str[start]) && i++ < 9)
		n = n * 10 + str[start++] - '0';
	if (!str[start] || !ft_isdigit(str[start]))
		return (sign * n);
	if ((str[start + 1] && ft_isdigit(str[start + 1])) || n > 214748364)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	if ((n == 214748364 && (((str[start] - '0') <= 7 && sign == 1) ||
		((str[start] - '0') <= 8 && sign == -1))) || n < 214748364)
		return (sign * (n * 10 + str[start] - '0'));
	if ((str[start + 1] - '0') > 8 && sign == -1)
		return (0);
	return (-1);
}

int			ft_atoi(char const *str)
{
	int		sign;
	int		i;

	if (!str)
		return (0);
	sign = 1;
	i = ft_blanks(str);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] && str[i] == '0')
		i++;
	return (ft_result(str, sign, i));
}
