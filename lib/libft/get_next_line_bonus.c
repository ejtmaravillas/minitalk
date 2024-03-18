/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:10:55 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/19 16:01:31 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*dump[MAX_FD];
	char		*read_buffer;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD || BUFFER_SIZE > INT_MAX)
		return (NULL);
	read_buffer = ft_calloc((size_t)BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	if (!dump[fd])
	{
		dump[fd] = ft_strdup("");
		if (!dump[fd])
			return (free_null(read_buffer), NULL);
	}
	dump[fd] = find_newline(fd, dump[fd], read_buffer);
	free_null(read_buffer);
	if (!dump[fd])
		return (NULL);
	newline = fetch_newline(dump[fd]);
	dump[fd] = get_remainingdump(dump[fd], ft_strchr(dump[fd], '\n'));
	return (newline);
}

char	*find_newline(int fd, char *dump, char *read_buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	if (!dump)
		return (NULL);
	while (bytes_read > 0 && !(ft_strchr(dump, '\n')))
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0 || (bytes_read == 0 && !*dump))
			return (free_null(dump), NULL);
		read_buffer[bytes_read] = '\0';
		temp = ft_strjoin(dump, read_buffer);
		if (!temp)
			return (free_null(dump), NULL);
		free_null(dump);
		dump = temp;
	}
	return (dump);
}

char	*get_remainingdump(char *dump, char *newline)
{
	char	*rem;
	size_t	remlen;
	size_t	count;
	size_t	start;

	if (!newline)
		return (free_null(dump), NULL);
	start = newline - dump + 1;
	remlen = ft_strlen(dump);
	if (start > remlen)
		return (free_null(dump), NULL);
	if ((start + BUFFER_SIZE) > remlen)
		remlen = remlen - start;
	rem = ft_calloc(remlen + 1);
	if (!rem)
		return (free_null(dump), NULL);
	count = 0;
	while (dump[start + count] && count < remlen)
	{
		rem[count] = dump[start + count];
		count++;
	}
	rem[count] = '\0';
	free_null(dump);
	return (rem);
}

char	*fetch_newline(char *dump)
{
	char	*newline;
	char	*temp;
	size_t	dumplen;

	if (!*dump)
		return (NULL);
	dumplen = ft_strlen(dump);
	newline = ft_calloc(dumplen + 1);
	if (!newline)
		return (NULL);
	temp = newline;
	while (*dump && *dump != '\n')
		*newline++ = *dump++;
	if (*dump == '\n')
		*newline++ = '\n';
	*newline = '\0';
	return (temp);
}

void	free_null(char *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}
