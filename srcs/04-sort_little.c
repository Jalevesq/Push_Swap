/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04-sort_little.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:05:17 by jalevesq          #+#    #+#             */
/*   Updated: 2023/03/09 16:53:41 by jalevesq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Finds the smallest index in the stack passed as parameter.
static int	find_smallest(t_stack **stack_a, int *smallest_index)
{
	t_stack	*tmp;
	int		index;

	*smallest_index = lstcount(*stack_a) + 1;
	index = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < *smallest_index)
			*smallest_index = tmp->index;
		tmp = tmp->next;
	}
	tmp = *stack_a;
	while (tmp->index != *smallest_index)
	{
		index++;
		tmp = tmp->next;
	}
	return (index);
}

// Sorting algorithm for 3 numbers
void	sort_three(t_stack **stack_a)
{
	int	i;
	int	j;
	int	k;

	i = (*stack_a)->index;
	j = (*stack_a)->next->index;
	k = (*stack_a)->next->next->index;
	if (i < j && i < k && j > k)
	{
		do_sa(*stack_a);
		do_ra(*stack_a);
	}
	else if (i > j && i < k && j < k)
		do_sa(*stack_a);
	else if (i < j && i > k && j > k)
		do_rra(stack_a);
	else if (i > j && i > k && j < k)
		do_ra(*stack_a);
	else if (i > j && i > k && j > k)
	{
		do_ra(*stack_a);
		do_sa(*stack_a);
	}
}

// // Sorting algorithm for 4 numbers
void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	index;
	int	smallest_index;

	index = find_smallest(stack_a, &smallest_index);
	if (lstcount(*stack_a) / 2 <= index)
	{
		while ((*stack_a)->index != smallest_index)
			do_rra(stack_a);
	}
	else if (lstcount(*stack_a) / 2 > index)
	{
		while ((*stack_a)->index != smallest_index)
			do_ra(*stack_a);
	}
	if (ft_is_sorted(*stack_a) == 0)
	{
		do_pb(stack_b, stack_a);
		sort_three(stack_a);
		do_pa(stack_a, stack_b);
	}		
}

// // Sorting algorithm for 5 numbers
void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	index;
	int	smallest_index;
	int	i;

	i = 0;
	while (i < 2)
	{
		index = find_smallest(stack_a, &smallest_index);
		while ((*stack_a)->index != smallest_index)
		{
			if (index <= lstcount(*stack_a) / 2)
				do_ra(*stack_a);
			else
				do_rra(stack_a);
		}
		do_pb(stack_b, stack_a);
		i++;
	}
	sort_three(stack_a);
	do_pa(stack_a, stack_b);
	do_pa(stack_a, stack_b);
}
