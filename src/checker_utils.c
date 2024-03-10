/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:22:30 by co-neill          #+#    #+#             */
/*   Updated: 2024/03/10 15:11:35 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

static void	error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	ft_putendl_fd("Error", 2);
	exit (1);
}

static char	*get_next_line(int fd)
{
	char	buffer[10960];
	char	*line;
	ssize_t	i;

	i = 0;
	line = NULL;
	if (fd == -1 || read(fd, &buffer[0], 0) == -1)
		return (NULL);
	while (read(fd, &buffer[i], 1) > 0 && buffer[i++] != '\n')
		continue ;
	if (i == 0)
		return (NULL);
	line = (char *) malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (--i > -1)
		line[i] = buffer[i];
	return (line);
}

static void	check_move(char *move, t_stack **a, t_stack **b)
{
	if (ft_strncmp(move, "pa\n", 3) == 0)
		push_a(a, b);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		push_b(a, b);
	else if (ft_strncmp(move, "sa\n", 3) == 0)
		swap_a(a);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		swap_b(b);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		swap_both(a, b);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		rotate_a(a);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		rotate_b(b);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		rotate_both(a, b);
	else if (ft_strncmp(move, "rra\n", 3) == 0)
		reverse_rotate_a(a);
	else if (ft_strncmp(move, "rrb\n", 3) == 0)
		reverse_rotate_b(b);
	else if (ft_strncmp(move, "rrr\n", 3) == 0)
		reverse_rotate_both(a, b);
	else
		error(a, b);
}

void	checker(t_stack *a, t_stack *b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		check_move(move, &a, &b);
		free(move);
		move = get_next_line(0);
	}
	free(move);
	if (is_sorted(a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}
