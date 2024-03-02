/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:46:32 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/03 09:43:19 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate(t_stack *stack)
{
	if (is_full(stack))
	{
		stack->bottom = stack->top;
		stack->top = next_down(stack, stack->top);
	}
	else
	{
		stack->bottom = next_down(stack, stack->bottom);
		stack->nodes[stack->bottom].value = stack->nodes[stack->top].value;
		stack->nodes[stack->top].value = 0;
		stack->top = next_down(stack, stack->top);
	}
}

void	rotate_a(t_stack *a)
{
	rotate(a);
	ft_putendl_fd("ra", 1);
}

void	rotate_b(t_stack *b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

void	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
