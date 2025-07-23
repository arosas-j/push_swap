/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:18:42 by arosas-j          #+#    #+#             */
/*   Updated: 2024/02/01 14:34:31 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_stack_node **dest, t_stack_node **src)
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
