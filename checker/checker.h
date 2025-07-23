/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:05:26 by arosas-j          #+#    #+#             */
/*   Updated: 2024/02/05 15:59:16 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 4
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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

char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlen(char *s);
char			*ft_strchr(char *s, int c);
void			stack_init(t_stack_node **stack, char **argv);
long			ft_atol(const char *str);
void			add_node(t_stack_node **stack, int number);
void			free_stack(t_stack_node **stack);
void			error_free(t_stack_node **stack);
int				error_syntax(char *number);
int				error_repetition(t_stack_node *node, int number);
void			push(t_stack_node **dest, t_stack_node **src);
void			swap(t_stack_node **stack);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b);
void			rotate(t_stack_node **stack);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b);
void			reverse_rotate(t_stack_node **stack);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b);
t_stack_node	*get_last_node(t_stack_node *node);
int				stack_len(t_stack_node *stack);
int				is_sorted(t_stack_node *stack);

#endif