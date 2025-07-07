/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:26:09 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/07 14:05:42 by taewonki         ###   ########.fr       */
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
	ft_free_list(stack[0]);
	ft_free_list(stack[1]);
	return (0);
}
