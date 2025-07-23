/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:27:58 by arosas-j          #+#    #+#             */
/*   Updated: 2024/02/05 15:59:04 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					number;
	int					position;
	int					cost;
	int					above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;	
}						t_stack_node;

void			stack_init(t_stack_node **stack, char **argv);
int				error_syntax(char *number);
void			error_free(t_stack_node **stack);
void			free_stack(t_stack_node **stack);
long			ft_atol(const char *str);
int				error_repetition(t_stack_node *node, int number);
void			add_node(t_stack_node **stack, int number);
t_stack_node	*get_last_node(t_stack_node *node);
int				is_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
void			sa(t_stack_node **stack);
void			sb(t_stack_node **stack);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b);
void			pa(t_stack_node **stack_a, t_stack_node **stack_b);
void			pb(t_stack_node **stack_b, t_stack_node **stack_a);
void			ra(t_stack_node **stack);
void			rb(t_stack_node **stack);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b);
void			rra(t_stack_node **stack);
void			rrb(t_stack_node **stack);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_three(t_stack_node **stack);
void			sort_five(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_list(t_stack_node **stack_a, t_stack_node **stack_b);
t_stack_node	*get_smallest(t_stack_node *stack);
void			init_nodes(t_stack_node *stack_a, t_stack_node *stack_b);
void			set_position(t_stack_node *stack);
void			set_target_node(t_stack_node *stack_a, t_stack_node *stack_b);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			rotate_one(t_stack_node **stack, t_stack_node *node, char ab);

#endif