/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:52:28 by arosas-j          #+#    #+#             */
/*   Updated: 2024/01/31 13:44:37 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*get_highest(t_stack_node *stack)
{
	int				highest;
	t_stack_node	*highest_node;

	if (stack == NULL)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->number > highest)
		{
			highest = stack->number;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*highest_node;

	highest_node = get_highest(*stack);
	if (*stack == highest_node)
		ra(stack);
	else if ((*stack)->next == highest_node)
		rra(stack);
	if ((*stack)->number > (*stack)->next->number)
		sa(stack);
}

void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
	while (stack_len(*stack_a) > 3)
	{
		init_nodes(*stack_a, *stack_b);
		rotate_one(stack_a, get_smallest(*stack_a), 'a');
		pb(stack_b, stack_a);
	}
}
