/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:43:39 by amansour          #+#    #+#             */
/*   Updated: 2017/05/01 11:31:00 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(big);
	j = ft_strlen(little);
	if (!little)
		return ((char*)big);
	if (!big)
		return (NULL);
	while (i >= j)
	{
		i--;
		if (!ft_memcmp((void const*)big, (void const*)little, j))
			return ((char*)big);
		big++;
	}
	return (NULL);
}
