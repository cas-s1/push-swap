/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 07:30:11 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/08 14:23:04 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				cost_a;
	int				cost_b;
	int				total_cost;
	struct s_stack	*next;
}	t_stack;

// push_swap.c
void	error(t_stack *a, t_stack *b);

// stack.c
int		max_index(t_stack *stack);
int		min_index(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
t_stack	*node_at(t_stack *stack, int index);
int		stack_size(t_stack *stack);

// utils.c
void	free_data(t_stack *a, t_stack *b);
int		is_sorted(t_stack *stack);
int		abs(int n);
void	init_pushswap(t_stack **a, char **av);

// op_push.c
char	*push_a(t_stack **a, t_stack **b);
char	*push_b(t_stack **a, t_stack **b);

// op_swap.c
char	*swap_a(t_stack **a);
char	*swap_b(t_stack **b);
char	*swap_both(t_stack **a, t_stack **b);

// op_rotate.c
char	*rotate_a(t_stack **a);
char	*rotate_b(t_stack **b);
char	*rotate_both(t_stack **a, t_stack **b);

// op_reverse_rotate.c
char	*reverse_rotate_a(t_stack **a);
char	*reverse_rotate_b(t_stack **b);
char	*reverse_rotate_both(t_stack **a, t_stack **b);

// sort.c
void	sort(t_stack **a, t_stack **b);
void	sort_three_a(t_stack **a);

// algo.c
void	large_sort(t_stack *a, t_stack *b);

// algo_utils.c
void	count_steps_a(t_stack *a);
void	count_steps_b(t_stack *a, t_stack *b);
void	total_steps(t_stack *a);
int		min_steps(t_stack *a);

#endif
