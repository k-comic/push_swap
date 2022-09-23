/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 05:26:06 by marvin            #+#    #+#             */
/*   Updated: 2022/02/26 05:26:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_list(t_stack *elem)
{
	t_stack	*next_elem;

	if (elem == NULL)
		return ;
	while (elem->next)
	{
		next_elem = elem->next;
		free(elem);
		elem = next_elem;
	}
	free(elem);
}

void	ft_check_index(t_stack **stack)
{
	int		i;
	t_stack	*elem;

	i = 1;
	elem = *stack;
	while (elem)
	{
		elem->index = i;
		elem = elem->next;
		i++;
	}
}
