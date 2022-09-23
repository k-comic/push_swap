/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:33:47 by marvin            #+#    #+#             */
/*   Updated: 2022/02/21 00:33:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_add_tail(t_stack **first, t_stack *new_elem)
{
	t_stack	*elem;

	elem = *first;
	if (*first == NULL)
	{
		*first = new_elem;
		return ;
	}
	while (elem->next != NULL)
		elem = elem->next;
	elem->next = new_elem;
}

static t_stack	*ft_create_elem(t_stack *first_elem, char *str)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (!ptr)
	{
		free_list(first_elem);
		ft_error();
	}
	ptr->value = ft_atoi(str);
	ptr->next = NULL;
	return (ptr);
}

static t_stack	*ft_check_input(int argc, char *argv[])
{
	int		i;
	t_stack	*ptr;
	t_stack	*first_elem;
	char	**splited;
	int		j;

	i = 1;
	first_elem = NULL;
	if (argc < 2)
		exit(0);
	while (i < argc)
	{
		j = 0;
		splited = ft_split(argv[i], ' ');
		while (splited[j])
		{
			ptr = ft_create_elem(first_elem, splited[j]);
			ft_add_tail(&first_elem, ptr);
			free(splited[j]);
			j++;
		}
		free(splited);
		i++;
	}
	return (first_elem);
}

static int	is_sorted(t_stack *elem)
{
	while (elem->next)
	{
		if (elem->value > elem->next->value)
			return (0);
		elem = elem->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = ft_check_input(argc, argv);
	if (a == NULL || is_sorted(a))
		return (0);
	b = NULL;
	ft_algorithm(&a, &b);
	free_list(a);
	return (0);
}
