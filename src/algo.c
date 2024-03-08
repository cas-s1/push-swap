/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 07:20:56 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/08 09:50:07 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
/*
static void	move_stack(t_stack *a, t_stack *b, int pos)
{
	int	i;

	i = 0;
	while (i < abs(a->nodes[pos].cost_a))
	{
		if (a->nodes[pos].cost_a > 0)
			rotate_a(a);
		else
			reverse_rotate_a(a);
		pos = min_steps(a);
		i++;
	}
	i = 0;
	while (i < abs(a->nodes[pos].cost_b))
	{
		if (a->nodes[pos].cost_b > 0)
			rotate_b(b);
		else
			reverse_rotate_b(b);
		i++;
	}
}*/
/*
static void	combine(t_stack *a, t_stack *b, int pos)
{
	if (a->nodes[pos].cost_a * a->nodes[pos].cost_b > 0)
	{
		while (a->nodes[pos].cost_a != 0 && a->nodes[pos].cost_b != 0)
		{
			if (a->nodes[pos].cost_a > 0)
			{
				rotate_both(a, b);
				a->nodes[pos].cost_a--;
				a->nodes[pos].cost_b--;
			}
			else
			{
				reverse_rotate_both(a, b);
				a->nodes[pos].cost_a++;
				a->nodes[pos].cost_b++;
			}
		}
		total_steps(a);
		pos = min_steps(a);
	}
	move_stack(a, b, pos);
}
*//*
static void	order_b(t_stack *a, t_stack *b)
{
	while (max_index(b) != b->top)
	{
		if (max_index(b) <= current_size(b) / 2)
			rotate_b(b);
		else
			reverse_rotate_b(b);
	}
	sort_three_a(a);
}*/
/*
static void	move_to_a(t_stack *a, t_stack *b)
{
	t_stack	*a_copy;
	int		i;

	i = 3;
	a_copy = NULL;
	a_copy->nodes = &a->nodes[current_size(a) - i--];
	while (current_size(a_copy))
	{
		if (a_copy->nodes[max_index(a_copy)].value < b->nodes[max_index(b)].value)
			push_a(a, b);
		else
		{
			reverse_rotate_a(a);
			a_copy->nodes = &a->nodes[current_size(a) - i--];
		}
	}
	while (current_size(b))
		push_a(a, b);
}*/
/*
void	large_sort(t_stack *a, t_stack *b)
{
	int	pos;

	push_b(&a, &b);
	push_b(&a, &b);
	while (stack_size(a) > 3)
	{
		count_steps_a(a);
		count_steps_b(a, b);
		total_steps(a);
		pos = min_steps(a);
		if (pos)
			break ;
		//combine(a, b, pos);
		//push_b(a, b);
	}
	//order_b(a, b);
	//move_to_a(a, b);
}*/
