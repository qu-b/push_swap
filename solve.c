/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:02:45 by fcullen           #+#    #+#             */
/*   Updated: 2022/11/23 10:49:52 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		solve_2(*a, *b);
	else if (ft_lstsize(*a) == 3)
		solve_3(a, b);
	else if (ft_lstsize(*a) == 4)
		solve_4(a, b);
	else if (ft_lstsize(*a) == 5)
		solve_5(a, b);
	else
		radix_sort(a, b);
}

void	solve_2(t_list *a, t_list *b)
{
	if (a->content > a->next->content)
		ops(&a, &b, "sa");
}

void	solve_3(t_list **a, t_list **b)
{
	if ((*a)->content > (*a)->next->content
		&& (*a)->content > (*a)->next->next->content)
		ops(a, b, "ra");
	else if ((*a)->next->content > (*a)->content
		&& (*a)->next->content > (*a)->next->next->content)
		ops(a, b, "rra");
	if ((*a)->content > (*a)->next->content)
		ops(a, b, "sa");
	if ((*a)->content > (*a)->next->next->content)
		ops(a, b, "rra");
}
