/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:46:12 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/08 08:00:53 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*swap_a(t_stack **a)
{
	t_stack	*tmp;

	if (stack_size(*a) <= 1)
		return ("swap a called with not enough items");
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	return ("sa");
}

char	*swap_b(t_stack **b)
{
	t_stack	*tmp;

	if (stack_size(*b) <= 1)
		return ("swap b called with not enough items");
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	return ("sb");
}

char	*swap_both(t_stack **a, t_stack **b)
{
	swap_a(a);
	swap_b(b);
	return ("ss");
}
