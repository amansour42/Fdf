/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:47:47 by amansour          #+#    #+#             */
/*   Updated: 2017/05/01 11:16:28 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t size)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;
	unsigned char	car;

	i = 0;
	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	car = (unsigned char)c;
	while (i < size && src1[i] != car)
	{
		dst1[i] = src1[i];
		i++;
	}
	if (src1[i] == car)
	{
		dst1[i] = car;
		return ((void*)(dst + i + 1));
	}
	return (NULL);
}
