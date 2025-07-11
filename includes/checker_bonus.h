/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:12:00 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/08 15:41:18 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "libftprintf.h"
# include "get_next_line.h"
# include "libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_node
{
	int				data;
	int				cost_a;
	int				cost_b;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_deque;

//check.c
int		is_vaild_num(char *str);
int		ft_atoll(const char *str, int *num);
int		is_deque_empty(t_deque *dq);
int		check_dup(t_deque *a, int input);

//ft_strncmp.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//free_exit.c
void	ft_free_list(t_deque *deque);
void	ft_free_split(char **str);
void	error_free_helper(t_deque *a, t_deque *b, char **to_free);
void	free_exit(t_deque *ab[2]);

//init.c
void	init_stack_a(t_deque *a, int ac, char **av);
int		is_sorted(t_deque *a);

//list_func.c
t_node	*create_node(int data);
void	push_front(t_deque *dq, int data);
void	push_back(t_deque *dq, int data);
int		pop_front(t_deque *dq);
int		pop_tail(t_deque *dq);

//quick_sort.c
int		*sorted_arr_gen(t_deque *a);
void	nomalize_stack(t_deque *a);

//rules_util.c
void	swap(t_deque *ab);
void	push(t_deque *push, t_deque *pop);
void	rotate(t_deque *ab);
void	reverse_rotate(t_deque *ab);
void	rrr(t_deque *stack[2]);

//rules.c
void	sa(t_deque *stack[2]);
void	sb(t_deque *stack[2]);
void	ss(t_deque *stack[2]);
void	pa(t_deque *stack[2]);
void	pb(t_deque *stack[2]);

//rules1.c
void	ra(t_deque *stack[2]);
void	rb(t_deque *stack[2]);
void	rr(t_deque *stack[2]);
void	rra(t_deque *stack[2]);
void	rrb(t_deque *stack[2]);

//utils.c
void	print_stack_state(t_deque *a, int i);
int		ft_abs(int i);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif
