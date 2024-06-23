/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:08:27 by bjacobs           #+#    #+#             */
/*   Updated: 2023/03/21 13:59:44 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_BONUS_H
# define FT_FDF_BONUS_H

# include "ft_fdf.h"

typedef struct s_mlx_data
{
	float		anglex;
	float		angley;
	float		anglez;
	double		zoom;
	double		scale;
	t_grid		origin;
	t_grid		grid;
	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_mlx_data;

t_grid		griddup(t_grid grid);

void		redraw(t_mlx_data *data);
void		zoom(t_grid origin, t_grid grid, double zoom, double scale);
void		scroll_hook(double dx, double dy, void *param);
void		put_instruction(mlx_t *mlx, mlx_image_t **str_img);

#endif
