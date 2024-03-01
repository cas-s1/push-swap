/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 08:25:00 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/01 07:35:07 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	next_up(t_stack	*stack, int	index)
{
	if (current_size(stack) == 0)
		return (index);
	if (index == 0)
		return (stack->size - 1);
	else
		return (index - 1);
}

int	next_down(t_stack *stack, int index)
{
	if (current_size(stack) == 0)
		return (index);
	if (index == stack->size - 1)
		return (0);
	else
		return (index + 1);
}

int	value(t_stack *stack, int index)
{
	int	i;

	i = stack->top;
	while (--index > 0)
		i = next_down(stack, i);
	return (stack->nodes[i].value);
}

int	is_full(t_stack *stack)
{
	return (stack->size == current_size(stack));
}

int	current_size(t_stack *stack)
{
	if (stack->top == stack->bottom && stack->nodes[stack->top].value == 0)
		return (0);
	if (stack->top > stack->bottom)
		return ((stack->size - stack->top) + (stack->bottom + 1));
	else
		return (stack->bottom - stack->top + 1);
}
