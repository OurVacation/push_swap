/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:27:31 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/09 12:41:21 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		handle_cmd(char *cmd, t_deque *stack[2]);
static int		handle_stack_cmd_sp(char *cmd, t_deque *stack[2]);
static int		handle_stack_cmd_r(char *cmd, t_deque *stack[2]);
static int		handle_stack_cmd_rr(char *cmd, t_deque *stack[2]);

int	main(int ac, char **av)
{
	static t_deque	a;
	static t_deque	b;
	char			*cmd;
	t_deque			*stack[2];

	if (ac < 3)
		return (0);
	stack[0] = &a;
	stack[1] = &b;
	init_stack_a(stack[0], ac, av);
	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
			break ;
		handle_cmd(cmd, stack);
		free(cmd);
	}
	if (is_sorted(&a) && is_deque_empty(&b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_list(stack[0]);
	ft_free_list(stack[1]);
	return (0);
}

void	handle_cmd(char *cmd, t_deque *stack[2])
{
	if (handle_stack_cmd_sp(cmd, stack))
		return ;
	else if (handle_stack_cmd_r(cmd, stack))
		return ;
	else if (handle_stack_cmd_rr(cmd, stack))
		return ;
	else
		error_free_helper_1(stack[0], stack[1], NULL);
}

static int	handle_stack_cmd_sp(char *cmd, t_deque *stack[2])
{
	if (!ft_strncmp(cmd, "sa", 2) && ft_strlen(cmd) == 3)
	{
		swap(stack[0]);
		return (1);
	}
	else if (!ft_strncmp(cmd, "sb", 2) && ft_strlen(cmd) == 3)
	{
		swap(stack[1]);
		return (1);
	}
	else if (!ft_strncmp(cmd, "ss", 2) && ft_strlen(cmd) == 3)
	{
		swap(stack[0]);
		swap(stack[1]);
		return (1);
	}
	else if (!ft_strncmp(cmd, "pa", 2) && ft_strlen(cmd) == 3)
	{
		push(stack[0], stack[1]);
		return (1);
	}
	else
		return (0);
}

static int	handle_stack_cmd_r(char *cmd, t_deque *stack[2])
{
	if (!ft_strncmp(cmd, "ra", 2) && ft_strlen(cmd) == 3)
	{
		rotate(stack[0]);
		return (1);
	}
	else if (!ft_strncmp(cmd, "pb", 2) && ft_strlen(cmd) == 3)
	{
		push(stack[1], stack[0]);
		return (1);
	}
	else if (!ft_strncmp(cmd, "rb", 2) && ft_strlen(cmd) == 3)
	{
		rotate(stack[1]);
		return (1);
	}
	else if (!ft_strncmp(cmd, "rr", 2) && ft_strlen(cmd) == 3)
	{
		rotate(stack[0]);
		rotate(stack[1]);
		return (1);
	}
	else
		return (0);
}

static int	handle_stack_cmd_rr(char *cmd, t_deque *stack[2])
{
	if (!ft_strncmp(cmd, "rra", 2) && ft_strlen(cmd) == 4)
	{
		reverse_rotate(stack[0]);
		return (1);
	}
	else if (!ft_strncmp(cmd, "rrb", 2) && ft_strlen(cmd) == 4)
	{
		reverse_rotate(stack[1]);
		return (1);
	}
	else if (!ft_strncmp(cmd, "rrr", 2) && ft_strlen(cmd) == 4)
	{
		reverse_rotate(stack[0]);
		reverse_rotate(stack[1]);
		return (1);
	}
	else
		return (0);
}
