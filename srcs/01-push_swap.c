/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:13:26 by jalevesq          #+#    #+#             */
/*   Updated: 2023/03/13 10:41:24 by jalevesq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Function that manages which algorithm is used and the size of
// the chunk depending on the size of the stack. 
void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	set_index(*stack_a, lstcount(*stack_a));
	if (ft_is_sorted(*stack_a) == 1)
	{
		free_list(*stack_a);
		exit(EXIT_SUCCESS);
	}
	else if (size == 2)
		do_sa(*stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else if (size <= 21 && size > 5)
		sort_all_chunk(stack_a, stack_b, 4);
	else if (size <= 200 && size > 21)
		sort_all_chunk(stack_a, stack_b, 22);
	else if (size <= 550 && size > 200)
		sort_all_chunk(stack_a, stack_b, 44);
	else
		sort_all_chunk(stack_a, stack_b, 75);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**array;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
		stack_a = ft_fill_list(argc, array);
		ft_free_char(array);
	}
	else
		stack_a = ft_fill_list(argc, argv);
	stack_b = NULL;
	if (ft_checker(stack_a) != 0)
		ft_end(1, stack_a, NULL);
	push_swap(&stack_a, &stack_b, lstcount(stack_a));
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
