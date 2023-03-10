/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:52:31 by jalevesq          #+#    #+#             */
/*   Updated: 2023/03/08 10:18:24 by jalevesq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_swap_first_two(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
	tmp = stack->chunk;
	stack->chunk = stack->next->chunk;
	stack->next->chunk = tmp;
}

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	do_sa(t_stack *stack_a)
{
	ft_swap_first_two(stack_a);
	ft_putstr_fd("sa\n", 1);
}

// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	do_sb(t_stack *stack_b)
{
	ft_swap_first_two(stack_b);
	ft_putstr_fd("sb\n", 1);
}

//  sa and sb at the same time.
void	do_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap_first_two(stack_a);
	ft_swap_first_two(stack_b);
	ft_putstr_fd("ss\n", 1);
}
