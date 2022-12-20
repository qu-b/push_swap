/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:18:35 by fcullen           #+#    #+#             */
/*   Updated: 2022/11/23 10:53:40 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Create new list element with content
t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

// Add an element at end of linked list
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
	new->next = NULL;
}

// Return last element
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// Return penultimate element
t_list	*ft_lstpen(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

// Check if list is ordered
int	check_order(t_list *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}
