/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:38:44 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/03 09:44:31 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	if (is_full(stack))
	{
		stack->top = stack->bottom;
		stack->bottom = next_up(stack, stack->bottom);
	}
	else
	{
		stack->top = next_up(stack, stack->top);
		stack->nodes[stack->top].value = stack->nodes[stack->bottom].value;
		stack->nodes[stack->bottom].value = 0;
		stack->bottom = next_up(stack, stack->bottom);
	}
}

void	reverse_rotate_a(t_stack *a)
{
	reverse_rotate(a);
	ft_putendl_fd("rra", 1);
}

void	reverse_rotate_b(t_stack *b)
{
	reverse_rotate(b);
	ft_putendl_fd("rrb", 1);
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
}
