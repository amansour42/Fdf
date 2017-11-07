/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:36:44 by amansour          #+#    #+#             */
/*   Updated: 2017/11/03 13:44:50 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_convert_base(char *str, int base)
{
	int		nbr;
	int		n;
	int		i;

	n = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr = str[i] - '0';
		else
			nbr = str[i] - 'A';
		n = n * base + nbr;
	}
	return (n);
}
