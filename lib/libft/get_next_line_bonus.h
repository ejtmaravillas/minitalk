/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:11:17 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/19 13:48:21 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/resource.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# ifndef MAX_FD
#  define MAX_FD OPEN_MAX
# endif

char	*get_next_line(int fd);
char	*get_remainingdump(char *dump, char *newline);
char	*fetch_newline(char *dump);
char	*find_newline(int fd, char *dump, char *read_buffer);
char	*ft_strdup(char *str);
size_t	ft_strlen(const char *arg);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	free_null(char *ptr);
char	*error_check(char *dump);
void	*ft_calloc(size_t buffer);
#endif //GET_NEXT_LINE_BONUS_H