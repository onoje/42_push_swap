/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoje <onoje@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 00:15:29 by onoje             #+#    #+#             */
/*   Updated: 2025/01/30 19:03:55 by onoje            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	tmp = *stack;
	*stack = last;
	last->next = tmp;
}

void	ft_rra(t_list **a)
{
	ft_reverse_rotate(a);
	ft_write_str_and_new_line("rra");
}

void	ft_rrb(t_list **b)
{
	ft_reverse_rotate(b);
	ft_write_str_and_new_line("rrb");
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_write_str_and_new_line("rrr");
}
