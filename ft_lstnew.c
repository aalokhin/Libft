/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:44:55 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/10 19:44:57 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*head;

	head = (t_list*)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	else if (!content)
	{
		head->content = NULL;
		head->content_size = 0;
	}
	else
	{
		head->content = (void*)malloc(sizeof(void) * content_size);
		head->content_size = 0;
		if (!head->content)
		{
			free(head);
			head->content = NULL;
			return (NULL);
		}
		ft_memcpy(head->content, content, content_size);
		head->content_size = content_size;
	}
	head->next = NULL;
	return (head);
}
