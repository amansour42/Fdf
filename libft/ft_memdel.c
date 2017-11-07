/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 09:46:50 by amansour          #+#    #+#             */
/*   Updated: 2017/05/01 12:32:47 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	char **app;

	app = (char**)ap;
	if (app == NULL)
		return ;
	if (*app != NULL)
		free((void*)(*app));
	*app = NULL;
	app = NULL;
	return ;
}
