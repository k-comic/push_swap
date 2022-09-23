/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:07:01 by marvin            #+#    #+#             */
/*   Updated: 2022/02/25 17:07:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate_n(t_stack **stack, char *show, int n)
{
	while (n)
	{
		rotate(stack);
		write(1, show, ft_strlen(show));
		n--;
	}
}

void	rev_rotate_n(t_stack **stack, char *show, int n)
{
	while (n)
	{
		rev_rotate(stack);
		write(1, show, ft_strlen(show));
		n--;
	}
}

void	rotate_all_n(t_stack **a, t_stack **b, int n)
{
	while (n)
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
		n--;
	}
}

void	rev_rotate_all_n(t_stack **a, t_stack **b, int n)
{
	while (n)
	{
		rev_rotate(a);
		rev_rotate(b);
		write(1, "rrr\n", 4);
		n--;
	}
}
