/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:57:10 by arosas-j          #+#    #+#             */
/*   Updated: 2024/01/29 16:03:58 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*aux;

	if (*src == NULL)
		return ;
	aux = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	aux->prev = NULL;
	if (*dest == NULL)
	{
		*dest = aux;
		aux->next = NULL;
	}
	else
	{
		aux->next = *dest;
		aux->next->prev = aux;
		*dest = aux;
	}
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **stack_b, t_stack_node **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
