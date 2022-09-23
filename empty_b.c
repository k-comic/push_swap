/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:57:26 by marvin            #+#    #+#             */
/*   Updated: 2022/02/25 16:57:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_rr(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	if ((pos_b - 1) > (pos_a - 1))
	{
		rotate_n(b, "rb\n", pos_b - 1 - pos_a + 1);
		rotate_all_n(a, b, pos_a - 1);
	}
	else
	{
		rotate_n(a, "ra\n", pos_a - 1 - pos_b + 1);
		rotate_all_n(a, b, pos_b - 1);
	}
}

static void	ft_rrr(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	if ((len_list(b) - pos_b + 1) % len_list(b)
		> (len_list(a) - pos_a + 1) % len_list(a))
	{
		rev_rotate_n(b, "rrb\n", (len_list(b) - pos_b + 1) % len_list(b)
			- ((len_list(a) - pos_a + 1) % len_list(a)));
		rev_rotate_all_n(a, b, (len_list(a) - pos_a + 1) % len_list(a));
	}
	else
	{
		rev_rotate_n(a, "rra\n", (len_list(a) - pos_a + 1) % len_list(a)
			- (len_list(b) - pos_b + 1) % len_list(b));
		rev_rotate_all_n(a, b, (len_list(b) - pos_b + 1) % len_list(b));
	}
}

static void	ft_move_and_print(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;

	rra = (len_list(a) - pos_a + 1) % len_list(a);
	rrb = (len_list(b) - pos_b + 1) % len_list(b);
	rr = ft_max_int(pos_a - 1, pos_b - 1);
	rrr = ft_max_int(rra, rrb);
	if (pos_a - 1 + rrb == ft_check_cost(a, b))
	{
		rotate_n(a, "ra\n", pos_a - 1);
		rev_rotate_n(b, "rrb\n", rrb);
	}
	else if (pos_b - 1 + rra == ft_check_cost(a, b))
	{
		rotate_n(b, "rb\n", pos_b - 1);
		rev_rotate_n(a, "rra\n", rra);
	}
	else if (rr == ft_check_cost(a, b))
		ft_rr(a, b, pos_a, pos_b);
	else if (rrr == ft_check_cost(a, b))
		ft_rrr(a, b, pos_a, pos_b);
	push(b, a);
	write(1, "pa\n", 3);
}

void	ft_empty_b(t_stack **a, t_stack **b)
{
	int		min_cost;
	t_stack	*elem;

	elem = *b;
	ft_check_index(a);
	ft_check_index(b);
	while (elem)
	{
		min_cost = ft_check_cost(a, b);
		if (elem->cost == min_cost)
		{
			ft_move_and_print(a, b, elem->where, elem->index);
			elem = *b;
		}
		else
			elem = elem->next;
	}
}
