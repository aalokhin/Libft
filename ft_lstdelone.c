/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:44:24 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/10 19:44:26 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;

	if (!alst || !*alst || !del)
		return ;
	next = (*alst)->next;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = next;
}
