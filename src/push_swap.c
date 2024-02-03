/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 07:29:56 by co-neill          #+#    #+#             */
/*   Updated: 2024/02/03 16:00:25 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static long int	pushswap_atoi(char *s)
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

	i = pushswap_atoi(s1);
	j = pushswap_atoi(s2);
	return (i - j);
}

static void	parse_args(char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		if (pushswap_atoi(av[i]) > INT_MAX || pushswap_atoi(av[i]) < INT_MIN)
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
	char	**args;
	t_stack	*new;
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 0;
	a = 0;
	b = 0;
	args = av;
	if (ac == 2 && ft_strchr(args[1], 32) && --i)
	{
		args = ft_split(args[1], 32);
		parse_args(args);
	}
	parse_args(args);
	while (args[++i])
	{
		new = new_stack(pushswap_atoi(args[i]));
		stackadd_bottom(&a, new);
	}
	return (0);
}
