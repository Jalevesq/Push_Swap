/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06-checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:34:36 by jalevesq          #+#    #+#             */
/*   Updated: 2023/03/09 17:06:58 by jalevesq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_double(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*tmp2;

	tmp2 = stack;
	while (tmp2)
	{
		temp = tmp2->next;
		while (temp)
		{
			if (tmp2->value == temp->value)
				return (1);
			temp = temp->next;
		}
		tmp2 = tmp2->next;
	}
	return (0);
}

// Check that there are no duplicate numbers.
int	ft_checker(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	if (ft_double(stack_a) == 1)
		return (1);
	return (0);
}
