/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoje <onoje@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:13:41 by onoje             #+#    #+#             */
/*   Updated: 2025/02/08 21:53:05 by onoje            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Header dosyasındaki content,
// her türden veriyi tutabilmek için void* olarak tanımlanmıştır. 

// Karşılaştırma yapabilmek için integer veri tipine döniştirmemiz gerekir.
static void	ft_sort_2(t_list **a)
{
	if ((*a)->content > (*a)->next->content)
		ft_sa(a);
}

// Sırayla
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1
static void	ft_sort_3(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	if (first < second && second < third)
		return ;
	else if (first < second && second > third && first < third)
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (first > second && second < third && first < third)
		ft_sa(a);
	else if (first < second && second > third && first > third)
		ft_rra(a);
	else if (first > second && second < third && first > third)
		ft_ra(a);
	else if (first > second && second > third)
	{
		ft_sa(a);
		ft_rra(a);
	}
}

static void	ft_sort_4(t_list **a, t_list **b)
{
	int	index;

	index = ft_find_minimum_number_index(*a);
	if (index == 0)
		ft_pb(a, b);
	else if (index == 1)
	{
		ft_ra(a);
		ft_pb(a, b);
	}
	else if (index == 2)
	{
		ft_rra(a);
		ft_rra(a);
		ft_pb(a, b);
	}
	else
	{
		ft_rra(a);
		ft_pb(a, b);
	}
	ft_sort_3(a);
	ft_pa(a, b);
}

/* while (ft_lstsize(*a) > 3) */
// En küçük iki elemanı b'ye gönder.

/* while (*b) */
// Stack b'deki elemanları geri al.
static void	ft_sort_5(t_list **a, t_list **b)
{
	int	index;

	while (ft_stack_size(*a) > 3)
	{
		index = ft_find_minimum_number_index(*a);
		if (index == 0)
			ft_pb(a, b);
		else if (index <= ft_stack_size(*a) / 2)
			ft_ra(a);
		else
			ft_rra(a);
	}
	ft_sort_3(a);
	while (*b)
		ft_pa(a, b);
}

void	ft_sort_data_small(t_list **a, t_list **b)
{
	int	size;

	size = ft_stack_size(*a);
	if (size == 2)
		ft_sort_2(a);
	else if (size == 3)
		ft_sort_3(a);
	else if (size == 4)
		ft_sort_4(a, b);
	else if (size == 5)
		ft_sort_5(a, b);
}
