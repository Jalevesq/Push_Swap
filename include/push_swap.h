/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 08:37:06 by jalevesq          #+#    #+#             */
/*   Updated: 2023/03/09 17:16:05 by jalevesq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack {
	int				index;
	int				value;
	int				chunk;
	struct s_stack	*next;
}	t_stack;

typedef struct s_chunk {
	int	first;
	int	first_index;
	int	last;
	int	last_index;
	int	i;
}	t_chunk;

// All the main functions to make the big algorithm work.
void		sort_all_chunk(t_stack **s_a, t_stack **s_b, int nbr_in_chunk);
t_stack		*ft_fill_list(int ac, char **av);
void		set_index(t_stack *stack, int size);
void		set_chunk(t_stack *stack, int chunknbr);

// All functions that are used to check the given numbers.
int			ft_is_sorted(t_stack *stack);
int			ft_checker(t_stack *stack_a);

// Initialization function and utilities.
void		init_chunk(t_chunk *chunk);
int			chunk_counter(int size, int chunksize);
int			lstcount(t_stack *stack);
long		ft_atoi(const char *str, int *error);

// All optimization functions.
void		exec_best_path(t_stack **stack_a, t_chunk *chunk);
void		best_path_a(t_stack **stack_a, int chunkcount);
void		best_path_b(t_stack **stack_b, t_stack **stack_a, int size);

// All functions to free and end the program.
void		free_list(t_stack *head);
void		ft_free_char(char **array);
void		ft_end(int flag, t_stack *stack_a, t_stack *stack_b);

// All functions for the small algorithm
void		sort_three(t_stack **stack_a);
void		sort_four(t_stack **stack_a, t_stack **stack_b);
void		sort_five(t_stack **stack_a, t_stack **stack_b);

// All movements used in the algorithms.
void		do_sa(t_stack *stack_a);
void		do_sb(t_stack *stack_b);
void		do_ss(t_stack *stack_a, t_stack *stack_b);

void		do_pb(t_stack **stack_b, t_stack **stack_a);
void		do_pa(t_stack **stack_a, t_stack **stack_b);

void		do_ra(t_stack *stack_a);
void		do_rb(t_stack *stack_b);
void		do_rr(t_stack *stack_a, t_stack *stack_b);

void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);

#endif