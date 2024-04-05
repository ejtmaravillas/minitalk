/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:42:11 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/20 14:24:10 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_printf("\nUSE CASE: ./client <SERVER_PID> <MESSAGE>\n");
	ft_printf("\nSERVER PID: %d\n", server_pid);
	ft_printf("\nFETCHING MESSAGE...\n");
	signal_init();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

void	signal_init(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &handle_signal;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		handle_errors("Failed to get SIGUSR1's handler");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		handle_errors("Failed to get SIGUSR2's handler");
}

void	handle_signal(int signum, siginfo_t *info, void *ucontent)
{
	static int				bits_count = -1;
	static unsigned char	c;

	(void)ucontent;
	(void)info;
	if (bits_count < 0)
		bits_count = 7;
	if (signum == SIGUSR1)
		c |= (1 << bits_count);
	if (--bits_count < 0)
	{
		if (c == '\0')
			ft_putchar_fd('\n', STDOUT_FILENO);
		else
			ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
		return ;
	}
}
