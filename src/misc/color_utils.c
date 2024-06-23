/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:08:41 by bjacobs           #+#    #+#             */
/*   Updated: 2023/02/13 13:25:44 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_fdf.h"

static uint32_t	create_trgb(uint32_t n)
{
	unsigned char	trgb[4];

	trgb[0] = 0xff;
	trgb[1] = ((unsigned char *)&n)[0];
	trgb[2] = ((unsigned char *)&n)[1];
	trgb[3] = ((unsigned char *)&n)[2];
	return (*(uint32_t *)trgb);
}

uint32_t	get_color(char *s)
{
	size_t		i;

	i = 0;
	while (s[i] && !ft_isspace(s[i]))
	{
		if (s[i] == ',')
			return (create_trgb(ft_atoh(&s[i + 1])));
		i++;
	}
	return (DEFAULT_COLOR);
}

uint32_t	color_lerp(uint32_t color1, uint32_t color2, double f)
{
	unsigned char	lerped_rgb[4];
	unsigned char	col[2];
	size_t			i;

	i = 0;
	while (i < 4)
	{
		col[0] = ((unsigned char *)&color1)[i];
		col[1] = ((unsigned char *)&color2)[i];
		lerped_rgb[i] = (col[1] - col[0]) * f + col[0];
		i++;
	}
	return (*(uint32_t *)lerped_rgb);
}
