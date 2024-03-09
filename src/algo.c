/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 07:20:56 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/09 14:18:21 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	move_stack(t_stack **a, t_stack **b, int pos)
{
	int	i;

	i = 0;
	while (i < abs(node_at(*a, pos)->cost_a))
	{
		if (node_at(*a, pos)->cost_a > 0)
			ft_putendl_fd(rotate_a(a), 1);
		else
			ft_putendl_fd(reverse_rotate_a(a), 1);
		pos = min_steps(a);
		i++;
	}
	i = 0;
	while (i < abs(node_at(*a, pos)->cost_b))
	{
		if (node_at(*a, pos)->cost_b > 0)
			ft_putendl_fd(rotate_b(b), 1);
		else
			ft_putendl_fd(reverse_rotate_b(b), 1);
		i++;
	}
}

static void	combine(t_stack **a, t_stack **b, int pos)
{
	t_stack	*current;

	current = node_at(*a, pos);
	if (current->cost_a * current->cost_b > 0)
	{
		while (current->cost_a != 0 && current->cost_b != 0)
		{
			if (current->cost_a > 0)
			{
				ft_putendl_fd(rotate_both(a, b), 1);
				current->cost_a--;
				current->cost_b--;
			}
			else
			{
				ft_putendl_fd(reverse_rotate_both(a, b), 1);
				current->cost_a++;
				current->cost_b++;
			}
		}
		total_steps(*a);
		pos = min_steps(a);
	}
	move_stack(a, b, pos);
}

static void	order_b(t_stack **a, t_stack **b)
{
	while ((*b)->val != max(*b))
	{
		if (find_value_index(*b, max(*b)) <= stack_size(*b) / 2)
			ft_putendl_fd(rotate_b(b), 1);
		else
			ft_putendl_fd(reverse_rotate_b(b), 1);
	}
	sort_three_a(a);
}

static void	move_to_a(t_stack **a, t_stack **b)
{
	t_stack	*a_copy;
	int		i;

	i = 3;
	a_copy = node_at(*a, stack_size(*a) - i--);
	while (stack_size(a_copy))
	{
		if (max(a_copy) < max(*b))
			ft_putendl_fd(push_a(a, b), 1);
		else
		{
			ft_putendl_fd(reverse_rotate_a(a), 1);
			a_copy = node_at(*a, stack_size(*a) - i--);
		}
	}
	while (stack_size(*b))
		ft_putendl_fd(push_a(a, b), 1);
}

void	large_sort(t_stack **a, t_stack **b)
{
	int	pos;

	ft_putendl_fd(push_b(a, b), 1);
	ft_putendl_fd(push_b(a, b), 1);
	while (stack_size(*a) > 3)
	{
		count_steps_a(*a);
		count_steps_b(*a, *b);
		total_steps(*a);
		pos = min_steps(a);
		combine(a, b, pos);
		ft_putendl_fd(push_b(a, b), 1);
	}
	order_b(a, b);
	move_to_a(a, b);
}
