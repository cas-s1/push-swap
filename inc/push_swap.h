/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 07:30:11 by co-neill          #+#    #+#             */
/*   Updated: 2024/02/28 20:26:12 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_stack
{
	int	value;
	int	cost_a;
	int	cost_b;
	int	total_cost;
}	t_stack;

// stack.c

// utils.c
void  error(void);
void  init_pushswap(t_stack *a, t_stack *b, int ac, char **av);

#endif
