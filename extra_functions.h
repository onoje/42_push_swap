/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoje <onoje@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:47:47 by onoje             #+#    #+#             */
/*   Updated: 2025/02/08 15:38:43 by onoje            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_FUNCTIONS_H
# define EXTRA_FUNCTIONS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

// extra_functions_1.c
void		ft_write_str_and_new_line(const char *str);
void		ft_write_error_and_new_line(const char *str);
int			ft_is_number(const char *str);
long long	ft_long_atoi(const char *str);

// extra_functions_2.c, extra_functions_3.c
// Bu iki dosya sadece **ft_split fonksiyonu için gereklidir.
size_t		ft_strlen(const char *s);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);

// extra_functions_4.c
t_list		*ft_stack_new(int content);
void		ft_stack_add_back(t_list **stack, t_list *new);
int			ft_stack_size(t_list *stack);
void		ft_stack_free(t_list *stack);

#endif
