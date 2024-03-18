#include "minitalk.h"

void	config_signals(void);
void	handle_sigusr(int signum, siginfo_t *info, void *ucontent);
int main(void)
{
    pid_t               server_pid;

    server_pid = getpid();
    ft_printf("SERVER PID: %d\n", server_pid);
    ft_printf("FETCHING MESSAGE...\n\n");
    ft_printf("------------- MESSAGE POLL ------------\n\n");
    while(1)
        config_signals();
    return (EXIT_SUCCESS);
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &handle_sigusr;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
}

void	handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	static int				bits_count = -1;
	static unsigned char	c;

    (void)ucontent;
	if (bits_count < 0)
		bits_count = 7;
	if (signum == SIGUSR1)
		c |= (1 << bits_count);
	bits_count--;
	if (bits_count < 0 && c)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
			handle_errors("Server failed to send SIGUSR2");
		return ;
	}
	// if (kill(info->si_pid, SIGUSR1) == -1)
	// 	handle_errors("Failed to send SIGUSR1");
}

void	handle_errors(char *error_msg)
{
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}