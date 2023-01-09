/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:53:44 by fcullen           #+#    #+#             */
/*   Updated: 2023/01/06 19:28:27 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Return list size
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// New empty element
t_list	*ft_lstnewempty(void)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

// Clear list
void	ft_lstclear(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	free(lst);
}

// Check integer boundaries
int	int_check(t_list **a)
{
	t_list *lst = *a;

	while (lst)
	{
		printf("%lld ", lst->content);
		lst = lst->next;
	}
	lst = *a;
	while (lst)
	{
		if (lst->content >= 2147483647ll || lst->content <= -2147483648ll)
			return (1);
		lst = lst->next;
	}
	return (0);
}
