/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:18:17 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/20 13:19:57 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../lib/libft/libft.h"
# include <signal.h>

void	send_message(pid_t server_pid, unsigned char c);
void	signal_init(void);
void	check_input(int argc, char **argv);
void	sig_handler(int signum);
void	signal_init(void);
void	handle_signal(int signum, siginfo_t *info, void *ucontent);
#endif