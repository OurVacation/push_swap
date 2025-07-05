/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimtaewon <gimtaewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:26:09 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/04 05:30:48 by gimtaewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	static t_deque	a;
	static t_deque	b;
	t_deque			*stack[2];

	stack[0] = &a;
	stack[1] = &b;
	init_stack_a(stack[0], argc, argv);
	if (is_sorted(stack[0]))
		free_exit(stack);
	sort_stack(stack);
	ft_printf("-----------------sort_stack()-----------------\n");
	print_stack_state(stack[0], 0);
	print_stack_state(stack[1], 1);
	ft_free_list(stack[0]);
	ft_free_list(stack[1]);
	return (0);
}
