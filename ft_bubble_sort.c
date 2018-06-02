/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:52:27 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/19 17:52:30 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_bubble_sort(int *tab, unsigned int size)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i < (((int)size) - 1))
	{
		j = 0;
		while (j < (((int)size) - i - 1))
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
