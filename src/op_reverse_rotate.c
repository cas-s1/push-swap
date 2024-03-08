/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:38:44 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/08 08:48:16 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*reverse_rotate_a(t_stack **a)
{
	t_stack	*tmp;

	if (stack_size(*a) <= 1)
		return ("reverse rotate a called with not enough items");
	tmp = node_at(*a, stack_size(*a) - 1);
	node_at(*a, stack_size(*a) - 2)->next = NULL;
	tmp->next = *a;
	*a = tmp;
	return ("rra");
}

char	*reverse_rotate_b(t_stack **b)
{
	t_stack	*tmp;

	if (stack_size(*b) <= 1)
		return ("reverse rotate b called with not enough items");
	tmp = node_at(*b, stack_size(*b) - 1);
	node_at(*b, stack_size(*b) - 2)->next = NULL;
	tmp->next = *b;
	*b = tmp;
	return ("rrb");
}

char	*reverse_rotate_both(t_stack **a, t_stack **b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
	return ("rrr");
}
