/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:07:28 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/07 14:24:23 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide_chunk(t_deque **ab, int start, int total_size);
static int	find_first_node(t_deque *a);
void		sort_stack(t_deque *ab[2]);

void	sort_stack(t_deque *ab[2])
{
	int	first;

	if (!ab || !ab[0] || !ab[1])
		return ;
	if (ab[0]->size <= 5)
	{
		two_to_five_sort(ab);
		return ;
	}
	divide_chunk(ab, 0, ab[0]->size);
	while (ab[1]->size)
	{
		calculate_costs(ab);
		choose_move(ab);
	}
	first = find_first_node(ab[0]);
	while (ab[0]->head->data != 0)
	{
		if (first < ab[0]->size / 2)
			ra(ab);
		else
			rra(ab);
	}
	return ;
}

void	divide_chunk(t_deque **ab, int start, int total_size)
{
	int	pivot[2];
	int	cnt;

	pivot[0] = start + (total_size / 3);
	pivot[1] = start + ((total_size * 2) / 3);
	cnt = ab[0]->size;
	if (ab[0]->size <= 5)
	{
		two_to_five_sort(ab);
		return ;
	}
	while (ab[0]->size > 0 && cnt--)
	{
		if (ab[0]->head->data <= pivot[0])
		{
			pb(ab);
			rb(ab);
		}
		else if (ab[0]->head->data < pivot[1])
			pb(ab);
		else
			ra(ab);
	}
	divide_chunk(ab, pivot[1] + 1, ab[0]->size);
}

int	find_first_node(t_deque *a)
{
	t_node	*cur;
	int		cnt;

	cnt = 0;
	cur = a->head;
	while (cur)
	{
		if (cur->data == 0)
			return (cnt);
		cnt++;
		cur = cur->next;
	}
	return (0);
}
