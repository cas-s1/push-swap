/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 07:30:11 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/10 14:53:03 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

// sort.c
void	sort(t_stack **a, t_stack **b);
void	sort_three_a(t_stack **a);
int		abs(int n);

// algo.c
void	large_sort(t_stack **a, t_stack **b);

// algo_utils.c
void	count_steps_a(t_stack *a);
void	count_steps_b(t_stack *a, t_stack *b);
void	total_steps(t_stack *a);
int		min_steps(t_stack **a);

#endif
