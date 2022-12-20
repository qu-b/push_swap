/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:47:52 by fcullen           #+#    #+#             */
/*   Updated: 2022/11/24 18:15:47 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (ac == 1)
		return (0);
	if (ac == 2)
		stacks.a = str_to_lst(av[1]);
	else
		stacks.a = char_to_lst(ac, av);
	if (!stacks.a || ft_lstsize(stacks.a) == 1 || dup_check(&stacks.a)) // refuse any (input > int_max)!!
		write(2, "Error\n", 6);
	else if (!check_order(stacks.a))
		solve(&stacks.a, &stacks.b);
	ft_lstclear(stacks.a);
	ft_lstclear(stacks.b);
	return (0);
}
