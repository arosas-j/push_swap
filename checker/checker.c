/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:05:06 by arosas-j          #+#    #+#             */
/*   Updated: 2024/02/01 17:34:26 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strcmp(char *str_1, char *str_2)
{
	while (*str_1 == *str_2
		&& *str_1)
	{
		++str_1;
		++str_2;
	}
	return (*str_1 - *str_2);
}

static void	error(t_stack_node **a, t_stack_node **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	parse_command(t_stack_node **a, t_stack_node **b, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		push(a, b);
	else if (!ft_strcmp(command, "pb\n"))
		push(b, a);
	else if (!ft_strcmp(command, "sa\n"))
		swap(a);
	else if (!ft_strcmp(command, "sb\n"))
		swap(b);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(command, "ra\n"))
		rotate(a);
	else if (!ft_strcmp(command, "rb\n"))
		rotate(b);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(command, "rra\n"))
		reverse_rotate(a);
	else if (!ft_strcmp(command, "rrb\n"))
		reverse_rotate(b);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b);
	else
		error(a, b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*next_line;
	int				len;

	a = NULL;
	b = NULL;
	if (1 == argc)
		return (0);
	stack_init(&a, argv);
	len = stack_len(a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		parse_command(&a, &b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(a) && stack_len(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a);
}
