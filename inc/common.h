/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:33:25 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/10 14:35:32 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				val;
	int				cost_a;
	int				cost_b;
	int				total_cost;
	struct s_stack	*next;
}	t_stack;

// stack.c
int		max(t_stack *stack);
int		min(t_stack *stack);
int		find_value_index(t_stack *stack, int val);
t_stack	*node_at(t_stack *stack, int index);
int		stack_size(t_stack *stack);

// utils.c
void	free_stack(t_stack **stack);
int		is_sorted(t_stack *stack);
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

#endif
