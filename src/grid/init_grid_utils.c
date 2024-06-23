/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:11:43 by bjacobs           #+#    #+#             */
/*   Updated: 2023/02/16 15:52:15 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "libft.h"

int	count_collums(char *s)
{
	int	i;
	int	collums;

	if (!s)
		return (0);
	i = 0;
	collums = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
		{
			while (!ft_isspace(s[i]) && s[i])
				i++;
			collums++;
		}
		else
			i++;
	}
	return (collums);
}

t_grid	count_points(int fd)
{
	char	*s;
	t_grid	grid;

	grid.rows = 0;
	s = get_next_line(fd);
	grid.collums = count_collums(s);
	while (s)
	{
		if (grid.collums != count_collums(s))
		{
			ft_printf_fd("Map collums does not match at line %d\n", 2,
				grid.rows + 1);
			error(NULL, INVALID_MAP, FALSE);
		}
		grid.rows++;
		free(s);
		s = get_next_line(fd);
	}
	grid.total_points = grid.rows * grid.collums;
	return (grid);
}
