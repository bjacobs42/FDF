/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:22:41 by bjacobs           #+#    #+#             */
/*   Updated: 2023/02/14 15:08:36 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	fill_center_offset(int	*center_offset, t_grid grid)
{
	int	i;
	int	j;
	int	center[3];

	i = 0;
	center[X] = 0;
	center[Y] = 0;
	center[Z] = 0;
	while (i < grid.rows)
	{
		j = 0;
		while (j < grid.collums)
		{
			center[X] += grid.p[i][j].x;
			center[Y] += grid.p[i][j].y;
			center[Z] += grid.p[i][j].z;
			j++;
		}
		i++;
	}
	center_offset[X] = WIDTH / 2 - center[X] / grid.total_points;
	center_offset[Y] = HEIGHT / 2 - center[Y] / grid.total_points;
	center_offset[Z] = center[Z] / grid.total_points;
}

void	center_grid(t_grid grid, double dx, double dy)
{
	static int	map_offset[2] = {0, 0};
	int			center_offset[3];
	int			i;
	int			j;

	i = 0;
	map_offset[X] += dx;
	map_offset[Y] += dy;
	fill_center_offset(center_offset, grid);
	while (i < grid.rows)
	{
		j = 0;
		while (j < grid.collums)
		{
			grid.p[i][j].x += center_offset[X] + map_offset[X];
			grid.p[i][j].y += center_offset[Y] + map_offset[Y];
			grid.p[i][j].z += center_offset[Z];
			j++;
		}
		i++;
	}
}
