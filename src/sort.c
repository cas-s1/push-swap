/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 08:17:41 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/08 14:30:06 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three_a(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = node_at(*a, 0)->value;
	second = node_at(*a, 1)->value;
	third = node_at(*a, 2)->value;
	if (first > second && third > second && third > first)
		ft_putendl_fd(swap_a(a), 1);
	else if (first > second && third > second && first > third)
		ft_putendl_fd(rotate_a(a), 1);
	else if (second > first && second > third && first > third)
		ft_putendl_fd(reverse_rotate_a(a), 1);
	else if (second > first && second > third && third > first)
	{
		ft_putendl_fd(swap_a(a), 1);
		ft_putendl_fd(rotate_a(a), 1);
	}
	else if (first > second && second > third && first > third)
	{
		ft_putendl_fd(swap_a(a), 1);
		ft_putendl_fd(reverse_rotate_a(a), 1);
	}
}

static void	sort_five_a(t_stack **a, t_stack **b)
{
	int	smallest;

	while (stack_size(*a) > 3)
	{
		smallest = min_index(*a);
		if (smallest == 0)
			ft_putendl_fd(push_b(a, b), 1);
		else if (smallest < stack_size(*a) / 2)
			ft_putendl_fd(rotate_a(a), 1);
		else
			ft_putendl_fd(reverse_rotate_a(a), 1);
	}
	sort_three_a(a);
	while (stack_size(*b))
		ft_putendl_fd(push_a(a, b), 1);
}

void	sort(t_stack **a, t_stack **b)
{
	if (stack_size(*a) <= 1 || is_sorted(*a))
		return ;
	if (stack_size(*a) == 2)
		ft_putendl_fd(swap_a(a), 1);
	else if (stack_size(*a) == 3)
		sort_three_a(a);
	else if (stack_size(*a) < 6)
		sort_five_a(a, b);
	/*else
		large_sort(a, b);*/
}
