/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:20:58 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/01 16:33:08 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_stack *src, t_stack *dst)
{
	int	dst_index;

	if (is_full(dst))
		return ;
	dst_index = next_up(dst, dst->top);
	dst->nodes[dst_index].value = src->nodes[src->top].value;
	dst->top = dst_index;
	src->nodes[src->top].value = 0;
	src->top = next_down(src, src->top);
}

void	push_a(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_putendl_fd("pa", 1);
}

void	push_b(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putendl_fd("pa", 1);
}
