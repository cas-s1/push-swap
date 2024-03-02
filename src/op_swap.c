/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:46:12 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/03 10:08:23 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap(t_stack *s)
{
	int	temp;

	if (s->nodes[next_down(s, s->top)].value == 0)
		return ;
	temp = s->nodes[next_down(s, s->top)].value;
	s->nodes[next_down(s, s->top)].value = s->nodes[s->top].value;
	s->nodes[s->top].value = temp;
}

void	swap_a(t_stack *a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

void	swap_b(t_stack *b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}
