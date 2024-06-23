/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:55:53 by bjacobs           #+#    #+#             */
/*   Updated: 2023/03/21 13:57:54 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf_bonus.h"

void	put_instruction(mlx_t *mlx, mlx_image_t **str_img)
{
	str_img[0] = mlx_put_string(mlx, "Increase/Decrease scale: RF", 0, 0);
	if (!str_img[0])
		error("New image error", MLX_FAILURE, TRUE);
	str_img[1] = mlx_put_string(mlx, "Zoom: scroll", 0, 20);
	if (!str_img[1])
		error("New image error", MLX_FAILURE, TRUE);
	str_img[2] = mlx_put_string(mlx, "Translate: AWSD", 0, 40);
	if (!str_img[2])
		error("New image error", MLX_FAILURE, TRUE);
}
