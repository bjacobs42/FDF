/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:20:10 by bjacobs           #+#    #+#             */
/*   Updated: 2023/02/13 13:20:38 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include <math.h>
#include <stdio.h>

double	torad(double degrees)
{
	return (degrees * M_PI / 180);
}

double	distance(t_pdata a, t_pdata b)
{
	double	d[3];

	d[X] = b.x - a.x;
	d[Y] = b.y - a.y;
	d[Z] = b.z - a.z;
	return (sqrt(d[X] * d[X] + d[Y] * d[Y] + d[Z] * d[Z]));
}

double	get_unit(t_pdata origin, t_pdata p1, t_pdata p2)
{
	double	distance0;
	double	distance1;

	distance0 = distance(origin, p1);
	distance1 = distance(origin, p2);
	return (distance0 / distance1);
}
