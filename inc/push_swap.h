/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 07:30:11 by co-neill          #+#    #+#             */
/*   Updated: 2024/02/22 21:06:02 by co-neill         ###   ########.fr       */
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
	int	*stack;
	int	size;
	int	top;
	int	bottom;
}	t_stack;

typedef struct s_context
{
	t_stack	a;
	t_stack	b;
}	t_context;


// stack.c
t_stack	*init_stack(t_context *context, t_stack *stack, int size);

// utils.c
void	print_stack(t_stack *stack);

#endif
