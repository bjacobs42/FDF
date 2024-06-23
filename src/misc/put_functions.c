/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:07:29 by bjacobs           #+#    #+#             */
/*   Updated: 2023/12/24 22:58:25 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include <stdio.h>
#include <math.h>

static void	put_pixel(mlx_image_t *img, t_pdata origin, t_pdata p1, t_pdata p2)
{
	uint32_t	color;

	if (p1.x < 0 || p1.x >= WIDTH || p1.y < 0 || p1.y >= HEIGHT)
		return ;
	if (p1.color == p2.color)
		color = p1.color;
	else
		color = color_lerp(p1.color, p2.color, get_unit(origin, p1, p2));
	mlx_put_pixel(img, p1.x, p1.y, color);
}

static void	init_data(int *delta, int *step, t_pdata p1, t_pdata p2)
{
	delta[X] = abs(p2.x - p1.x);
	delta[Y] = abs(p2.y - p1.y);
	if (p1.x < p2.x)
		step[X] = 1;
	else
		step[X] = -1;
	if (p1.y < p2.y)
		step[Y] = 1;
	else
		step[Y] = -1;
}

static int	out_of_bounds(t_pdata p1, t_pdata p2)
{
	return ((p1.x > WIDTH - 1 && p2.x > WIDTH - 1)
		|| (p1.x < 0 && p2.x < 0)
		|| (p1.y > HEIGHT - 1 && p2.y > HEIGHT - 1)
		|| (p1.y < 0 && p2.y < 0));
}

void	put_line(mlx_image_t *img, t_pdata p1, t_pdata p2)
{
	t_pdata	origin;
	int		delta[2];
	int		step[2];
	int		err[2];

	origin = p1;
	init_data(delta, step, p1, p2);
	err[0] = delta[X] - delta[Y];
	put_pixel(img, origin, p1, p2);
	while ((p1.x != p2.x || p1.y != p2.y) && !out_of_bounds(p1, p2))
	{
		err[1] = 2 * err[0];
		if (err[1] > -delta[Y])
		{
			err[0] -= delta[Y];
			p1.x += step[X];
		}
		else if (err[1] < delta[X])
		{
			err[0] += delta[X];
			p1.y += step[Y];
		}
		put_pixel(img, origin, p1, p2);
	}
}

void	put_grid(mlx_image_t *img, int rows, int collums, t_pdata **point)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < collums)
		{
			if (i + 1 < rows)
				put_line(img, point[i][j], point[i + 1][j]);
			if (j + 1 < collums)
				put_line(img, point[i][j], point[i][j + 1]);
			j++;
		}
		i++;
	}
}
