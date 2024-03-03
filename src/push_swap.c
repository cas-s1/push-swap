/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 07:29:56 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/04 07:13:45 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error(t_stack *a, t_stack *b)
{
	free_data(a, b);
	ft_putendl_fd("Error", 2);
	exit(1);
}

// DELETE BEFORE SUBMISSION
/*static void	print_nodes(t_stack *stack)
{
	int	i;

	i = stack->top;
	printf("%d\n", stack->nodes[i].value);
	while (i != stack->bottom)
	{
		i = next_down(stack, i);
		printf("%d\n", stack->nodes[i].value);
	}
}*/

static long int	ps_atoi(t_stack *a, t_stack *b, char *s)
{
	long int	res;
	int			sign;
	int			i;

	sign = 1;
	res = 0;
	i = 0;
	if (s[i] == 45)
	{
		sign *= -1;
		i++;
	}
	if (!s[i])
		error(a, b);
	while (ft_isdigit(s[i]))
		res = res * 10 + (s[i++] - 48);
	if (s[i] && !ft_isdigit(s[i]))
		error(a, b);
	return (res * sign);
}

static int	compare_atoi(t_stack *a, t_stack *b, char *s1, char *s2)
{
	long int	i;
	long int	j;

	i = ps_atoi(a, b, s1);
	j = ps_atoi(a, b, s2);
	return (i - j);
}

static void	parse_args(t_stack *a, t_stack *b, char **av)
{
	int		i;
	int		j;

	i = -1;
	while (av[++i])
	{
		j = 0;
		if (ps_atoi(a, b, av[i]) > INT_MAX || ps_atoi(a, b, av[i]) < INT_MIN)
			error(a, b);
		while (av[++j])
		{
			if (i != j && !compare_atoi(a, b, av[i], av[j]))
				error(a, b);
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 2 && ft_strchr(av[1], 32))
		av = ft_split(av[1], 32);
	else
		av++;
	parse_args(&a, &b, av);
	init_pushswap(&a, &b, ac, av);
	sort(&a, &b);
	//print_nodes(&a);
	free_data(&a, &b);
	return (0);
}
