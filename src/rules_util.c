/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimtaewon <gimtaewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:56:43 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/04 05:26:47 by gimtaewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_deque *ab);
void	push(t_deque *push, t_deque *pop);
void	rotate(t_deque *ab);
void	reverse_rotate(t_deque *ab);
void	rrr(t_deque **stack);

void	swap(t_deque *ab)
{
	int	temp;

	if (!ab)
		return ;
	if (is_deque_empty(ab) || ab->size == 1)
		return ;
	else
	{
		temp = ab->head->data;
		ab->head->data = ab->head->next->data;
		ab->head->next->data = temp;
	}
}

void	push(t_deque *push, t_deque *pop)
{
	int	temp;

	if (!push || !pop)
		return ;
	if (is_deque_empty(pop))
		return ;
	temp = pop_front(pop);
	push_front(push, temp);
}

void	rotate(t_deque *ab)
{
	t_node	*first;

	if (!ab || !ab->head)
		return ;
	if (ab->size == 1 || is_deque_empty(ab))
		return ;
	else
	{
		first = ab->head;
		ab->head = first->next;
		ab->head->prev = NULL;
		first->next = NULL;
		first->prev = ab->tail;
		ab->tail->next = first;
		ab->tail = first;
	}
}

void	reverse_rotate(t_deque *ab)
{
	t_node	*last;

	if (!ab)
		return ;
	if (ab->size == 1 || is_deque_empty(ab))
		return ;
	else
	{
		last = ab->tail;
		ab->tail = last->prev;
		ab->tail->next = NULL;
		last->prev = NULL;
		last->next = ab->head;
		ab->head->prev = last;
		ab->head = last;
	}
}

void	rrr(t_deque *stack[2])
{
	if (!stack || !*stack)
		return ;
	reverse_rotate(stack[0]);
	reverse_rotate(stack[1]);
	ft_printf("rrr\n");
}
