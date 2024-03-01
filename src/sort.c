/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 08:17:41 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/01 08:23:11 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size < 6)
		sort_five(a, b);
	else
		large_sort(a, b);
}
