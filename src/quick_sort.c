/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:34:05 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/03 14:14:41 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	swap_arr(int *a, int *b);
static int	partition(int *arr, int low, int high);
static void	quick_sort(int *arr, int low, int high);
int			*sorted_arr_gen(t_deque *a);
void		nomalize_stack(t_deque *a);

static void	swap_arr(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int *arr, int low, int high)
{
	int pivot;
	int	i;
	int	j;

	pivot = arr[low];
	i = low;
	j = high;
	while (i < j)
	{
		while (arr[i] <= pivot && i <= high - 1)
			i++;
		while (arr[j] > pivot && j >= low + 1)
			j--;
		if (i < j)
			swap_arr(&arr[i], &arr[j]);
	}
	swap_arr(&arr[low], &arr[j]);
	return (j);
}

static void	quick_sort(int *arr, int low, int high)
{
	int	pivot;

	if (low > high)
		return ;
	pivot = partition(arr, low, high);
	quick_sort(arr, low, pivot - 1);
	quick_sort(arr, pivot + 1, high);
}

int	*sorted_arr_gen(t_deque *a)
{
	t_node	*cur;
	int		*arr;
	int		i;

	arr = malloc (sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	i = 0;
	cur = a->head;
	while ((i < a->size) && cur)
	{
		arr[i] = cur->data;
		cur = cur->next;
		i++;
	}
	quick_sort(arr, 0, a->size - 1);
	return (arr);
}

void	nomalize_stack(t_deque *a)
{
	t_node	*cur;
	int		*arr;
	int		i;

	i = 0;
	arr = sorted_arr_gen(a);
	if (!arr)
	{
		ft_printf("sorted_arr_gen() failed");
		return ;
	}
	while (i < a->size)
	{
		cur = a->head;
		while (cur)
		{
			if (arr[i] == cur->data)
				cur->data = i;
			cur = cur->next;
		}
		i++;
	}
	free(arr);
}
