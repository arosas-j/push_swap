/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:12:48 by arosas-j          #+#    #+#             */
/*   Updated: 2024/02/05 15:58:38 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	add_node(t_stack_node **stack, int number)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (NULL == stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->number = number;
	if (NULL == *stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

long	ft_atol(const char *str)
{
	long	n;
	size_t	i;
	int		negative;

	n = 0;
	i = 0;
	negative = 1;
	while (str[i] == ' ' || str[i] == '\t' || str [i] == '\v' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * negative);
}

void	stack_init(t_stack_node **stack, char **argv)
{
	long	number;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(stack);
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			error_free(stack);
		if (error_repetition(*stack, (int)number))
			error_free(stack);
		add_node(stack, (int)number);
		++i;
	}
}
