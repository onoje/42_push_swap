/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoje <onoje@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:36:28 by onoje             #+#    #+#             */
/*   Updated: 2025/02/08 21:52:11 by onoje            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* if (argc == 2) */
// Eğer tek bir string argüman varsa parçala.

/* args = argv + 1; */
// Eğer birden çok arguman varsa,
// arguman kaydırma işlemi yaparak dosya adını pas geçiyoruz.
// Burada ft_split kullanılmadığı için malloc() ile yeni bir bellek ayırmıyoruz.
// Yani args zaten argv'nin içinde ve serbest bırakmaya gerek yok.
static char	**parse_arguments_and_check_numbers(int argc, char **argv)
{
	char	**args;
	int		i;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	i = 0;
	while (args[i])
	{
		if (ft_is_number(args[i]))
		{
			ft_write_error_and_new_line("Error");
			exit(1);
		}
		i++;
	}
	return (args);
}

/* number = ft_long_atoi(args[i]); */
// String'i long long'a çevir.
static void	ft_add_stack(t_list **a, char **args)
{
	t_list		*tmp;
	int			i;
	long long	number;

	i = 0;
	while (args[i])
	{
		number = ft_long_atoi(args[i]);
		if (number < -2147483648 || number > 2147483647)
		{
			ft_write_error_and_new_line("Error");
			exit(1);
		}
		tmp = ft_stack_new(number);
		if (!tmp)
		{
			ft_write_error_and_new_line("Error");
			ft_stack_free(*a);
			exit(1);
		}
		ft_stack_add_back(a, tmp);
		i++;
	}
}

/* if (argc == 2) */
// BU durumda args ft_split tarafından malloc() ile ayrılıyor,
// args freelenmezse bellek sızıntısı olur.
t_list	*ft_initialize_stack(int argc, char **argv)
{
	t_list	*a;
	char	**args;

	a = NULL;
	args = parse_arguments_and_check_numbers(argc, argv);
	ft_add_stack(&a, args);
	if (argc == 2)
		free(args);
	return (a);
}

void	ft_duplicate_control(t_list *a)
{
	t_list	*current;
	t_list	*tmp;

	current = a;
	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (current->content == tmp->content)
			{
				ft_write_error_and_new_line("Error");
				ft_stack_free(a);
				exit(1);
			}
			tmp = tmp->next;
		}
		current = current->next;
	}
}

/* return (0); */
// Stack sıralı değil.

/* return (1); */
// Stack sıralı.
int	ft_sorted_control(t_list *a)
{
	while (a && a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}
