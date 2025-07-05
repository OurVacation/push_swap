/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimtaewon <gimtaewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:07:28 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/04 05:39:23 by gimtaewon        ###   ########.fr       */
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
	print_stack_state(ab[0], 0);
	print_stack_state(ab[1], 1);
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
	static int	recursion_depth = 0;
	recursion_depth++;
	ft_printf("divide_chunk() : recursion_depth = %d\n", recursion_depth);
	ft_printf("divide_chunk() : start = %d, total_size = %d\n", start, total_size);
	ft_printf("divide_chunk() : ab[0]->size = %d\n", ab[0]->size);
	int	pivot_sm;
	int	pivot_big;
	int	cnt;

	pivot_sm = start + (total_size / 3);
	pivot_big = start + ((total_size * 2) / 3);
	cnt = ab[0]->size;
	if (is_deque_empty(ab[0]))
		return ;
	if (ab[0]->size <= 5)
	{
		two_to_five_sort(ab);
		return ;
	}
	int i = 0;
	while (ab[0]->size > 0 && cnt--)
	{
		ft_printf("divide_chunk() : %d\n",i);
		ft_printf("pivot_sm : %d, pivot_big : %d\n", pivot_sm, pivot_big);
		if (ab[0]->head->data <= pivot_sm)
		{
			pb(ab);
			rb(ab);
		}
		else if (ab[0]->head->data <= pivot_big)
			pb(ab);
		else
			ra(ab);
		i++;
	}
	divide_chunk(ab, pivot_big + 1, ab[0]->size);
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
