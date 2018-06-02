/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 12:24:59 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/19 12:25:01 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstrev(t_list **alst)
{
	t_list	*current;
	t_list	*previous;
	t_list	*next;

	if (!alst || !*alst)
		return ;
	previous = NULL;
	current = *alst;
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*alst = previous;
}
