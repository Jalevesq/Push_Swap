/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08-utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:20:32 by jalevesq          #+#    #+#             */
/*   Updated: 2023/03/09 17:13:37 by jalevesq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Count the number of nodes in a linked list.
int	lstcount(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

// Initialize all values inside a struct t_chunk.
void	init_chunk(t_chunk *chunk)
{
	chunk->first = -1;
	chunk->first_index = -1;
	chunk->last = -1;
	chunk->last_index = -1;
	chunk->i = 0;
}

// Checks if the linked list in parameter is sorted
int	ft_is_sorted(t_stack *stack)
{
	t_stack	*tmp;
	int		i;
	int		count;

	i = 0;
	count = lstcount(stack);
	tmp = stack;
	while ((tmp && tmp->next) && tmp->index < tmp->next->index)
	{
		tmp = tmp->next;
		i++;
	}
	if (i + 1 == count)
		return (1);
	return (0);
}

// Function to free a variable char **.
void	ft_free_char(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

// Function to count the number of chunks.
int	chunk_counter(int size, int chunksize)
{
	int	chunknbr;

	chunknbr = (size / chunksize) + 1;
	if (size % chunksize != 0)
		chunknbr += 1;
	return (chunknbr);
}
