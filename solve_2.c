/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:02:09 by fcullen           #+#    #+#             */
/*   Updated: 2022/11/23 10:52:10 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find minimum value
int	findmin(t_list *a)
{
	int		min;

	min = a->content;
	while (a)
	{
		if (a->content < min)
			min = a->content;
		a = a->next;
	}
	return (min);
}

// Find minimum position
int	minpos(t_list *a, int min)
{
	int	pos;

	pos = 0;
	if (min == ft_lstlast(a)->content)
		pos = ft_lstsize(a) - 1;
	else
		while (a)
		{
			if (min == a->content)
				return (pos);
			pos++;
			a = a->next;
		}
	return (pos);
}

void	solve_4(t_list **a, t_list **b)
{
	int	min;

	min = minpos(*a, findmin(*a));
	if (min == 1)
		ops(a, b, "sa");
	if (min == 2)
	{
		ops(a, b, "ra");
		ops(a, b, "ra");
	}
	if (min == 3)
		ops(a, b, "rra");
	ops(a, b, "pb");
	solve_3(a, b);
	ops(a, b, "pa");
}

void	solve_5(t_list **a, t_list **b)
{
	int	pos;

	pos = minpos(*a, findmin(*a));
	if (pos == 1)
		ops(a, b, "ra");
	if (pos == 2)
	{
		ops(a, b, "ra");
		ops(a, b, "ra");
	}
	if (pos == 3)
	{
		ops(a, b, "rra");
		ops(a, b, "rra");
	}
	if (pos == 4)
		ops(a, b, "rra");
	ops(a, b, "pb");
	solve_4(a, b);
	ops(a, b, "pa");
}
