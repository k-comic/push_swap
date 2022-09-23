/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:08:02 by marvin            #+#    #+#             */
/*   Updated: 2022/02/21 16:08:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	*ft_create_mass(t_stack **elem)
{
	int		*mass;
	int		i;
	t_stack	*tmp;

	i = 1;
	tmp = *elem;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	mass = (int *)malloc(sizeof(int) * (i + 1));
	if (!mass)
		ft_error();
	return (mass);
}

static void	ft_fill_mass(int *mass, t_stack **stack)
{
	int		i;
	t_stack	*elem;

	i = 0;
	elem = *stack;
	while (elem)
	{
		mass[i] = elem->value;
		elem = elem->next;
		i++;
	}
}

static void	ft_sort_mass(int *mass, t_stack **a)
{
	int	i;
	int	flag;
	int	tmp;

	i = 0;
	flag = 1;
	while (flag)
	{
		flag = 0;
		while (i < len_list(a) - 1)
		{
			if (mass[i] > mass[i + 1])
			{
				tmp = mass[i + 1];
				mass[i + 1] = mass[i];
				mass[i] = tmp;
				flag = 1;
				i = 0;
			}
			else
				i++;
		}
	}
}

static void	ft_check_repeat(int *mass, t_stack **a)
{
	int	i;
	int	len;

	i = 0;
	len = len_list(a);
	while (i < (len - 1))
	{
		if (mass[i] == mass[i + 1])
		{
			free(mass);
			free_list(*a);
			ft_error();
		}
		i++;
	}
}

void	ft_find_mm(t_stack **a, int *min, int *max)
{
	int	*mass;

	mass = ft_create_mass(a);
	ft_fill_mass(mass, a);
	ft_sort_mass(mass, a);
	ft_check_repeat(mass, a);
	*min = mass[0];
	*max = mass[len_list(a) - 1];
	free(mass);
}
