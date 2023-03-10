/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03-sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:22:32 by jalevesq          #+#    #+#             */
/*   Updated: 2023/03/09 16:41:18 by jalevesq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Find the best path (between ra and rra) in the stack_a to get to the top
// of the number and push the number into the stack_b.
// Use the chunks to know which number to move up.
static void	sort_one_chunk(t_stack **s_a, t_stack **s_b, int chunkc, int nbrc)
{
	int	i;

	i = 1;
	while (i < nbrc + 1 && (*s_a))
	{
		best_path_a(s_a, chunkc);
		if ((*s_a)->chunk == chunkc)
			do_pb(s_b, s_a);
		i++;
	}
}

// Sort every chunk, one by one.
// 1. Push everything to stack_b chunk by chunk.
// 2. Push everything back to stack_a in order.
void	sort_all_chunk(t_stack **s_a, t_stack **s_b, int nbr_in_chunk)
{
	int	i;
	int	total_chunk;

	i = 1;
	set_chunk(*s_a, nbr_in_chunk);
	total_chunk = chunk_counter(lstcount(*s_a), nbr_in_chunk);
	while (i < total_chunk)
	{
		sort_one_chunk(s_a, s_b, i, nbr_in_chunk);
		i++;
	}
	i = lstcount(*s_b);
	while (i > 0)
	{
		best_path_b(s_b, s_a, i - 1);
		i--;
	}
}
