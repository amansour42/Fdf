/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 12:00:34 by amansour          #+#    #+#             */
/*   Updated: 2017/10/16 12:00:54 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel2(t_list **alst)
{
	t_list *maillon;

	while (*alst != NULL)
	{
		maillon = *alst;
		(*alst) = (*alst)->next;
		free(maillon);
		maillon = NULL;
	}
	alst = NULL;
	return ;
}
