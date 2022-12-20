/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:23:36 by fcullen           #+#    #+#             */
/*   Updated: 2022/11/23 11:00:14 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_separator(char c, char d)
{
	if (c == d)
		return (1);
	return (0);
}

static int	count_strings(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && check_separator(str[i], c))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && !check_separator(str[i], c))
			i++;
	}
	return (count);
}

static int	ft_strlen_sep(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !check_separator(str[i], c))
		i++;
	return (i);
}

static char	*ft_word(char *str, char c)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = ft_strlen_sep(str, c);
	word = malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (0);
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char c)
{
	char	**strings;
	int		i;

	i = 0;
	strings = (char **)malloc(sizeof(char *) * (count_strings(str, c) + 1));
	if (!strings)
		return (0);
	while (*str)
	{
		while (*str && check_separator(*str, c))
			str++;
		if (*str)
		{
			strings[i] = ft_word(str, c);
			i++;
		}
		while (*str && !check_separator(*str, c))
			str++;
	}
	strings[i] = 0;
	return (strings);
}
