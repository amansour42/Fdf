/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:24:52 by amansour          #+#    #+#             */
/*   Updated: 2017/09/18 10:32:32 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_str(int n, size_t index, int sign)
{
	char	*str;

	if ((str = ft_strnew(index)))
	{
		str[index] = '\0';
		str[--index] = n % 10 + '0';
		n /= 10;
		while (n)
		{
			--index;
			str[index] = n % 10 + '0';
			n /= 10;
		}
		if (sign == -1)
			str[0] = '-';
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int		sign;
	size_t	index;
	int		nb;

	sign = 1;
	index = 1;
	if (n == -2147483648)
		return ("-2147483648\0");
	nb = n;
	if (n < 0)
	{
		sign = -1;
		index += 1;
		nb = -nb;
	}
	n /= 10;
	while (n)
	{
		index++;
		n /= 10;
	}
	return (ft_str(nb, index, sign));
}
