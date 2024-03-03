/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:23:02 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/04 06:43:45 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_data(t_stack *a, t_stack *b)
{
	if (a->nodes)
		free(a->nodes);
	if (b->nodes)
		free(b->nodes);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i != stack->bottom)
	{
		if (stack->nodes[i].value > stack->nodes[next_down(stack, i)].value)
			return (0);
		i = next_down(stack, i);
	}
	return (1);
}

static t_node	*init_nodes(t_node *node, int size)
{
	node = (t_node *) malloc(size * sizeof(t_node));
	if (!node)
	{
		ft_putendl_fd("stack bad", 2);
		exit(1);
	}
	return (node);
}

static void	fill_nodes(t_stack *stack, int size, char **args)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		stack->nodes[i].value = ft_atoi(args[i]);
		stack->nodes[i].cost_a = 0;
		stack->nodes[i].cost_b = 0;
		stack->nodes[i].total_cost = 0;
	}
	stack->bottom = size - 1;
}

void	init_pushswap(t_stack *a, t_stack *b, int ac, char **av)
{
	t_node	*a_nodes;
	t_node	*b_nodes;

	--ac;
	a_nodes = NULL;
	b_nodes = NULL;
	a_nodes = init_nodes(a_nodes, ac);
	b_nodes = init_nodes(b_nodes, ac);
	a->nodes = a_nodes;
	a->size = ac;
	a->top = 0;
	a->bottom = 0;
	b->nodes = b_nodes;
	b->size = ac - 1;
	b->top = 0;
	b->bottom = 0;
	fill_nodes(a, ac, av);
}
