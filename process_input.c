/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:06:01 by fcullen           #+#    #+#             */
/*   Updated: 2022/11/23 11:14:44 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Str to list
t_list	*str_to_lst(char *str)
{
	t_list	*list;
	int		i;
	char	**arr;

	arr = ft_split(str, ' ');
	list = ft_lstnew(ft_atoi(arr[0]));
	i = 0;
	while (arr[++i])
		ft_lstadd_back(&list, ft_lstnew(ft_atoi(arr[i])));
	i = 0;
	ft_free_split(arr);
	return (list);
}

// Arr to list
t_list	*char_to_lst(int ac, char **av)
{
	t_list	*list;
	int		i;

	list = ft_lstnew(ft_atoi(av[1]));
	i = 1;
	while (++i < ac)
		ft_lstadd_back(&list, ft_lstnew(ft_atoi(av[i])));
	return (list);
}

// Free array created by split
void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		i++;
	}
	free(arr);
	arr = NULL;
}
