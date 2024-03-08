/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 08:25:00 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/08 10:40:37 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	max_index(t_stack *stack)
{
	int	index;
	int	i;

	index = 0;
	i = -1;
	while (stack || i++)
	{
		if (stack->value > node_at(stack, index)->value)
			index = i;
		stack = stack->next;
	}
	return (index);
}

int	min_index(t_stack *stack)
{
	t_stack	*tmp;
	int		min;
	int		i;

	min = stack->value;
	tmp = stack;
	i = 0;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	while (tmp->value != min)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
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
