/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoje <onoje@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:33:30 by onoje             #+#    #+#             */
/*   Updated: 2025/02/08 16:04:38 by onoje            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ft_swap(t_list **stack) */
// Stackin başını değiştirebilmek için double pointer kullanılır.
// Eğer tek pointer kullanılsaydı,
// yapılan değişiklikler fonksiyonun dışında etkili olmazdı.

/* return ; */
// Dönüş değeri void olduğu için bu şekilde yazılır.
static void	ft_swap(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	ft_sa(t_list **a)
{
	ft_swap(a);
	ft_write_str_and_new_line("sa");
}

void	ft_sb(t_list **b)
{
	ft_swap(b);
	ft_write_str_and_new_line("sb");
}

void	ft_ss(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_write_str_and_new_line("ss");
}
