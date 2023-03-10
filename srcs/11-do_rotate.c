/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:38:36 by jalevesq          #+#    #+#             */
/*   Updated: 2023/03/08 10:08:53 by jalevesq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Rotate each value inside the node.
static void	rotate(t_stack *stack)
{
	int	tmp;

	while (stack->next)
	{
		tmp = stack->value;
		stack->value = stack->next->value;
		stack->next->value = tmp;
		tmp = stack->index;
		stack->index = stack->next->index;
		stack->next->index = tmp;
		tmp = stack->chunk;
		stack->chunk = stack->next->chunk;
		stack->next->chunk = tmp;
		stack = stack->next;
	}
}

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	do_ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	do_rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

// ra and rb at the same time.
void	do_rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
