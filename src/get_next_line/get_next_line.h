/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:55:30 by bjacobs           #+#    #+#             */
/*   Updated: 2023/01/21 12:41:04 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	gnl_strcpy(char *s0, const char *s1);

char	*gnl_substr(const char *s, unsigned int start, size_t size);
char	*gnl_strdup(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
#endif
