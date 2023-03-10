/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:13:09 by jalevesq          #+#    #+#             */
/*   Updated: 2023/03/08 10:09:00 by jalevesq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*previous;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;
	previous = NULL;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	current->next = *stack;
	*stack = current;
}

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	do_rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

// Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	do_rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

// rra and rrb at the same time.
void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
