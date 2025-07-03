/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:07:28 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/03 13:51:37 by taewonki         ###   ########.fr       */
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
	{
		ft_printf("sort_stack() fail\n");
		return ;
	}
	if (ab[0]->size <= 5)
	{
		two_to_five_sort(ab);
		return ;
	}
	divide_chunk(ab, 0, ab[0]->size);
	while (!is_deque_empty(ab[1]))
	{
		calculate_costs(ab);
		choose_move(ab);
	}
	first = find_first_node(ab[0]);
	while(ab[0]->head->data != 0)
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
	int	pivot_sm;
	int	pivot_big;
	int	cnt;

	pivot_sm = start + (total_size / 3);
	pivot_big = start + ((total_size * 2) / 3);
	cnt = ab[0]->size;
	if (ab[0]->size <= 5)
	{
		two_to_five_sort(ab);
		return ;
	}
	while (cnt--)
	{
		if (ab[0]->head->data <= pivot_sm)
		{
			pb(ab);
			rb(ab);
		}
		else if (ab[0]->head->data <= pivot_big)
			pb(ab);
		else
			ra(ab);
	}
	divide_chunk(ab, pivot_big + 1, total_size - (pivot_big + 1));
	ft_printf("------------------------after divide_chunk--------------------------\n");
	print_stack_state(ab[0], 0);
	print_stack_state(ab[1], 1);
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
