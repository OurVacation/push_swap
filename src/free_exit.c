/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:29:32 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/09 12:37:10 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_list(t_deque *deque);
void	ft_free_split(char **str);
void	error_free_helper(t_deque *stack, char **to_free);
void	free_exit(t_deque *ab[2]);

void	ft_free_list(t_deque *deque)
{
	if (!deque)
	{
		ft_printf("ft_free_list()'s input is NULL\n");
		return ;
	}
	while (deque->head)
		pop_front(deque);
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	error_free_helper(t_deque *stack, char **to_free)
{
	ft_printf("Error\n");
	if (stack)
		ft_free_list(stack);
	if (to_free)
		ft_free_split(to_free);
	exit(1);
}

void	error_free_helper_1(t_deque *a, t_deque *b, char **to_free)
{
	if (a)
		ft_free_list(a);
	if (b)
		ft_free_list(b);
	if (to_free)
		ft_free_split(to_free);
	ft_printf("Error\n");
	exit(1);
}

void	free_exit(t_deque *ab[2])
{
	ft_free_list(ab[0]);
	ft_free_list(ab[1]);
	exit(0);
}
