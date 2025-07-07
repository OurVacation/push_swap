/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:44:08 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/07 13:59:21 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		three_sort(t_deque *ab[2]);
void		two_to_five_sort(t_deque *ab[2]);
void		min_to_top(t_deque *ab[2], int min);
int			find_min(t_deque *a);

void	two_to_five_sort(t_deque *ab[2])
{
	int	pb_cnt;

	if (ab[0]->size < 2 || is_deque_empty(ab[0]))
		return ;
	if (ab[0]->size == 2)
		sa(ab);
	if (ab[0]->size == 2)
		return ;
	if (ab[0]->size == 3)
		three_sort(ab);
	if (ab[0]->size == 3)
		return ;
	if (ab[0]->size <= 5)
	{
		pb_cnt = 0;
		while (ab[0]->size > 3)
		{
			min_to_top(ab, find_min(ab[0]));
			pb_cnt++;
			pb(ab);
		}
		three_sort(ab);
		while (pb_cnt--)
			pa(ab);
	}
}

void	min_to_top(t_deque *ab[2], int min)
{
	t_node	*temp;
	int		cnt;

	cnt = 0;
	temp = ab[0]->head;
	while (temp)
	{
		if (temp->data == min)
			break ;
		temp = temp->next;
		cnt++;
	}
	if (cnt < ab[0]->size / 2)
	{
		while (ab[0]->head->data != min)
			ra(ab);
	}
	else
	{
		while (ab[0]->head->data != min)
			rra(ab);
	}
}

void	three_sort(t_deque *ab[2])
{
	int	first;
	int	second;
	int	third;

	first = ab[0]->head->data;
	second = ab[0]->head->next->data;
	third = ab[0]->tail->data;
	if (first < third && third < second)
	{
		sa(ab);
		ra(ab);
	}
	else if (second < first && first < third)
		sa(ab);
	else if (second < third && third < first)
	{
		ra(ab);
		sa(ab);
	}
	else if (third < first && first < second)
		rra(ab);
	else if (third < second && second < first)
		ra(ab);
}

int	find_min(t_deque *a)
{
	t_node	*cur;
	int		min;

	if (!a || is_deque_empty(a))
	{
		ft_printf("find_min() error");
		return (-1);
	}
	cur = a->head;
	min = cur->data;
	while (cur)
	{
		if (cur->data < min)
			min = cur->data;
		cur = cur->next;
	}
	return (min);
}
