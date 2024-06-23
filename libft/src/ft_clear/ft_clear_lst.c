/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:42:34 by bjacobs           #+#    #+#             */
/*   Updated: 2023/02/13 14:09:30 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_clear_lst(char **lst)
{
	int	i;

	if (!lst)
		return ;
	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		lst[i] = NULL;
		i++;
	}
	free(lst);
	lst = NULL;
}
