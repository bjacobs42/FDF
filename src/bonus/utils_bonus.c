/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:46:06 by bjacobs           #+#    #+#             */
/*   Updated: 2023/03/21 13:03:39 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf_bonus.h"

void	redraw(t_mlx_data *data)
{
	mlx_image_t	*new_img;

	new_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!new_img)
		error("New image error", MLX_FAILURE, TRUE);
	put_grid(new_img, data->grid.rows, data->grid.collums, data->grid.p);
	if (mlx_image_to_window(data->mlx, new_img, 0, 0) == -1)
		error("Image to window error", MLX_FAILURE, TRUE);
	mlx_delete_image(data->mlx, data->img);
	data->img = new_img;
}

void	zoom(t_grid origin, t_grid grid, double zoom, double scale)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid.rows)
	{
		j = 0;
		while (j < grid.collums)
		{
			grid.p[i][j].x = origin.p[i][j].x * zoom;
			grid.p[i][j].y = origin.p[i][j].y * zoom;
			grid.p[i][j].z = origin.p[i][j].z * zoom * scale;
			j++;
		}
		i++;
	}
}
