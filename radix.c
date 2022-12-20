/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:35:54 by fcullen           #+#    #+#             */
/*   Updated: 2022/11/23 11:08:47 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*lst_to_arr(t_list *a)
{
	int	*array;
	int	i;
	int	lst_size;

	array = malloc(sizeof(int) * ft_lstsize(a) + 1);
	i = -1;
	lst_size = ft_lstsize(a);
	while (++i < lst_size)
	{
		array[i] = a->content;
		a = a->next;
	}
	return (array);
}

void	normalize(t_list *a)
{
	int		i;
	int		*int_arr;
	t_list	*current;

	int_arr = lst_to_arr(a);
	current = a;
	quicksort(int_arr, 0, ft_lstsize(a) - 1);
	while (current)
	{
		i = -1;
		while (++i < ft_lstsize(a))
		{
			if (current->content == int_arr[i])
			{
				current->content = i;
				break ;
			}
		}
		current = current->next;
	}
	free(int_arr);
}

void	radix_sort(t_list **a, t_list **b)
{
	int		i;
	int		bits;
	int		size;

	bits = 0;
	size = ft_lstsize(*a);
	normalize(*a);
	while (!check_order(*a))
	{
		i = -1;
		while (++i < size)
		{
			if ((((*a)->content >> bits) & 1) == 1)
				ops(a, b, "ra");
			else
				ops(a, b, "pb");
		}
		while (*b)
			ops(a, b, "pa");
		bits++;
	}
}
