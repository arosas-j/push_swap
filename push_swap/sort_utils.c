/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:14:33 by arosas-j          #+#    #+#             */
/*   Updated: 2024/01/31 14:09:17 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_stack_node *stack)
{
	int	position;
	int	median;

	position = 0;
	if (stack == NULL)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->position = position;
		if (position <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		position++;
	}
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*a_node;
	t_stack_node	*target_node;
	long			best_target;

	while (b)
	{
		best_target = LONG_MAX;
		a_node = a;
		while (a_node)
		{
			if (a_node->number > b->number && a_node->number < best_target)
			{
				best_target = a_node->number;
				target_node = a_node;
			}
			a_node = a_node->next;
		}
		if (best_target == LONG_MAX)
			b->target_node = get_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

static void	set_price(t_stack_node *a, t_stack_node *b)
{
	while (b)
	{
		b->cost = b->position;
		if (b->above_median == 0)
			b->cost = stack_len(b) - b->position;
		if (b->target_node->above_median == 1)
			b->cost += b->target_node->position;
		else
			b->cost += stack_len(a) - b->target_node->position;
		b = b->next;
	}
}

t_stack_node	*get_cheapest(t_stack_node *b)
{
	long			best_price;
	t_stack_node	*cheapest_node;

	if (b == NULL)
		return (NULL);
	best_price = LONG_MAX;
	while (b)
	{
		if (b->cost < best_price)
		{
			best_price = b->cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	return (cheapest_node);
}

void	init_nodes(t_stack_node *stack_a, t_stack_node *stack_b)
{
	set_position(stack_a);
	set_position(stack_b);
	set_target_node(stack_a, stack_b);
	set_price(stack_a, stack_b);
}
