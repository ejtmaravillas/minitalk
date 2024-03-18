/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:11:17 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/19 14:59:44 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/resource.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*get_remainingdump(char *dump, char *newline);
char	*fetch_newline(char *dump);
char	*find_newline(int fd, char *dump, char *read_buffer);
char	*ft_strdup_gnl(char *str);
size_t	ft_strlen_gnl(const char *arg);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	free_null(char *ptr);
char	*error_check(char *dump);
void	*ft_calloc_gnl(size_t buffer);
bool	check_string_arg(char *newline);

#endif //GET_NEXT_LINE_H