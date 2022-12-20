/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:59:57 by fcullen           #+#    #+#             */
/*   Updated: 2022/11/23 10:49:28 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap a or b (sa/sb)
void	swap(t_list *a)
{
	int	tmp;

	tmp = a->content;
	a->content = a->next->content;
	a->next->content = tmp;
}

// Takes first element of b and uses it as first element of a (pa/pb)
void	ft_lstpush(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = temp;
	ft_lstlast(*a)->next = NULL;
}

// Takes first element of a and makes it last element of a (ra/rb)
void	ft_rotate(t_list **a)
{
	t_list	*last;
	t_list	*temp;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	last = ft_lstlast(*a);
	last->next = *a;
	*a = (*a)->next;
	temp->next = NULL;
}

// Takes last element of a and makes it first element of a (rra/rrb/)
void	ft_rrotate(t_list **a)
{
	t_list	*last;
	t_list	*pen;

	last = ft_lstlast(*a);
	pen = ft_lstpen(*a);
	(*last).next = *a;
	*a = last;
	pen->next = NULL;
}

// Execute operation
void	ops(t_list **a, t_list **b, char *op)
{
	if (!ft_strcmp(op, "sa") || !ft_strcmp(op, "ss"))
		swap(*a);
	if (!ft_strcmp(op, "sb") || !ft_strcmp(op, "ss"))
		swap(*b);
	if (!ft_strcmp(op, "pa"))
		ft_lstpush(a, b);
	if (!ft_strcmp(op, "pb"))
		ft_lstpush(b, a);
	if (!ft_strcmp(op, "ra") || !ft_strcmp(op, "rr"))
		ft_rotate(a);
	if (!ft_strcmp(op, "rb") || !ft_strcmp(op, "rr"))
		ft_rotate(b);
	if (!ft_strcmp(op, "rra") || !ft_strcmp(op, "rrr"))
		ft_rrotate(a);
	if (!ft_strcmp(op, "rrb") || !ft_strcmp(op, "rrr"))
		ft_rrotate(b);
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
}
