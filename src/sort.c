/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 08:17:41 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/03 11:06:36 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

void	sort(t_stack *a, t_stack *b)
{
	if (a->size <= 1 || is_sorted(a))
		return ;
	if (a->size == 2 && b)
		swap_a(a);
	else if (a->size == 3)
		sort_three_a(a);
	/*else if (a->size < 6)
		sort_five(a, b);
	else
		large_sort(a, b);*/
}
