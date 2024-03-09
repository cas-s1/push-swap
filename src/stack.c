/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 08:25:00 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/09 13:57:00 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	max(t_stack *stack)
{
	int		max;

	if (!stack)
		return (0);
	max = stack->val;
	while (stack)
	{
		if (stack->val > max)
			max = stack->val;
		stack = stack->next;
	}
	return (max);
}

int	min(t_stack *stack)
{
	int		min;

	if (!stack)
		return (0);
	min = stack->val;
	while (stack)
	{
		if (stack->val < min)
			min = stack->val;
		stack = stack->next;
	}
	return (min);
}

int	find_value_index(t_stack *stack, int val)
{
	int	i;

	i = -1;
	while (stack)
	{
		i++;
		if (stack->val == val)
			return (i);
		stack = stack->next;
	}
	return (-1);
}

t_stack	*node_at(t_stack *stack, int index)
{
	while (index-- > 0)
		stack = stack->next;
	return (stack);
}

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
