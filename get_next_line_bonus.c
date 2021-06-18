/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 22:15:51 by kchristi          #+#    #+#             */
/*   Updated: 2021/06/17 20:25:08 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
		return ((char *)s + (ft_strlen(s)));
	return (ft_memchr(s, c, ft_strlen(s)));
}

static char	*ft_crop_line(char *s, size_t len)
{
	char			*line;
	size_t			c;

	line = malloc(len + 1);
	if (!line)
		return (NULL);
	c = 0;
	while (c < len)
	{
		line[c] = s[c];
		c++;
	}
	line[c] = '\0';
	return (line);
}

static int	ft_get_line(char **result, char **line)
{
	int		line_size;
	char	*temp;

	line_size = 0;
	while ((*result)[line_size] != '\n' && (*result)[line_size])
		line_size++;
	if ((*result)[line_size] == '\0')
	{
		*line = ft_strdup(*result);
		if (*result != NULL)
		{
			free(*result);
			*result = NULL;
		}
		return (0);
	}
	*line = ft_crop_line(*result, line_size);
	temp = ft_strdup((*result) + line_size + 1);
	free(*result);
	*result = temp;
	return (1);
}

static int	ft_output(char **result, char **line, ssize_t size)
{
	if (size < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	else if (size == 0 && *result == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_get_line(result, line));
}

int	get_next_line(int fd, char **line)
{
	static char		*result[OPEN_MAX];
	t_gnl			gnl;

	gnl.buffer = malloc(BUFFER_SIZE + 1);
	if (!gnl.buffer)
		return (-1);
	gnl.size = read(fd, gnl.buffer, BUFFER_SIZE);
	while (gnl.size > 0)
	{
		gnl.buffer[gnl.size] = '\0';
		if (result[fd] == NULL)
			result[fd] = ft_strdup(gnl.buffer);
		else
		{
			gnl.temp = ft_strjoin(result[fd], gnl.buffer);
			free(result[fd]);
			result[fd] = gnl.temp;
		}
		if (ft_strchr(result[fd], '\n'))
			break ;
		gnl.size = read(fd, gnl.buffer, BUFFER_SIZE);
	}
	free(gnl.buffer);
	return (ft_output(&result[fd], line, gnl.size));
}
