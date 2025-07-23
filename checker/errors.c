/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:16:36 by arosas-j          #+#    #+#             */
/*   Updated: 2024/02/01 14:31:45 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*node;

	if (stack == NULL)
		return ;
	node = *stack;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack_node **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_syntax(char *number)
{
	if (!(*number == '+' || *number == '-'
			|| (*number >= '0' && *number <= '9')))
		return (1);
	if ((*number == '+' || *number == '-')
		&& !(number[1] >= '0' && number[1] <= '9'))
		return (1);
	while (*++number)
	{
		if (!(*number >= '0' && *number <= '9'))
			return (1);
	}
	return (0);
}

int	error_repetition(t_stack_node *node, int number)
{
	if (node == NULL)
		return (0);
	while (node)
	{
		if (node->number == number)
			return (1);
		node = node->next;
	}
	return (0);
}
