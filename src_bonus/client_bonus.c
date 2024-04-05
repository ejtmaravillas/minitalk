/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:38:48 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/20 14:29:54 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t			server_pid;
	unsigned char	c;

	check_input(argc, argv);
	server_pid = ft_atoi(argv[1]);
	signal_init();
	while (*argv[2])
	{
		c = *argv[2];
		send_message(server_pid, c);
		argv[2]++;
	}
	send_message(server_pid, '\0');
	return (EXIT_SUCCESS);
}

void	send_message(pid_t server_pid, unsigned char c)
{
	int	bits_count;

	bits_count = 8;
	while (bits_count--)
	{
		if (c & 0b10000000)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(200);
		c <<= 1;
	}
}

void	signal_init(void)
{
	struct sigaction	sa_action;

	sa_action.sa_handler = &sig_handler;
	sa_action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_action, NULL) == -1)
		handle_errors("Failed to handle SIGUSR1");
	if (sigaction(SIGUSR2, &sa_action, NULL) == -1)
		handle_errors("Failed to handle SIGUSR2");
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR2)
		write(1, "Character received!\n", 20);
	if (signum == SIGUSR1)
		write(1, "MESSAGE SUCCESSFULLY DELIVERED!\n", 32);
}

void	check_input(int argc, char **argv)
{
	int	i;
	int	server_pid;

	i = 0;
	if (argc != 3)
		handle_errors("Invalid number of arguments");
	while (argv[1][i])
		if (!ft_isdigit(argv[1][i++]))
			handle_errors("Invalid PID");
	if (*argv[2] == 0 || (ft_strlen(argv[2]) == 0))
		handle_errors("Empty message input");
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 2 || server_pid > 99998)
		handle_errors("PID out of range - [2, 99998]");
	if (kill(server_pid, 0) == -1)
		handle_errors("No process for the given PID");
}
