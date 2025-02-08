/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoje <onoje@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:04:28 by onoje             #+#    #+#             */
/*   Updated: 2025/02/08 21:46:06 by onoje            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (argc <= 1)
		return (0);
	a = ft_initialize_stack(argc, argv);
	if (!a)
	{
		ft_write_error_and_new_line("Error");
		ft_stack_free(a);
		ft_stack_free(b);
		exit(1);
	}
	ft_duplicate_control(a);
	if (ft_sorted_control(a))
	{
		ft_stack_free(a);
		ft_stack_free(b);
		exit(0);
	}
	ft_sort_data(&a, &b);
	ft_stack_free(a);
	ft_stack_free(b);
}
