/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:46:32 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/08 08:45:34 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*rotate_a(t_stack **a)
{
	t_stack	*tmp;

	if (stack_size(*a) <= 1)
		return ("rotate a called with not enough items");
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	node_at(*a, stack_size(*a) - 1)->next = tmp;
	return ("ra");
}

char	*rotate_b(t_stack **b)
{
	t_stack	*tmp;

	if (stack_size(*b) <= 1)
		return ("rotate b called with not enough items");
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	node_at(*b, stack_size(*b) - 1)->next = tmp;
	return ("rb");
}

char	*rotate_both(t_stack **a, t_stack **b)
{
	rotate_a(a);
	rotate_b(b);
	return ("rr");
}
