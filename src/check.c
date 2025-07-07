/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:27:27 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/07 13:24:59 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_vaild_num(char *str);
int			ft_atoll(const char *str, int *num);
int			is_deque_empty(t_deque *dq);
int			check_dup(t_deque *a, int input);

int	is_vaild_num(char *str)
{
	if (!str || !*str)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	ft_atoll(const char *str, int *num)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
		if (sign * result < INT_MIN || sign * result > INT_MAX)
			return (0);
	}
	if (*str != '\0')
		return (0);
	*num = (int)(sign * result);
	return (1);
}

int	is_deque_empty(t_deque *dq)
{
	if (!dq)
		return (-1);
	if (dq->size == 0)
		return (1);
	else
		return (0);
}

int	check_dup(t_deque *a, int input)
{
	t_node	*cur;

	if (!a)
		return (0);
	cur = a->head;
	while (cur)
	{
		if (cur->data == input)
			return (1);
		cur = cur->next;
	}
	return (0);
}
