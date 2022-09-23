/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 05:30:25 by marvin            #+#    #+#             */
/*   Updated: 2022/02/25 05:30:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_drop(t_stack **a, t_stack **b, int min, int max)
{
	while (len_list(a) > 3)
	{
		if (((*a)->value != min) && ((*a)->value != max))
		{
			push(a, b);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
	}
}

static void	ft_presort(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (len_list(a) < 3)
		return ;
	first = *a;
	second = first->next;
	third = second->next;
	if (((third->value > first->value) && (third->value < second->value))
		|| ((first->value > second->value) && (first->value < third->value))
		|| ((second->value < first->value) && (second->value > third->value)))
	{
		swap(a);
		write(1, "sa\n", 3);
	}
}

static void	ft_final_rotate(t_stack **a)
{
	t_stack	*elem;
	int		min_value;
	int		pos;
	int		ra;
	int		rra;

	elem = *a;
	min_value = 2147483647;
	while (elem)
	{
		if (elem->value < min_value)
		{
			min_value = elem->value;
			pos = elem->index;
		}
		elem = elem->next;
	}
	ra = pos - 1;
	rra = (len_list(a) - ra) % len_list(a);
	if (ra < rra)
		rotate_n(a, "ra\n", ra);
	else
		rev_rotate_n(a, "rra\n", rra);
}

void	ft_algorithm(t_stack **a, t_stack **b)
{
	int	min;
	int	max;

	ft_find_mm(a, &min, &max);
	ft_drop(a, b, min, max);
	ft_presort(a);
	ft_empty_b(a, b);
	ft_final_rotate(a);
}
