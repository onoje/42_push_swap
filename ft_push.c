/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoje <onoje@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:24:03 by onoje             #+#    #+#             */
/*   Updated: 2025/02/08 16:00:24 by onoje            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

/* ft_push(b, a); */
// Argümanların verilme sırası önemli.
void	ft_pa(t_list **a, t_list **b)
{
	ft_push(b, a);
	ft_write_str_and_new_line("pa");
}

void	ft_pb(t_list **a, t_list **b)
{
	ft_push(a, b);
	ft_write_str_and_new_line("pb");
}
