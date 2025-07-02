/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:48:02 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/02 11:06:23 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_node
{
	int	data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	size_t	size;
	t_node	*head;
	t_node	*tail;
}	t_deque;

char		**ft_split(char const *s, char c);

void		sort(t_deque **ab, int **arr);
void		three_sort(t_deque **ab);
void		two_to_five_sort(t_deque *ab);
void		min_to_top(t_deque **ab, int min);
int			find_min(t_deque *a);

t_node		*create_node(int data);
void		push_front(t_deque *dq, int data);
void		push_back(t_deque *dq, int data);
int			pop_front(t_deque *dq);
int			pop_tail(t_deque *dq);

void		ft_free_list(t_deque *deque);
void		ft_free_split(char **str);
void		error_free_helper(t_deque *stack, char **to_free)
void		free_exit(t_deque **ab);

int			is_vaild_num(char *str);
int			ft_atoll(const char *str, int *num);
int			is_deque_empty(t_deque *dq);
int			check_dup(t_deque *a, int input);

void		init_stack_a(t_deque *a, int ac, char **av);
int			is_sorted(t_deque *a);

void		swap(t_deque *ab);
void		push(t_deque *push, t_deque *pop);
void		rotate(t_deque *ab);
void		reverse_rotate(t_deque *ab);
void		rrr(t_deque **stack);

void		sa(t_deque **stack);
void		sb(t_deque **stack);
void		ss(t_deque **stack);
void		pa(t_deque **stack);
void		pb(t_deque **stack);

void		ra(t_deque **stack);
void		rb(t_deque **stack);
void		rr(t_deque **stack);
void		rra(t_deque **stack);
void		rrb(t_deque **stack);

#endif
