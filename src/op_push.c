/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:20:58 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/08 10:49:34 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*push_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (stack_size(*b) == 0)
		return ("push from empty stack b");
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	return ("pa");
}

char	*push_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (stack_size(*a) == 0)
		return ("push from empty stack a");
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	return ("pb");
}
