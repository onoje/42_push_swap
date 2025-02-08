/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoje <onoje@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:51:41 by onoje             #+#    #+#             */
/*   Updated: 2025/02/08 21:48:20 by onoje            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "extra_functions.h"

// ft_push.c, ft_reverse_rotate.c, ft_rotate.c, ft_swap.c
void	ft_pa(t_list **a, t_list **b);
void	ft_pb(t_list **a, t_list **b);
void	ft_rra(t_list **a);
void	ft_rrb(t_list **b);
void	ft_rrr(t_list **a, t_list **b);
void	ft_ra(t_list **a);
void	ft_rb(t_list **b);
void	ft_rr(t_list **a, t_list **b);
void	ft_sa(t_list **a);
void	ft_sb(t_list **b);
void	ft_ss(t_list **a, t_list **b);

// sort_data_big.c, sort_data_small.c, sort_data.c
void	ft_indexing_stack(t_list *a);
void	ft_radix_sort(t_list **a, t_list **b);
void	ft_sort_data_small(t_list **a, t_list **b);
int		ft_find_minimum_number_index(t_list *a);
void	ft_sort_data(t_list **a, t_list **b);

// push_swap_main.c, push_swap.c
int		main(int argc, char **argv);
t_list	*ft_initialize_stack(int argc, char **argv);
void	ft_duplicate_control(t_list *a);
int		ft_sorted_control(t_list *a);

#endif
