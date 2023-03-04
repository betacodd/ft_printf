/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:18:32 by elevy             #+#    #+#             */
/*   Updated: 2022/12/24 17:50:37 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(char *buffer, int fd)
{
	char	*tmp;
	int		to_read;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	to_read = 1;
	while (to_read > 0)
	{
		to_read = read(fd, tmp, BUFFER_SIZE);
		if (to_read < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[to_read] = '\0';
		buffer = ft_strjoin(tmp, buffer);
		if (ft_get_nl(buffer))
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*get_new_buffer(char *buffer)
{
	char	*new_buffer;
	int		buffer_length;
	int		new;
	int		total_length;

	buffer_length = ft_strlen_nl(buffer);
	total_length = ft_strlen(buffer) - ft_strlen_nl(buffer);
	new = 0;
	if (!total_length)
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = malloc(sizeof(char) * (total_length + 1));
	if (!new_buffer)
		return (NULL);
	while (buffer[buffer_length] != '\0')
	{
		new_buffer[new] = buffer[buffer_length];
		new++;
		buffer_length++;
	}
	new_buffer[new] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_line(char *buffer)
{
	int		i;
	char	*s;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	s = malloc(sizeof(char) * ft_strlen(buffer) + 1);
	if (!s)
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		s[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1096];
	char		*s;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer[fd] = read_file(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	s = get_line(buffer[fd]);
	buffer[fd] = get_new_buffer(buffer[fd]);
	if (!s)
		free(buffer[fd]);
	return (s);
}
