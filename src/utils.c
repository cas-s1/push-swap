/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:23:02 by co-neill          #+#    #+#             */
/*   Updated: 2024/02/03 15:58:49 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stack(t_stack *stack)
{
	if (!stack)
		ft_putstr_fd("No nodes!\n", 2);
	while (stack)
	{
		ft_putnbr_fd(stack->number, 1);
		ft_putchar_fd(10, 1);
		stack = stack->next;
	}
}

void	fill_stack(t_stack *stack, char **args, int i)
{
	t_stack	new;

	while (args[++i])
	{
		new = new_stack(args)
