/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:16:20 by bjacobs           #+#    #+#             */
/*   Updated: 2023/03/22 16:57:49 by bjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf_bonus.h"

static int	aswd_keys_down(mlx_t *mlx)
{
	return (mlx_is_key_down(mlx, MLX_KEY_W)
		|| mlx_is_key_down(mlx, MLX_KEY_S)
		|| mlx_is_key_down(mlx, MLX_KEY_A)
		|| mlx_is_key_down(mlx, MLX_KEY_D));
}

static void	change_height(t_mlx_data *data, double delta)
{
	data->scale += delta;
	zoom(data->origin, data->grid, data->zoom, data->scale);
	rotate_x(data->anglex, data->grid);
	rotate_z(data->anglez, data->grid);
	rotate_y(data->angley, data->grid);
	center_grid(data->grid, 0, 0);
	redraw(data);
}

void	scroll_hook(double dx, double dy, void *param)
{
	t_mlx_data	*data;
	double		delta;

	data = param;
	if (dx != 0)
		dy += dx;
	delta = .1 * dy;
	data->zoom += delta;
	if (data->zoom < .1)
		data->zoom = .1;
	else if (data->zoom)
		data->zoom += delta * data->zoom / 10;
	if (data->zoom > 200)
		data->zoom = 200;
	zoom(data->origin, data->grid, data->zoom, data->scale);
	rotate_x(data->anglex, data->grid);
	rotate_z(data->anglez, data->grid);
	rotate_y(data->angley, data->grid);
	center_grid(data->grid, 0, 0);
	redraw(data);
}

void	hook(void *param)
{
	t_mlx_data	*data;
	int			offset[2];

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	else if (aswd_keys_down(data->mlx))
	{
		offset[X] = 0;
		offset[Y] = 0;
		if (mlx_is_key_down(data->mlx, MLX_KEY_W))
			offset[Y] -= 10;
		if (mlx_is_key_down(data->mlx, MLX_KEY_S))
			offset[Y] += 10;
		if (mlx_is_key_down(data->mlx, MLX_KEY_A))
			offset[X] -= 10;
		if (mlx_is_key_down(data->mlx, MLX_KEY_D))
			offset[X] += 10;
		center_grid(data->grid, offset[X] * data->zoom, offset[Y] * data->zoom);
		redraw(data);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_R))
		change_height(data, .05);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_F))
		change_height(data, -.05);
}
