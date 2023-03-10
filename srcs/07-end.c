/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07-end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:28:09 by jalevesq          #+#    #+#             */
/*   Updated: 2023/03/09 17:34:58 by jalevesq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Function executed in case of error.
// Free the stack, write an error message and exit the program.
void	ft_end(int flag, t_stack *stack_a, t_stack *stack_b)
{
	if (flag == 1)
	{
		if (stack_a)
			free_list(stack_a);
		if (stack_b)
			free_list(stack_b);
	}
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

// Function to free a linked list
void	free_list(t_stack *head)
{
	t_stack	*tmp;

	if (head)
	{
		while (head)
		{
			tmp = head->next;
			free(head);
			head = tmp;
		}
	}
}
