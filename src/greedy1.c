/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:23:48 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/07 14:55:52 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_max(t_node *a, int *min_max);

void	find_min_max(t_node *a, int *min_max)
{
	if (!a || !min_max)
	{
		ft_printf("find_min_max() get nullptr\n");
		return ;
	}
	min_max[0] = a->data;
	min_max[1] = a->data;
	while (a)
	{
		if (a->data < min_max[0])
			min_max[0] = a->data;
		if (a->data > min_max[1])
			min_max[1] = a->data;
		a = a->next;
	}
}

int	find_min_val_node_pos(t_deque *a, int min)
{
	int		pos;
	t_node	*cur;

	pos = 0;
	cur = a->head;
	while (cur)
	{
		if (cur->data == min)
			return (pos);
		pos++;
		cur = cur->next;
	}
	return (0);
}
