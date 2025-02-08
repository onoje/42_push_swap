/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoje <onoje@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:59:29 by onoje             #+#    #+#             */
/*   Updated: 2025/02/08 20:49:15 by onoje            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_minimum_number_index(t_list *a)
{
	int	minimum_number;
	int	minimum_number_index;
	int	i;

	minimum_number = a->content;
	minimum_number_index = 0;
	i = 0;
	while (a)
	{
		if (a->content < minimum_number)
		{
			minimum_number = a->content;
			minimum_number_index = i;
		}
		a = a->next;
		i++;
	}
	return (minimum_number_index);
}

void	ft_sort_data(t_list **a, t_list **b)
{
	int	size;

	size = ft_stack_size(*a);
	if (size <= 5)
		ft_sort_data_small(a, b);
	else
	{
		ft_indexing_stack(*a);
		ft_radix_sort(a, b);
	}
}
