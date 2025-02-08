/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoje <onoje@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:43:49 by onoje             #+#    #+#             */
/*   Updated: 2025/02/08 16:00:42 by onoje            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* while (last->next) */
// Stackin sonuna kadar gider ve sonuncu elemanı bulduğunda durur. 

/* last->next = tmp; */
// Sonuncu elemanın sonuna ilk elemanı ekler. 
// *stack listenin başını tuttuğu için,
// last ile listede yapılacak herhangi bir değişiklik stacki değiştirir.
static void	ft_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	ft_ra(t_list **a)
{
	ft_rotate(a);
	ft_write_str_and_new_line("ra");
}

void	ft_rb(t_list **b)
{
	ft_rotate(b);
	ft_write_str_and_new_line("rb");
}

void	ft_rr(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_write_str_and_new_line("rr");
}
