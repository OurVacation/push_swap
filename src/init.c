/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:18:47 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/03 13:18:35 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		init_stack_a(t_deque *a, int ac, char **av);
int			is_sorted(t_deque *a);
static void	stack_push(t_deque *a, char *str, char **to_free);

void	init_stack_a(t_deque *a, int ac, char **av)
{
	int		i;
	char	**input;

	if (ac < 2)
		return ;
	if (ac == 2)
	{
		i = 0;
		input = ft_split(av[1], ' ');
		if (!input)
			return ;
		while (input[i++])
			stack_push(a, input[i], input);
		ft_free_split(input);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			stack_push(a, av[i], NULL);
			i++;
		}
	}
	ft_printf("---------------after push a-------------------\n");
	print_stack_state(a, 0);
	nomalize_stack(a);
	ft_printf("---------------after nomalize -------------------\n");
	print_stack_state(a, 0);
}

static void	stack_push(t_deque *a, char *str, char **to_free)
{
	int	num;

	if (!is_vaild_num(str))
	{
		error_free_helper(a, to_free);
	}
	if (!ft_atoll(str, &num))
	{
		error_free_helper(a, to_free);
	}
	if (check_dup(a, num))
	{
		error_free_helper(a, to_free);
	}
	push_back(a, num);
}

int is_sorted(t_deque *a)
{
	t_node	*node;

	if (!a || !a->head)
	{
		ft_printf("is_sorted() fail\n");
		return (-1);
	}
	node = a->head;
	while (node->next)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}
