/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:45:26 by bjacobs           #+#    #+#             */
/*   Updated: 2023/03/21 13:26:37 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include <unistd.h>
#include <stdio.h>

void	error(char *msg, int code, int print_erno)
{
	if (print_erno)
		perror(msg);
	else
		ft_putendl_fd(msg, STDERR_FILENO);
	exit(code);
}

void	put_usage(void)
{
	ft_putendl_fd("Usage: fdf <filename>", STDERR_FILENO);
}
