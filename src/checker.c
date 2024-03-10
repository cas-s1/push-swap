/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:23:16 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/10 15:06:09 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

static void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

static long int	ps_atoi(char *s)
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
		error();
	while (ft_isdigit(s[i]))
		res = res * 10 + (s[i++] - 48);
	if (s[i] && !ft_isdigit(s[i]))
		error();
	return (res * sign);
}

static int	compare_atoi(char *s1, char *s2)
{
	long int	i;
	long int	j;

	i = ps_atoi(s1);
	j = ps_atoi(s2);
	return (i - j);
}

static void	parse_args(char **av)
{
	int		i;
	int		j;

	i = -1;
	while (av[++i])
	{
		j = 0;
		if (ps_atoi(av[i]) > INT_MAX || ps_atoi(av[i]) < INT_MIN)
			error();
		while (av[++j])
		{
			if (i != j && !compare_atoi(av[i], av[j]))
				error();
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		exit(0);
	if (ac == 2 && ft_strchr(av[1], 32))
		av = ft_split(av[1], 32);
	else
		av++;
	parse_args(av);
	init_pushswap(&a, av);
	checker(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
