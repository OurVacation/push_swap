/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:07:28 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/02 12:48:56 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_chunk(t_deque **ab);

void	sort_stack(t_deque **ab)
{

}

void	divide_chunk(t_deque **ab, int n)
{
	int	pivot_sm;
	int	pivot_big;
	int	i;

	pivot_sm = n + ab[0]->size / 3;
	pivot_big = n + ab[0]->size / 3 * 2;
	i = 0;
	if (ab[0]->size <= 5)
	{
		two_to_five_sort(ab);
		return ;
	}
	while (i < ab[0]->size)
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
	devide_chunk(ab, pivot_big);
}
