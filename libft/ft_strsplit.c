/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 10:07:28 by amansour          #+#    #+#             */
/*   Updated: 2017/10/19 12:03:53 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int      index_c(char const *str, char c, int start)
{
    int i;

    i = start;
    while (str[i] == c)
        ++i;
    return (i);
}

static char		**ft_tab(char const *str, size_t nb, char c, char **tab)
{
	size_t j;
	size_t i;
    size_t k;

	j = 0;
    k = 0;
    i = 0;
	while (j < (nb - 1))
	{
		
		k = index_c(str, c, i);
        i = k;
		while (str[i] && str[i] != c)
			i++;
		//if (!(tab[j] = ft_strsub(str, k, i - k)))
		//	return (NULL);
        if (!(tab[j] = ft_strnew(i - k)))
            return (NULL);
        ft_strncpy(tab[j], str + k, i - k);
        tab[j][i - k] = '\0';
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

static int      tab_len(char const *s, char c)
{
    int len;
    int i;

    len = 1;
    i = 0;
    while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			++len;
		while (s[i] && s[i] != c)
			i++;
    }
    return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	nb;
	int		i;
	char	**tab;

	if (!s)
		return (NULL);
	i = 0;
	nb = tab_len(s, c);;
	if ((tab = (char**)malloc(sizeof(char*) * nb)))
		return (ft_tab(s, nb, c, tab));
	return (NULL);
}
