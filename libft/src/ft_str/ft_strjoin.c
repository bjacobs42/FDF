/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:38:27 by bjacobs           #+#    #+#             */
/*   Updated: 2023/01/12 20:30:09 by bjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	size1;
	size_t	size2;

	if (!s1 || !s1[0])
		return (ft_strdup(s2));
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!s)
		return (NULL);
	s[size1 + size2] = '\0';
	while (size2--)
		s[size1 + size2] = s2[size2];
	while (size1--)
		s[size1] = s1[size1];
	return (s);
}
