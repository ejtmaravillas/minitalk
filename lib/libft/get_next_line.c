/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:10:55 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/19 16:07:25 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*dump;
	char		*read_buffer;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	read_buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	if (!dump)
	{
		dump = ft_strdup_gnl("");
		if (!dump)
			return (free_null(read_buffer), NULL);
	}
	dump = find_newline(fd, dump, read_buffer);
	free_null(read_buffer);
	if (!dump)
		return (NULL);
	newline = fetch_newline(dump);
	dump = get_remainingdump(dump, newline);
	if (!check_string_arg(newline))
		free_null(dump);
	return (newline);
}

char	*find_newline(int fd, char *dump, char *read_buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	if (!dump)
		return (NULL);
	while (bytes_read > 0 && !(ft_strchr_gnl(dump, '\n')))
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0 || (bytes_read == 0 && !*dump))
			return (free_null(dump), NULL);
		read_buffer[bytes_read] = '\0';
		temp = ft_strjoin_gnl(dump, read_buffer);
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
	remlen = ft_strlen_gnl(dump);
	if ((start > remlen))
		return (free_null(dump), NULL);
	if ((start + BUFFER_SIZE) > remlen)
		remlen = remlen - start;
	rem = malloc(remlen + 1);
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
	dumplen = ft_strlen_gnl(dump);
	newline = malloc(dumplen + 1);
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
