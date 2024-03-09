/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 07:49:06 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/09 14:00:44 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdlib.h>

static int	get_target_index(t_stack *a, t_stack *b, int size)
{
	t_stack	*b_copy;
	int		last_val;
	int		index;
	int		i;

	b_copy = b;
	i = -1;
	if (a->val < min(b) || a->val > max(b))
		index = find_value_index(b, max(b));
	else
	{
		last_val = node_at(b, size - 1)->val;
		while (b_copy->next)
		{
			i++;
			if (a->val < b_copy->val && a->val > b_copy->next->val)
				index = i + 1;
			else if (a->val < last_val && a->val > b->val)
				index = 0;
			b_copy = b_copy->next;
		}
	}
	return (index);
}

void	count_steps_a(t_stack *a)
{
	int	stack_pos;
	int	size;

	size = stack_size(a);
	stack_pos = 0;
	while (a)
	{
		if (stack_pos <= (size / 2))
			a->cost_a = stack_pos;
		else
			a->cost_a = stack_pos - size;
		a = a->next;
		stack_pos++;
	}
}

void	count_steps_b(t_stack *a, t_stack *b)
{
	int	target;
	int	size;

	size = stack_size(b);
	while (a)
	{
		target = get_target_index(a, b, size);
		if (target <= size / 2)
			a->cost_b = target;
		else
			a->cost_b = -(size - target);
		a = a->next;
	}
}

void	total_steps(t_stack *a)
{
	while (a)
	{
		if (a->cost_a * a->cost_b < 0)
			a->total_cost = abs(a->cost_a) + abs(a->cost_b);
		else
		{
			if (abs(a->cost_a) > abs(a->cost_b))
				a->total_cost = abs(a->cost_a);
			else
				a->total_cost = abs(a->cost_b);
		}
		a = a->next;
	}
}

int	min_steps(t_stack **a)
{
	int	index;
	int	min_steps;
	int	current_steps;
	int	i;

	i = -1;
	min_steps = 2147483647;
	while (++i < stack_size(*a))
	{
		current_steps = node_at(*a, i)->total_cost;
		if (current_steps < min_steps)
		{
			min_steps = current_steps;
			index = i;
		}
	}
	return (index);
}
