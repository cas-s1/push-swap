/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:23:02 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/10 11:49:26 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static t_stack	*create_node(int val)
{
	t_stack	*new_node;

	new_node = (t_stack *) malloc(sizeof(t_stack));
	if (!new_node)
	{
		ft_putendl_fd("stack bad", 2);
		exit(1);
	}
	new_node->val = val;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->total_cost = 0;
	new_node->next = NULL;
	return (new_node);
}

static void	add_node_back(t_stack **stack, t_stack *new_node)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new_node;
	else
		node_at(*stack, stack_size(*stack) - 1)->next = new_node;
}

void	init_pushswap(t_stack **a, char **av)
{
	t_stack	*new_node;

	while (*av)
	{
		new_node = create_node(ft_atoi(*(av++)));
		add_node_back(a, new_node);
	}
	if (is_sorted(*a))
		exit(0);
}
