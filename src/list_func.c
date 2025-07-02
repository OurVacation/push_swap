/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:00:15 by taewonki          #+#    #+#             */
/*   Updated: 2025/06/30 14:21:00 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int data);
void	push_front(t_deque *dq, int data);
void	push_back(t_deque *dq, int data);
int		pop_front(t_deque *dq);
int		pop_tail(t_deque *dq);

t_node	*create_node(int data)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	return (newnode);
}

void	push_front(t_deque *dq, int data)
{
	t_node	*node;

	if (!dq)
		return ;
	node = create_node(data);
	if (node == NULL)
		return ;
	node->next = dq->head;
	if (dq->head)
		dq->head->prev = node;
	else
		dq->tail = node;
	dq->head = node;
	dq->size++;
}

void	push_back(t_deque *dq, int data)
{
	t_node	*node;

	if (!dq)
		return ;
	node = create_node(data);
	if (node == NULL)
		return ;
	node->prev = dq->tail;
	if (dq->tail)
		dq->tail->next = node;
	else
		dq->head = node;
	dq->tail = node;
	dq->size++;
}

int	pop_front(t_deque *dq)
{
	t_node	*temp;
	int		result;

	if (!dq || is_deque_empty(dq))
	{
		ft_printf("pop_front error\n");
		exit(-1);
	}
	temp = dq->head;
	result = temp->data;
	dq->head = temp->next;
	if (dq->head)
		dq->head->prev = NULL;
	else
		dq->tail = NULL;
	dq->size--;
	free(temp);
	return (result);
}

int	pop_tail(t_deque *dq)
{
	t_node	*temp;
	int		result;

	if (!dq || is_deque_empty(dq))
	{
		ft_printf("pop_tail error\n");
		exit(-1);
	}
	temp = dq->tail;
	result = temp->data;
	dq->tail = temp->prev;
	if (dq->tail)
		dq->tail->next = NULL;
	else
		dq->tail = NULL;
	dq->size--;
	free(temp);
	return (result);
}
