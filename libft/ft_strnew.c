/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 11:15:32 by amansour          #+#    #+#             */
/*   Updated: 2017/10/15 11:11:38 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char*)ft_memalloc(size + 1);
	if (str)
	{
		if (size == 0)
			str[0] = '\0';
		else
		{
			ft_memset(str, 0, size);
			str[size] = '\0';
		}
	}
	return (str);
}
