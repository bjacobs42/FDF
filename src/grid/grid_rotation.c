/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:39:24 by bjacobs           #+#    #+#             */
/*   Updated: 2023/03/20 22:49:25 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include <math.h>
#include <stdio.h>

/* {1, 0, 0}
 * {0, cos, -sin}
   {0, sin, cos} */
void	rotate_x(float angle, t_grid grid)
{
	int	i;
	int	j;

	i = 0;
	angle = torad(angle);
	while (i < grid.rows)
	{
		j = 0;
		while (j < grid.collums)
		{
			grid.p[i][j].x = grid.p[i][j].x * 1
				+ grid.p[i][j].y * 0
				+ grid.p[i][j].z * 0;
			grid.p[i][j].y = grid.p[i][j].x * 0
				+ grid.p[i][j].y * cos(angle)
				+ grid.p[i][j].z * -sin(angle);
			grid.p[i][j].z = grid.p[i][j].x * 0
				+ grid.p[i][j].y * sin(angle)
				+ grid.p[i][j].z * cos(angle);
			j++;
		}
		i++;
	}
}

/* {cos, 0 -sin}
 * {0, 1, 0}
 * {sin, 0, cos} */
void	rotate_y(float angle, t_grid grid)
{
	int	i;
	int	j;

	i = 0;
	angle = torad(angle);
	while (i < grid.rows)
	{
		j = 0;
		while (j < grid.collums)
		{
			grid.p[i][j].x = grid.p[i][j].x * cos(angle)
				+ grid.p[i][j].y * 0
				+ grid.p[i][j].z * sin(angle);
			grid.p[i][j].y = grid.p[i][j].x * 0
				+ grid.p[i][j].y * 1
				+ grid.p[i][j].z * 0;
			grid.p[i][j].z = grid.p[i][j].x * sin(angle)
				+ grid.p[i][j].y * 0
				+ grid.p[i][j].z * cos(angle);
			j++;
		}
		i++;
	}
}

/* {cos, -sin, 0}
 * {sin, cos, 0}
 * {0, 0, 1} */
void	rotate_z(float angle, t_grid grid)
{
	int	i;
	int	j;

	i = 0;
	angle = torad(angle);
	while (i < grid.rows)
	{
		j = 0;
		while (j < grid.collums)
		{
			grid.p[i][j].x = grid.p[i][j].x * cos(angle)
				+ grid.p[i][j].y * -sin(angle)
				+ grid.p[i][j].z * 0;
			grid.p[i][j].y = grid.p[i][j].x * sin(angle)
				+ grid.p[i][j].y * cos(angle)
				+ grid.p[i][j].z * 0;
			grid.p[i][j].z = grid.p[i][j].x * 0
				+ grid.p[i][j].y * 0
				+ grid.p[i][j].z * 1;
			j++;
		}
		i++;
	}
}

void	rotate_to_isometric(t_grid grid)
{
	rotate_x(-45.8, grid);
	rotate_z(-30, grid);
	rotate_y(-45.8, grid);
	center_grid(grid, 0, 0);
}
