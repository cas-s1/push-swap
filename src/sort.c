/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 08:17:41 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/04 07:12:11 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	find_smallest(t_stack *a)
{
	long int	min;
	int	i;

	min = 1;
	i = next_down(a, a->top);
	while (i != a->bottom)
	{
		if (value(a, i) < value(a, min))
			min = i;
		i = next_down(a, i);
	}
	return (min);
}

static void	sort_three_a(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = value(a, 1);
	second = value(a, 2);
	third = value(a, 3);
	if (first > second && third > second && third > first)
		swap_a(a);
	else if (first > second && third > second && first > third)
		rotate_a(a);
	else if (second > first && second > third && first > third)
		reverse_rotate_a(a);
	else if (second > first && second > third && third > first)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (first > second && second > third && first > third)
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
}

static void	sort_five_a(t_stack *a, t_stack *b)
{
	int	smallest;

	while (current_size(a) > 3)
	{
		smallest = find_smallest(a);
		if (smallest == 1)
			push_b(a, b);
		else
			rotate_a(a);
	}
	sort_three_a(a);
	if (value(b, 1) < value(b, 2))
		swap_b(b);
	push_a(a, b);
	push_a(a, b);

}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size <= 1 || is_sorted(a))
		return ;
	if (a->size == 2 && b)
		swap_a(a);
	else if (a->size == 3)
		sort_three_a(a);
	else if (a->size < 6)
		sort_five_a(a, b);
	/*else
		large_sort(a, b);*/
}
