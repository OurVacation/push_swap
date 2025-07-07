/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:23:48 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/07 13:25:08 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_max(t_node *a, int *min_max);

void	find_min_max(t_node *a, int *min_max)
{
	if (!a || !min_max)
	{
		ft_printf("find_min_max in find_insert_pos is crash\n");
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
