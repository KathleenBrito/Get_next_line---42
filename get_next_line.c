/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kada-sil <kada-sil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:25:56 by kada-sil          #+#    #+#             */
/*   Updated: 2022/04/26 15:30:06 by kada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*get_next_line(int fd);
static char		*ft_get_backup(int fd, char *next_line, char *buffer);
static char		*ft_get_line(char *next_line);
static char		*ft_line_filter(char *next_line);

char	*get_next_line(int fd)
{
	char			*line;
	static char		*next_line;
	char			*buffer;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	next_line = ft_get_backup(fd, next_line, buffer);
	if (next_line == NULL)
		return (NULL);
	line = ft_get_line(next_line);
	next_line = ft_line_filter(next_line);
	return (line);
}

static char	*ft_get_backup(int fd, char *next_line, char *buffer)
{
	char	*temp;
	int		i;

	i = 1;
	while (i != 0)
	{
		i = read (fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		if (next_line == NULL)
			next_line = ft_strdup("");
		temp = next_line;
		next_line = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(next_line, '\n'))
			i = 0;
	}
	free(buffer);
	return (next_line);
}

static char	*ft_get_line(char *next_line)
{
	int		size;
	char	*string;

	size = 0;
	if (!next_line || next_line[size] == '\0')
		return (NULL);
	while (next_line[size] != '\n' && next_line[size] != '\0')
		size++;
	string = (char *)malloc(sizeof(char) * (size + 2));
	if (string == NULL)
		return (NULL);
	ft_strlcpy(string, next_line, size + 2);
	return (string);
}

static char	*ft_line_filter(char *next_line)
{
	int		i;
	int		j;
	char	*string2;

	i = 0;
	j = 0;
	while (next_line[i] != '\0' && next_line[i] != '\n')
		i++;
	if (next_line[i] == '\0')
	{
		free(next_line);
		return (NULL);
	}
	i++;
	string2 = (char *)malloc(sizeof(char) * (ft_strlen(next_line) - i + 1));
	if (string2 == NULL)
		return (NULL);
	while (next_line[i] != '\0')
	{
		string2[j++] = next_line[i++];
	}
	string2[j] = '\0';
	free(next_line);
	return (string2);
}
