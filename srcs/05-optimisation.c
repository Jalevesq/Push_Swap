/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05-optimisation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:44:47 by jalevesq          #+#    #+#             */
/*   Updated: 2023/03/09 17:06:01 by jalevesq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Checks which is the fastest path (between ra and rra)
// to get the number on top of the stack and runs it.
void	exec_best_path(t_stack **stack_a, t_chunk *chunk)
{
	if (chunk->first < lstcount(*stack_a) - chunk->last)
		while ((*stack_a)->index != chunk->first_index)
			do_ra(*stack_a);
	else
		while ((*stack_a)->index != chunk->last_index)
			do_rra(stack_a);
}

// Find the distance between the beginning of the stack 
// and the first element of the chunk "chunkcount"
// Find the distance between the last element of the chunk "chunkcount"
// and the end of the stack.
void	best_path_a(t_stack **stack_a, int chunkcount)
{
	t_chunk	chunk;
	t_stack	*tmp;

	init_chunk(&chunk);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->chunk == chunkcount && chunk.first == -1)
		{
			chunk.first = chunk.i;
			chunk.first_index = tmp->index;
		}
		if (tmp->chunk == chunkcount)
		{
			chunk.last = chunk.i;
			chunk.last_index = tmp->index;
		}
		chunk.i++;
		tmp = tmp->next;
	}
	exec_best_path(stack_a, &chunk);
}

// Find the best path (between rb and rrb) to bring the next index
// to the top of the stack and do it
void	best_path_b(t_stack **stack_b, t_stack **stack_a, int size)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack_b;
	while (tmp->index != size && tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	if (i <= lstcount(*stack_b) / 2)
	{
		while ((*stack_b)->index != size)
			do_rb(*stack_b);
	}
	else
	{
		while ((*stack_b)->index != size)
			do_rrb(stack_b);
	}
	do_pa(stack_a, stack_b);
}
