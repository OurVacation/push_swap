/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:44:45 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/08 15:41:35 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_state(t_deque *a, int i);
int		ft_abs(int i);

void	print_stack_state(t_deque *a, int i)
{
	t_node	*cur;

	if (!a)
		return ;
	cur = a->head;
	if (i == 0)
		ft_printf("stack a : ");
	else
		ft_printf("stack b : ");
	while (cur)
	{
		ft_printf("%d ", cur->data);
		cur = cur->next;
	}
	ft_printf("\n");
}

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}
