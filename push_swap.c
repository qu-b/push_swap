/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:47:52 by fcullen           #+#    #+#             */
/*   Updated: 2023/01/06 19:18:52 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (ac == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ac == 2)
		stacks.a = str_to_lst(av[1]);
	else
		stacks.a = char_to_lst(ac, av);
	if (!stacks.a || int_check(&stacks.a)
		|| ft_lstsize(stacks.a) == 1 || dup_check(&stacks.a))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else if (!check_order(stacks.a))
		solve(&stacks.a, &stacks.b);
	ft_lstclear(stacks.a);
	ft_lstclear(stacks.b);
	return (0);
}
