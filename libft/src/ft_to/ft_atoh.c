/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:55:10 by bjacobs           #+#    #+#             */
/*   Updated: 2023/01/30 16:30:59 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoh(const char *s)
{
	int	num;
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && i < 2)
		i++;
	num = 0;
	while (ft_isdigit(s[i]) || ft_isalpha(s[i]))
	{
		if (ft_isdigit(s[i]))
			num = num * 16 + s[i] - '0';
		else
			num = num * 16 + ft_tolower(s[i]) - 'a' + 10;
		i++;
	}
	return (num);
}
