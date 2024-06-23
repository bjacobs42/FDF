/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:05:03 by bjacobs           #+#    #+#             */
/*   Updated: 2023/03/21 13:28:39 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include <fcntl.h>
#include <unistd.h>

t_pdata	**new_points(int rows, int collums)
{
	t_pdata	**points;
	int		i;

	points = (t_pdata **)malloc(sizeof(t_pdata *) * rows);
	if (!points)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		points[i] = (t_pdata *)malloc(sizeof(t_pdata) * collums);
		if (!points[i])
			return (ft_clear_arr((void **)points, i + 1), NULL);
		i++;
	}
	return (points);
}

static void	fill_data(t_grid grid, char *num, int row, int collum)
{
	grid.p[row][collum].x = grid.tile_width * collum;
	grid.p[row][collum].y = grid.tile_height * row;
	grid.p[row][collum].z = ft_atoi(num) * -grid.tile_height;
	grid.p[row][collum].color = get_color(num);
}

static void	fill_points(t_grid grid, int fd)
{
	char	**nums;
	char	*s;
	int		j;
	int		i;

	s = get_next_line(fd);
	i = 0;
	while (s)
	{
		nums = ft_split(s, ' ');
		if (!nums)
			error("split error", EXIT_FAILURE, TRUE);
		j = 0;
		while (j < grid.collums && nums[j])
		{
			fill_data(grid, nums[j], i, j);
			j++;
		}
		i++;
		free(s);
		ft_clear_lst(nums);
		s = get_next_line(fd);
	}
}

t_grid	init_grid(char *map)
{
	t_grid	grid;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		error(map, INVALID_MAP, TRUE);
	grid = count_points(fd);
	close(fd);
	if (grid.rows < 2 || grid.collums < 2)
		error("Not enough points", INVALID_MAP, FALSE);
	grid.tile_height = (WIDTH - 1) / (grid.rows - 1) * .6;
	grid.tile_width = grid.tile_height;
	grid.p = new_points(grid.rows, grid.collums);
	if (!grid.p)
		error("points allocation error", INIT_FAILURE, TRUE);
	fd = open(map, O_RDONLY);
	fill_points(grid, fd);
	close(fd);
	return (grid);
}
