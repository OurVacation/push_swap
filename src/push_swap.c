/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:26:09 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/02 11:39:02 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	static t_deque	stack[2];

	// stack[0] = a ; stack[1] = b;
	init_stack_a(stack[0], argc, argv);
	if (is_sorted(stack[0]))
		return (0);
	quick_sort_stack(stack);
	return (0);
}
