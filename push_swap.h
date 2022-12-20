/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:47:49 by fcullen           #+#    #+#             */
/*   Updated: 2022/11/23 11:23:56 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}			t_stacks;

// Input -> List
t_list	*str_to_lst(char *str);
t_list	*char_to_lst(int ac, char **av);

// Operations
int		check_order(t_list *a);
void	swap(t_list *a);
void	ops(t_list **a, t_list **b, char *op);
void	ft_rotate(t_list **a);
void	ft_rrotate(t_list **a);
void	ft_lstpush(t_list **a, t_list **b);

// List Utilities
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstpen(t_list *lst);
t_list	*init_stackb(int size);
t_list	*ft_lstnewempty(void);
int		*lst_to_arr(t_list *a);

// Clear list
void	ft_lstclear(t_list *lst);
void	ft_lstdelone(t_list *lst);

// Solve
void	solve(t_list **a, t_list **b);
void	solve_2(t_list *a, t_list *b);
void	solve_3(t_list **a, t_list **b);
void	solve_4(t_list **a, t_list **b);
void	solve_5(t_list **a, t_list **b);

// Solve Utilities
int		findmin(t_list *a);
int		minpos(t_list *a, int min);

// Sorting Algorithms + Utilities
void	ft_swap(int *a, int *b);
int		partition(int *arr, int start, int end);
void	quicksort(int *arr, int start, int end);
void	radix_sort(t_list **a, t_list **b);

// Print solutions (delete)
void	print_solution(t_list *l);
void	print_sol(t_list *l);

// Utilities
int		ft_atoi(const char *str);
char	**ft_split(char *str, char c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	ft_free_split(char **arr);
int		dup_check(t_list **a);


#endif