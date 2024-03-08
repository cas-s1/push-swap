/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 07:49:06 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/08 09:50:09 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdlib.h>
/*
static int	get_target_index(t_node *a, t_stack *b)
{
	int	index;
	int	last_val;
	int	i;

	i = b->top;
	if (a->value < min_index(b) || a->value > max_index(b))
		index = max_index(b);
	else
	{
		last_val = b->nodes[b->bottom].value;
		while (i != next_down(b, b->bottom))
		{
			if (a->value < b->nodes[i].value
				&& a->value > b->nodes[next_down(b, i)].value)
				index = next_down(b, i);
			else if (a->value < last_val
				&& a->value > b->nodes[i].value)
				index = i;
			i = next_down(b, i);
		}
	}
	return (index);
}

void	count_steps_a(t_stack *a)
{
	int	stack_size;
	int	stack_pos;
	int	i;

	stack_size = current_size(a);
	stack_pos = 0;
	i = a->top;
	while (i != next_down(a, a->bottom))
	{
		if (stack_pos <= (stack_size / 2))
			a->nodes[i].cost_a = stack_pos;
		else
			a->nodes[i].cost_a = stack_pos - stack_size;
		i = next_down(a, i);
		stack_pos++;
	}
}

void	count_steps_b(t_stack *a, t_stack *b)
{
	int	target;
	int	stack_size;
	int	i;

	stack_size = current_size(b);
	i = a->top;
	while (i != next_down(a, a->bottom))
	{
		target = get_target_index(&a->nodes[i], b);
		if (target <= stack_size / 2)
			a->nodes[i].cost_b = target;
		else
			a->nodes[i].cost_b = -(stack_size - target);
		i = next_down(a, i);
	}
}

void	total_steps(t_stack *a)
{
	int	cost_a;
	int	cost_b;
	int	i;

	i = a->top;
	while (i != a->bottom)
	{
		cost_a = a->nodes[i].cost_a;
		cost_b = a->nodes[i].cost_b;
		if (cost_a * cost_b < 0)
			a->nodes[i].total_cost = abs(cost_a) + abs(cost_b);
		else
		{
			if (abs(cost_a) > abs(cost_b))
				a->nodes[i].total_cost = abs(cost_a);
			else
				a->nodes[i].total_cost = abs(cost_b);
		}
		i = next_down(a, i);
	}
}

int	min_steps(t_stack *a)
{
	int	index;
	int	min_steps;
	int	current_steps;
	int	i;

	i = a->top;
	min_steps = 2147483647;
	while (i != a->bottom)
	{
		current_steps = a->nodes[i].total_cost;
		if (current_steps < min_steps)
		{
			min_steps = current_steps;
			index = i;
		}
		i = next_down(a, i);
	}
	return (index);
}*/
