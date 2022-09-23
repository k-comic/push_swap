/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:52:11 by marvin            #+#    #+#             */
/*   Updated: 2022/02/25 19:52:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_where(t_stack **stack, int value)
{
	t_stack	*elem;

	elem = *stack;
	while (elem->next)
	{
		if ((elem->value < value) && (elem->next->value > value))
			return (elem->next->index);
		elem = elem->next;
	}
	if (elem->next == NULL)
		return (1);
	return (-1000);
}

static int	ft_path_cost(int len_a, int len_b, int pos_a, int pos_b)
{
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;

	rra = (len_a - pos_a + 1) % len_a;
	rrb = (len_b - pos_b + 1) % len_b;
	rr = ft_max_int(pos_a - 1, pos_b - 1);
	rrr = ft_max_int(rra, rrb);
	return (ft_min_4_int(pos_a - 1 + rrb, pos_b - 1 + rra, rr, rrr));
}

int	ft_check_cost(t_stack **a, t_stack **b)
{
	t_stack	*elem;
	int		min_cost;

	elem = *b;
	min_cost = 2147483647;
	while (elem)
	{
		elem->where = ft_where(a, elem->value);
		elem->cost = ft_path_cost(len_list(a), len_list(b),
				elem->where, elem->index);
		if (elem->cost < min_cost)
			min_cost = elem->cost;
		elem = elem->next;
	}
	return (min_cost);
}
