/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:18:47 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/08 11:03:01 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		init_stack_a(t_deque *a, int ac, char **av);
int			is_sorted(t_deque *a);
static void	stack_push(t_deque *a, char *str, char **to_free);

void	init_stack_a(t_deque *a, int ac, char **av)
{
	int		i;
	int		j;
	char	**input;

	if (ac < 2)
		return ;
	else
	{
		i = 1;
		while (i < ac)
		{
			input = ft_split(av[i], ' ');
			if (!input || !*input)
				error_free_helper(a, input);
			j = -1;
			while (input[++j])
				stack_push(a, input[j], input);
			ft_free_split(input);
			i++;
		}
	}
	nomalize_stack(a);
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

int	is_sorted(t_deque *a)
{
	t_node	*node;

	if (!a || !a->head)
	{
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
