/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:42:56 by fcullen           #+#    #+#             */
/*   Updated: 2022/11/23 10:54:07 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	partition(int *arr, int start, int end)
{
	int	pivot_val;
	int	i;
	int	j;

	pivot_val = arr[end];
	j = start;
	i = start;
	while (j < end)
	{
		if (arr[j] <= pivot_val)
		{	
			ft_swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	ft_swap(&arr[i], &arr[end]);
	return (i);
}

void	quicksort(int *arr, int start, int end)
{
	int	p;

	p = 0;
	if (start < end)
	{
		p = partition(arr, start, end);
		quicksort(arr, start, p - 1);
		quicksort(arr, p + 1, end);
	}
}
