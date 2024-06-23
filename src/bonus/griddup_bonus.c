/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   griddup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:05:03 by bjacobs           #+#    #+#             */
/*   Updated: 2023/03/21 13:03:09 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf_bonus.h"

static t_grid	fill_dup_points(t_grid dup, t_grid grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < dup.rows)
	{
		j = 0;
		while (j < dup.collums)
		{
			dup.p[i][j].x = grid.p[i][j].x;
			dup.p[i][j].y = grid.p[i][j].y;
			dup.p[i][j].z = grid.p[i][j].z;
			dup.p[i][j].color = grid.p[i][j].color;
			j++;
		}
		i++;
	}
	return (dup);
}

t_grid	griddup(t_grid grid)
{
	t_grid	dup;

	dup.total_points = grid.total_points;
	dup.tile_width = grid.tile_width;
	dup.tile_height = grid.tile_height;
	dup.rows = grid.rows;
	dup.collums = grid.collums;
	dup.p = new_points(dup.rows, dup.collums);
	if (!dup.p)
		error(NULL, INIT_FAILURE, TRUE);
	dup = fill_dup_points(dup, grid);
	return (dup);
}
