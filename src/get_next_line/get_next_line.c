/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:37:54 by bjacobs           #+#    #+#             */
/*   Updated: 2023/01/21 12:42:21 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static size_t	search_nl(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

static void	clean_up(char **s)
{
	if (!*s)
		return ;
	free(*s);
	*s = NULL;
}

static char	*get_line(char **s, size_t size)
{
	char	*line;

	if (!*s)
		return (NULL);
	line = gnl_substr(*s, 0, size);
	if (!line)
		return (NULL);
	gnl_strcpy(*s, *s + size);
	if (!(*s)[0])
		clean_up(s);
	return (line);
}

static char	*read_fd(int fd, char *storage)
{
	char	*buff;
	int		bread;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (clean_up(&storage), NULL);
	while (1)
	{
		bread = read(fd, buff, BUFFER_SIZE);
		if (bread == -1)
			return (free(buff), clean_up(&storage), NULL);
		if (bread == 0)
			return (free(buff), storage);
		buff[bread] = '\0';
		storage = gnl_strjoin(storage, buff);
		if (!storage)
			return (free(buff), NULL);
		if (search_nl(buff))
			break ;
	}
	return (free(buff), storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;
	size_t		size;

	size = search_nl(storage);
	if (size)
	{
		line = get_line(&storage, size);
		if (!line)
			return (clean_up(&storage), NULL);
		return (line);
	}
	storage = read_fd(fd, storage);
	if (!storage)
		return (clean_up(&storage), NULL);
	size = search_nl(storage);
	if (size)
	{
		line = get_line(&storage, size);
		if (!line)
			return (clean_up(&storage), NULL);
		return (line);
	}
	line = gnl_strdup(storage);
	return (clean_up(&storage), line);
}
