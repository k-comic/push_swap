/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:33:54 by marvin            #+#    #+#             */
/*   Updated: 2022/02/21 00:33:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				where;
	int				cost;
	struct s_stack	*next;
}	t_stack;

void	ft_error(void);
void	ft_print_stacks(t_stack *one, t_stack *two);
int		ft_atoi(const char *s);
void	ft_algorithm(t_stack **a, t_stack **b);
void	ft_find_mm(t_stack **a, int *min, int *max);
void	swap(t_stack **stack);
void	push(t_stack **from, t_stack **where);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);
int		len_list(t_stack **stack);
int		ft_min_4_int(int a, int b, int c, int d);
int		ft_max_int(int a, int b);
void	ft_empty_b(t_stack **a, t_stack **b);
int		ft_strlen(const char *s);
void	rotate_n(t_stack **stack, char *show, int n);
void	rev_rotate_n(t_stack **stack, char *show, int n);
void	rotate_all_n(t_stack **a, t_stack **b, int n);
void	rev_rotate_all_n(t_stack **a, t_stack **b, int n);
int		ft_check_cost(t_stack **a, t_stack **b);
char	**ft_split(char const *s, char c);
void	free_list(t_stack *elem);
void	ft_check_index(t_stack **stack);

#endif