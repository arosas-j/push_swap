/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:55:47 by arosas-j          #+#    #+#             */
/*   Updated: 2024/02/01 15:12:59 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//Returns the line contained in the static memory
char	*copy_to_line(char *saved_line)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!saved_line[i])
		return (NULL);
	while (saved_line[i] && saved_line[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (saved_line[i] && saved_line[i] != '\n')
	{
		line[i] = saved_line[i];
		i++;
	}
	if (saved_line[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*Prepares the static memory for the next function call, deleting until it
detects a '\n'*/
char	*fix_saved_line(char *saved_line)
{
	size_t	i;
	size_t	j;
	char	*new_saved_line;

	i = 0;
	j = 0;
	while (saved_line[i] && saved_line[i] != '\n')
		i++;
	if (!saved_line[i])
	{
		free(saved_line);
		return (NULL);
	}
	new_saved_line = (char *)malloc(ft_strlen(saved_line) - i + 1);
	if (!new_saved_line)
		return (NULL);
	i++;
	while (saved_line[i])
		new_saved_line[j++] = saved_line[i++];
	new_saved_line[j] = '\0';
	free(saved_line);
	return (new_saved_line);
}

/*Reads from the fd and ads its contents to the saved line, until it detects
a char '\n' in the line.*/
char	*read_to_line(int fd, char *saved_line)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(saved_line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(saved_line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		saved_line = ft_strjoin(saved_line, buffer);
	}
	free(buffer);
	return (saved_line);
}

//Mother function. Reads from a fd and returns a new line each time it's called
char	*get_next_line(int fd)
{
	static char	*saved_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	saved_line = read_to_line(fd, saved_line);
	if (!saved_line)
		return (NULL);
	line = copy_to_line(saved_line);
	saved_line = fix_saved_line(saved_line);
	return (line);
}
