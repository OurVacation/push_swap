/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:44:45 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/07 12:55:47 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_state(t_deque *a, int i);
int		ft_abs(int i);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

void	print_stack_state(t_deque *a, int i)
{
	t_node	*cur;

	if (!a)
		return ;
	cur = a->head;
	if (i == 0)
		ft_printf("stack a : ");
	else
		ft_printf("stack b : ");
	while (cur)
	{
		ft_printf("%d ", cur->data);
		cur = cur->next;
	}
	ft_printf("\n");
}

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != 0)
		count++;
	return (count);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	search;

	search = (unsigned char)c;
	while (*str != 0)
	{
		if (*str == search)
			return ((char *)str);
		str++;
	}
	if (search == '\0')
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	idx;
	size_t	src_len;

	src_len = ft_strlen(src);
	idx = 0;
	if (size == 0)
		return (src_len);
	while (idx < size - 1 && src[idx])
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (src_len);
}
