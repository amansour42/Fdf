/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:29:32 by amansour          #+#    #+#             */
/*   Updated: 2017/11/01 14:52:11 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char const	*str;
	int					i;

	i = 0;
	str = (unsigned char const*)s;
	if (!str)
		return (NULL);
	while (n != 0)
	{
		if (str[i] == (unsigned char)c)
			return ((void*)(str + i));
		--n;
		++i;
	}
	return (NULL);
}
