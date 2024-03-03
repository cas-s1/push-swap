/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 07:30:11 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/03 10:20:03 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int	value;
	int	cost_a;
	int	cost_b;
	int	total_cost;
}	t_node;

typedef struct s_stack
{
	t_node	*nodes;
	int		size;
	int		top;
	int		bottom;
}	t_stack;

// push_swap.c
void	error(t_stack *a, t_stack *b);

// stack.c
int		next_up(t_stack *stack, int index);
int		next_down(t_stack *stack, int index);
int		value(t_stack *stack, int index);
int		current_size(t_stack *stack);
int		is_full(t_stack *stack);

// utils.c
void	free_data(t_stack *a, t_stack *b);
int		is_sorted(t_stack *stack);
void	init_pushswap(t_stack *a, t_stack *b, int ac, char **av);

// op_push.c
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);

// op_swap.c
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_both(t_stack *a, t_stack *b);

// op_rotate.c
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_both(t_stack *a, t_stack *b);

// op_reverse_rotate.c
void	reverse_rotate_a(t_stack *a);
void	reverse_rotate_b(t_stack *b);
void	reverse_rotate_both(t_stack *a, t_stack *b);

// sort.c
void	sort(t_stack *a, t_stack *b);

#endif
