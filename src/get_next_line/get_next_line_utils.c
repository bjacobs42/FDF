/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:55:02 by bjacobs           #+#    #+#             */
/*   Updated: 2023/01/21 12:10:55 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	gnl_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	if (!s)
		return (NULL);
	size = gnl_strlen((char *)s);
	dup = (char *)malloc(sizeof(char) * (size + 1));
	if (!dup)
		return (NULL);
	dup[size] = '\0';
	while (size--)
		dup[size] = s[size];
	return (dup);
}

char	*gnl_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;

	if (!s)
		return (NULL);
	size = gnl_strlen((char *)s);
	if (len > size - start)
		len = size - start;
	if (start >= size)
		return (gnl_strdup(""));
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	sub[len] = '\0';
	while (len--)
		sub[len] = s[start + len];
	return (sub);
}

size_t	gnl_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	s1len;
	size_t	s2len;

	s1len = gnl_strlen(s1);
	s2len = gnl_strlen(s2);
	s = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!s)
		return (free(s1), NULL);
	s[s1len + s2len] = '\0';
	while (s2len--)
		s[s1len + s2len] = s2[s2len];
	while (s1len--)
		s[s1len] = s1[s1len];
	return (free(s1), s);
}
