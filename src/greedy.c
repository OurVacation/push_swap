/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:26:57 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/07 14:55:11 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_insert_pos(t_deque *a, int val);
static t_node	*find_min_cost_node(t_deque *ab[2]);
static void		setting_min_node_pos(t_deque *ab[2], t_node *min_node);
void			calculate_costs(t_deque *ab[2]);
void			choose_move(t_deque *ab[2]);

void	choose_move(t_deque *ab[2])
{
	t_node	*min_node;

	min_node = find_min_cost_node(ab);
	while (min_node->cost_a > 0 && min_node->cost_b > 0)
	{
		rr(ab);
		min_node->cost_a--;
		min_node->cost_b--;
	}
	while (min_node->cost_a < 0 && min_node->cost_b < 0)
	{
		rrr(ab);
		min_node->cost_a++;
		min_node->cost_b++;
	}
	setting_min_node_pos(ab, min_node);
	pa(ab);
}

void	calculate_costs(t_deque *ab[2])
{
	t_node	*cur_b;
	int		size_a;
	int		size_b;
	int		pos_ab[2];

	cur_b = ab[1]->head;
	size_a = ab[0]->size;
	size_b = ab[1]->size;
	pos_ab[1] = 0;
	while (cur_b)
	{
		pos_ab[0] = find_insert_pos(ab[0], cur_b->data);
		if (pos_ab[0] <= size_a / 2)
			cur_b->cost_a = pos_ab[0];
		else
			cur_b->cost_a = -(size_a - pos_ab[0]);
		if (pos_ab[1] <= size_b / 2)
			cur_b->cost_b = pos_ab[1];
		else
			cur_b->cost_b = -(size_b - pos_ab[1]);
		pos_ab[1]++;
		cur_b = cur_b->next;
	}
}

t_node	*find_min_cost_node(t_deque *ab[2])
{
	t_node	*cur;
	t_node	*min_node;
	int		min_total;
	int		cmp_total;

	cur = ab[1]->head;
	min_node = ab[1]->head;
	min_total = ft_abs(cur->cost_a) + ft_abs(cur->cost_b);
	while (cur)
	{
		cmp_total = ft_abs(cur->cost_a) + ft_abs(cur->cost_b);
		if (cmp_total < min_total)
		{
			min_total = cmp_total;
			min_node = cur;
		}
		cur = cur->next;
	}
	return (min_node);
}

static void	setting_min_node_pos(t_deque *ab[2], t_node *min_node)
{
	while (min_node->cost_a > 0)
	{
		ra(ab);
		min_node->cost_a--;
	}
	while (min_node->cost_a < 0)
	{
		rra(ab);
		min_node->cost_a++;
	}
	while (min_node->cost_b > 0)
	{
		rb(ab);
		min_node->cost_b--;
	}
	while (min_node->cost_b < 0)
	{
		rrb(ab);
		min_node->cost_b++;
	}
}

static int	find_insert_pos(t_deque *a, int val)
{
	t_node	*cur;
	t_node	*next_node;
	int		min_max[2];
	int		pos;

	pos = 0;
	cur = a->head;
	find_min_max(a->head, min_max);
	while (pos < a->size)
	{
		next_node = cur->next;
		if (!next_node)
			next_node = a->head;
		if (cur->data < val && val < next_node->data)
			return (pos + 1);
		if ((val > min_max[1] || val < min_max[0])
			&& cur->data == min_max[1] && next_node->data == min_max[0])
			return (pos + 1);
		pos++;
		cur = cur->next;
	}
	return (find_min_val_node_pos(a, min_max[0]));
}
