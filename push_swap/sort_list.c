/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:20:46 by arosas-j          #+#    #+#             */
/*   Updated: 2024/01/31 13:43:01 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b);
	set_position(*a);
	set_position(*b);
}

static void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
								t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b);
	set_position(*a);
	set_position(*b);
}

void	rotate_one(t_stack_node **stack, t_stack_node *cheapest, char a_or_b)
{
	while (*stack != cheapest)
	{
		if (a_or_b == 'a')
		{
			if (cheapest->above_median == 1)
				ra(stack);
			else
				rra(stack);
		}
		else if (a_or_b == 'b')
		{
			if (cheapest->above_median == 1)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	move_nodes(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*stack_b);
	if (cheapest->above_median == 1 && cheapest->target_node->above_median == 1)
		rotate_both(stack_a, stack_b, cheapest);
	else if (cheapest->above_median == 0
		&& cheapest->target_node->above_median == 0)
		reverse_rotate_both(stack_a, stack_b, cheapest);
	rotate_one(stack_b, cheapest, 'b');
	rotate_one(stack_a, cheapest->target_node, 'a');
	pa(stack_a, stack_b);
}

void	sort_list(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*smallest;

	if (stack_len(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	else
	{
		while (stack_len(*stack_a) > 3)
			pb(stack_b, stack_a);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes(*stack_a, *stack_b);
		move_nodes(stack_a, stack_b);
	}
	set_position(*stack_a);
	smallest = get_smallest(*stack_a);
	if (smallest->above_median)
		while (*stack_a != smallest)
			ra (stack_a);
	else
		while (*stack_a != smallest)
			rra(stack_a);
}
