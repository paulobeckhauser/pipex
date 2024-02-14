/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:00:01 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/20 15:23:52 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"
#include "../../inc/libft.h"
#include <fcntl.h>

char	*filling_line(int fd, char *stash, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stash);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*update_stash(char *line)
{
	char	*stash;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		i++;
	}
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	stash = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!stash)
	{
		free(stash);
		stash = NULL;
	}
	line[i + 1] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(stash);
		buffer = NULL;
		stash = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = filling_line(fd, stash, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	stash = update_stash(line);
	return (line);
}
