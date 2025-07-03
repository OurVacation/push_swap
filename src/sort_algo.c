/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:44:08 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/03 14:21:37 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		three_sort(t_deque *ab[2]);
void		two_to_five_sort(t_deque *ab[2]);
void		min_to_top(t_deque *ab[2], int min);
int			find_min(t_deque *a);

void	two_to_five_sort(t_deque *ab[2])
{
	int	min;

	if (ab[0]->size == 2)
	{
		sa(ab);
		return ;
	}
	if (ab[0]->size == 3)
	{
		three_sort(ab);
		return ;
	}
	if (ab[0]->size <= 5)
	{
		while (ab[0]->size > 3)
		{
			min = find_min(ab[0]);
			min_to_top(ab, min);
			pb(ab);
		}
		three_sort(ab);
		while (ab[1]->size > 0)
			pa(ab);
	}
}

void min_to_top(t_deque *ab[2], int min)
{
	t_node	*temp;
	int		cnt;

	cnt = 0;
	temp = ab[0]->head;
	while (temp)
	{
		if (temp->data == min)
			break;
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
		rra(ab);
	else if (third < first && first < second)
		ra(ab);
	else if (third < second && second < first)
	{
		sa(ab);
		rra(ab);
	}
}

int	find_min(t_deque *a)
{
	t_node	*cur;
	int		min;

	if (!a)
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
