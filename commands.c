/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:38:57 by marvin            #+#    #+#             */
/*   Updated: 2022/02/21 22:38:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp_second;
	t_stack	*tmp_third;

	if (((*stack) == NULL) || ((*stack)->next == NULL))
		return ;
	tmp_second = (*stack)->next;
	tmp_third = tmp_second->next;
	tmp_second->next = *stack;
	(*stack)->next = tmp_third;
	*stack = tmp_second;
	ft_check_index(stack);
}

void	push(t_stack **from, t_stack **where)
{
	t_stack	*tmp_from;
	t_stack	*tmp_where;

	if ((*from) == NULL)
		return ;
	tmp_from = (*from)->next;
	tmp_where = (*where);
	(*where) = (*from);
	(*where)->next = tmp_where;
	(*from) = tmp_from;
	ft_check_index(from);
	ft_check_index(where);
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp_second;
	t_stack	*tmp_last;

	if (((*stack) == NULL) || ((*stack)->next == NULL))
		return ;
	tmp_second = (*stack)->next;
	tmp_last = (*stack)->next;
	while (tmp_last->next)
		tmp_last = tmp_last->next;
	tmp_last->next = *stack;
	(*stack)->next = NULL;
	*stack = tmp_second;
	ft_check_index(stack);
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp_predlast;
	t_stack	*tmp_last;

	if (((*stack) == NULL) || ((*stack)->next == NULL))
		return ;
	tmp_predlast = *stack;
	tmp_last = (*stack)->next;
	while (tmp_predlast->next->next)
	{
		tmp_predlast = tmp_last;
		tmp_last = tmp_last->next;
	}
	tmp_predlast->next = NULL;
	tmp_last->next = *stack;
	*stack = tmp_last;
	ft_check_index(stack);
}
