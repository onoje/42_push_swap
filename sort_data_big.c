/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoje <onoje@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:36:04 by onoje             #+#    #+#             */
/*   Updated: 2025/02/08 20:48:25 by onoje            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_indexing_stack(t_list *a)
{
	t_list	*ptr1;
	t_list	*ptr2;
	int		index;

	ptr1 = a;
	while (ptr1)
	{
		index = 0;
		ptr2 = a;
		while (ptr2)
		{
			if (ptr1->content > ptr2->content)
				index++;
			ptr2 = ptr2->next;
		}
		ptr1->index = index;
		ptr1 = ptr1->next;
	}
}

static int	ft_find_maximum_bit(t_list **a)
{
	t_list	*stack;
	int		maximum_index;
	int		maximum_bit;

	stack = *a;
	maximum_index = stack->index;
	maximum_bit = 0;
	while (stack)
	{
		if (stack->index > maximum_index)
			maximum_index = stack->index;
		stack = stack->next;
	}
	while ((maximum_index >> maximum_bit) != 0)
		maximum_bit++;
	return (maximum_bit);
}

// '>>' bit kaydırma operatorüdür. Sağa doğru kaydırma işlemi yapar.

// size 10 olarak verilirse size - 1 = 9 olur. 
// 9'un binary karşılığı 1001'dir. 
// max_bits 4 olduğunda 0 koşuluna gireceği için döngü kırılır.

/* if ((((*a)->index >> i) & 1) == 0) */
// i bit türündeki i. indexi ifade eder(En sağ sıfırıncı index.). 
// Number'in tuttuğu indexin bit karşılığının i. indexi karşılaştırılır. 
// Yani i. bitin 0 olup olmadığı kotrol edilir.

/* ft_pb(a, b); */
// Bit 0 ise.

/* ft_ra(a); */
// Bit 1 ise.
void	ft_radix_sort(t_list **a, t_list **b)
{
	int	size;
	int	maximum_bit;
	int	i;
	int	j;

	size = ft_stack_size(*a);
	maximum_bit = ft_find_maximum_bit(a);
	i = 0;
	while (i < maximum_bit)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				ft_pb(a, b);
			else
				ft_ra(a);
			j++;
		}
		while (*b)
			ft_pa(a, b);
		i++;
	}
}
