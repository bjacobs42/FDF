/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:08:27 by bjacobs           #+#    #+#             */
/*   Updated: 2023/03/21 13:25:29 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# define INIT_FAILURE 2
# define MLX_FAILURE 3
# define INVALID_MAP 4

# define WIDTH  1600 // 1024
# define HEIGHT 900 // 578
# define DEFAULT_COLOR -1

# define TRUE 1
# define FALSE 0

# define X 0
# define Y 1
# define Z 2

# include <stdlib.h>
# include "libft.h"
# include "MLX42.h"

typedef struct s_point_data
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
}				t_pdata;

typedef struct s_grid
{
	t_pdata	**p;
	int		rows;
	int		collums;
	int		total_points;
	int		tile_height;
	int		tile_width;
}			t_grid;

/* * * * grid stuff * * * */
t_grid		init_grid(char *map);
t_grid		count_points(int fd);

t_pdata		**new_points(int rows, int collums);

int			count_collums(char *s);

void		put_grid(mlx_image_t *img, int r, int c, t_pdata **points);
void		put_line(mlx_image_t *img, t_pdata p1, t_pdata p2);
void		center_grid(t_grid grid, double dx, double dy);

/* * * * get next line * * * */
char		*get_next_line(int fd);

/* * * * math operations * * * */
double		torad(double degrees);
double		get_unit(t_pdata origin, t_pdata p1, t_pdata p2);

/* * * * color functions * * * */
uint32_t	get_color(char *s);
uint32_t	color_lerp(uint32_t color1, uint32_t color2, double f);

/* * * * error function * * * */
void		error(char *msg, int code, int print_erno);
void		put_usage(void);

/* * * * rotation functions * * * */
void		rotate_x(float angle, t_grid grid);
void		rotate_y(float angle, t_grid grid);
void		rotate_z(float angle, t_grid grid);
void		rotate_to_isometric(t_grid grid);

void		hook(void *param);

#endif
