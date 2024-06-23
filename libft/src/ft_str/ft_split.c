/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:38:14 by bjacobs           #+#    #+#             */
/*   Updated: 2023/01/18 20:58:01 by bjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	lst_size(char const *s, char c)
{
	size_t	i;
	size_t	lst_size;

	i = 0;
	lst_size = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			lst_size++;
		}
		else
			i++;
	}
	return (lst_size);
}

static char	**create_lst(char const *s, char c, char **lst)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			lst[j] = ft_substr(s, start, i - start);
			if (!lst[j])
				return (ft_clear_lst(lst), NULL);
			j++;
		}
		else
			i++;
	}
	return (lst);
}

char	**ft_split(char const *s, char c)
{
	size_t	lst_s;
	char	**lst;

	lst_s = lst_size(s, c);
	lst = (char **)malloc(sizeof(char *) * (lst_s + 1));
	if (!lst)
		return (NULL);
	lst[lst_s] = NULL;
	if (!create_lst(s, c, lst))
		return (NULL);
	return (lst);
}
