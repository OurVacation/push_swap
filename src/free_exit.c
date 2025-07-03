/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:29:32 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/03 12:51:01 by taewonki         ###   ########.fr       */
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
		return ;
	while(deque->head)
		pop_front(deque);
	free(deque);
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
	ft_free_list(stack);
	if (to_free)
		ft_free_split(to_free);
	exit(1);
}

void	free_exit(t_deque *ab[2])
{
	ft_free_list(ab[0]);
	ft_free_list(ab[1]);
	exit(0);
}
