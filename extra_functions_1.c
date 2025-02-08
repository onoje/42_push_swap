/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoje <onoje@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:16:56 by onoje             #+#    #+#             */
/*   Updated: 2025/02/08 15:59:24 by onoje            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sadece okuma yaptığımız için,
// verinin değiştirilmesini önlemek amacıyla const kullanıyoruz.

/* write(1, str, 1); */
// 1 standart output belirtir.
void	ft_write_str_and_new_line(const char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write (1, "\n", 1);
}

/* write(2, str, 1); */
// 2 standart error belirtir.
void	ft_write_error_and_new_line(const char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
	write (2, "\n", 1);
}

int	ft_is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' && str[1] != '\0')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

// long long, -9223372036854775808 ile 9223372036854775807 arasında değer tutar.
// 64-bit işaretli tamsayı.

// Önce long long olarak saklayıp, 
// sonra int sınırları içinde olup olmadığını kontrol etmek daha güvenlidir.
long long	ft_long_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * sign);
}
