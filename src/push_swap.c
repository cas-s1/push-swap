/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 07:29:56 by co-neill          #+#    #+#             */
/*   Updated: 2024/02/26 08:38:30 by co-neill         ###   ########.fr       */
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

	i = -1;
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
	//t_context context;
	//int		  *numbers;

	if (ac == 2 && ft_strchr(av[1], 32))
		av = ft_split(av[1], 32);
	else
		av++;
	parse_args(av);
	//init_pushswap(&context, ac, av);
	return (0);
}
