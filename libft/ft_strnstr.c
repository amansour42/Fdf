/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 20:23:47 by amansour          #+#    #+#             */
/*   Updated: 2017/05/01 11:29:47 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t n)
{
	if (!l)
		return ((char*)b);
	if (!b || n < ft_strlen(l))
		return (NULL);
	if (ft_strlen(b) <= n)
		return (ft_strstr(b, l));
	while (n >= ft_strlen(l))
	{
		if (!ft_memcmp((void const*)b, (void const*)l, ft_strlen(l)))
			return ((char*)b);
		b++;
		n--;
	}
	return (NULL);
}
