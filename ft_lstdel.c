/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:44:15 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/10 19:44:17 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*curr;
	t_list	*next;

	if (!del || !alst || !*alst)
		return ;
	curr = *alst;
	while (curr != NULL)
	{
		next = curr->next;
		del(curr->content, curr->content_size);
		free(curr);
		curr = next;
	}
	*alst = NULL;
}
