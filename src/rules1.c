/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:23:49 by taewonki          #+#    #+#             */
/*   Updated: 2025/06/30 12:48:55 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra(t_deque **stack);
void		rb(t_deque **stack);
void		rr(t_deque **stack);
void		rra(t_deque **stack);
void		rrb(t_deque **stack);

void	ra(t_deque **stack)
{
	if (!stack || !*stack)
		return ;
	rotate(stack[0]);
	ft_printf("ra\n");
}

void	rb(t_deque **stack)
{
	if (!stack || !*stack)
		return ;
	rotate(stack[1]);
	ft_printf("rb\n");
}

void	rr(t_deque **stack)
{
	if(!stack || !*stack)
		return ;
	rotate(stack[0]);
	rotate(stack[1]);
	ft_printf("rr\n");
}

void	rra(t_deque **stack)
{
	if (!stack || !*stack)
		return ;
	reverse_rotate(stack[0]);
	ft_printf("rra\n");
}

void	rrb(t_deque **stack)
{
	if (!stack || !*stack)
		return ;
	reverse_rotate(stack[1]);
	ft_printf("rrb\n");
}
