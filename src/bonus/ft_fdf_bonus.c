/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:21:51 by bjacobs           #+#    #+#             */
/*   Updated: 2023/03/21 13:58:14 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf_bonus.h"
#include <unistd.h>

static t_mlx_data	init_data(t_grid origin, t_grid grid,
		mlx_image_t *img, mlx_t *mlx)
{
	t_mlx_data	data;

	data.origin = origin;
	data.grid = grid;
	data.img = img;
	data.mlx = mlx;
	data.zoom = 1;
	data.scale = 1;
	data.anglex = -45.8;
	data.anglez = -30;
	data.angley = -45.8;
	return (data);
}

static void	fdf(mlx_image_t *img, mlx_t *mlx, t_grid origin)
{
	t_grid		grid;
	t_mlx_data	data;
	mlx_image_t	*str_img[3];

	grid = griddup(origin);
	rotate_to_isometric(grid);
	data = init_data(origin, grid, img, mlx);
	put_grid(img, grid.rows, grid.collums, grid.p);
	if (mlx_image_to_window(mlx, img, 0, 0) == -1)
		error("Image to window error", MLX_FAILURE, TRUE);
	put_instruction(mlx, str_img);
	mlx_loop_hook(mlx, &hook, &data);
	mlx_scroll_hook(mlx, &scroll_hook, &data);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_delete_image(mlx, str_img[0]);
	mlx_delete_image(mlx, str_img[1]);
	mlx_delete_image(mlx, str_img[2]);
	mlx_terminate(mlx);
	ft_clear_arr((void **)grid.p, grid.rows);
	ft_clear_arr((void **)origin.p, origin.rows);
}

int	main(int ac, char **av)
{
	t_grid		grid;
	mlx_t		*mlx;
	mlx_image_t	*img;

	if (ac < 2 || ac > 2)
		return (put_usage(), EXIT_SUCCESS);
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".fdf", 5))
		return (ft_putendl_fd(".fdf files only! >:C", 2), EXIT_FAILURE);
	grid = init_grid(av[1]);
	mlx = mlx_init(WIDTH, HEIGHT, "FdF", false);
	if (!mlx)
		error("Mlx initialization error", MLX_FAILURE, TRUE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		error("New image error", MLX_FAILURE, TRUE);
	fdf(img, mlx, grid);
	return (EXIT_SUCCESS);
}
