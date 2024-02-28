/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:23:02 by co-neill          #+#    #+#             */
/*   Updated: 2024/02/28 20:35:48 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void  error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
static t_stack	*init_stack(t_stack *stack, int size)
{
	stack = (t_stack *) malloc(size * sizeof(t_stack));
	if (!stack)
	{
		ft_putstr_fd("stack bad", 2);
		exit(1);
	}
	return (stack);
}

static void	fill_stack(t_stack *stack, int size, char **args)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		stack[i].value = ft_atoi(args[i]);
		stack[i].cost_a = 0;
		stack[i].cost_b = 0;
		stack[i].total_cost = 0;
	}
}

static void	print_stack(t_stack *a, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		printf("%d\n", a[i].total_cost);
	}
}

void  init_pushswap(t_stack *a, t_stack *b, int ac, char **av)
{	
	a = init_stack(a, ac);
	b = init_stack(b, ac);
	fill_stack(a, ac, av);
	print_stack(a, ac);
}

