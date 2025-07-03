/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:53:41 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/03 13:20:32 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa(t_deque *stack[2]);
void		sb(t_deque *stack[2]);
void		ss(t_deque *stack[2]);
void		pa(t_deque *stack[2]);
void		pb(t_deque *stack[2]);

void	sa(t_deque *stack[2])
{
	if (!stack || !*stack)
		return ;
	swap(stack[0]);
	ft_printf("sa\n");
}

void	sb(t_deque *stack[2])
{
	if (!stack || !*stack)
		return ;
	swap(stack[1]);
	ft_printf("sb\n");
}

void	ss(t_deque *stack[2])
{
	if (!stack || !*stack)
		return ;
	swap(stack[0]);
	swap(stack[1]);
	ft_printf("ss\n");
}

void	pa(t_deque *stack[2])
{
	if (!stack || !*stack)
		return ;
	push(stack[0], stack[1]);
	ft_printf("pa\n");
}

void	pb(t_deque *stack[2])
{
	if (!stack || !*stack)
		return ;
	push(stack[1], stack[0]);
	ft_printf("pb\n");
}
