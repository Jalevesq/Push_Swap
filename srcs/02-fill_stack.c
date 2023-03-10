/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:12:16 by jalevesq          #+#    #+#             */
/*   Updated: 2023/03/09 16:38:50 by jalevesq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Create and initialize a new node in the linked list
static t_stack	*new_node(int nbr)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = nbr;
	new_node->next = NULL;
	new_node->index = -1;
	new_node->chunk = -1;
	return (new_node);
}

// Initialize the first node of the linked list depending
// on whether there are quotes or not.
static void	args_stack(int ac, char **av, int *i, t_stack **stack_a)
{
	int	error;

	error = 0;
	if (ac == 2)
	{
		*stack_a = new_node(ft_atoi(av[0], &error));
		if (!*stack_a)
			ft_end(1, *stack_a, NULL);
		*i = 1;
	}
	else
	{
		*stack_a = new_node(ft_atoi(av[1], &error));
		if (!*stack_a)
			ft_end(1, *stack_a, NULL);
		*i = 2;
	}
	if (error == 1)
		ft_end(1, *stack_a, NULL);
}

// Fill the linked list with the numbers given as parameters.
t_stack	*ft_fill_list(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*tmp;
	int		i;
	int		error;
	int		number;

	error = 0;
	args_stack(ac, av, &i, &stack_a);
	tmp = stack_a;
	while (av[i])
	{
		number = ft_atoi(av[i], &error);
		if (error == 1)
			ft_end(1, stack_a, NULL);
		tmp->next = new_node(number);
		if (!tmp->next)
			ft_end(1, stack_a, NULL);
		tmp = tmp->next;
		i++;
	}
	return (stack_a);
}

// Set and index to each node.
// Example:
// Value: 450 Index: 4
// Value: 24  Index: 2
// Value: 19  Index: 1
// Value: 45  Index: 3
void	set_index(t_stack *stack, int size)
{
	t_stack	*current;
	int		min;
	int		i;

	i = 0;
	while (size--)
	{
		min = 2147483647;
		current = stack;
		while (current)
		{
			if (current->value < min && current->index == -1)
				min = current->value;
			current = current->next;
		}
		current = stack;
		while (current)
		{
			if (current->value == min && current->index == -1)
				current->index = i++;
			current = current->next;
		}
	}
}

// Assigns a chunk number to each number in the linked list.
// Example:
// If there is 100 numbers
// Chunk 1 = All numbers indexed between 0 and 19 inclusive.
// Chunk 2 = All numbers indexed between 20 and 39 included.
// ...
void	set_chunk(t_stack *stack, int nbr_in_chunk)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		current->chunk = (current->index / nbr_in_chunk) + 1;
		current = current->next;
	}
}
