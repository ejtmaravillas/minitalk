#include "minitalk.h"

void    send_message(pid_t server_pid, unsigned char c);

int main(int argc, char **argv)
{
    pid_t               server_pid;
    unsigned char       c;

    check_input(argc, argv);
    server_pid = ft_atoi(argv[1]);
    signal_init();
    while(*argv[2])
    {
        c = *argv[2];
        send_message(server_pid, c);
        argv[2]++;
    }
    send_message(server_pid, '\n');
    while (1)
        pause();
    return (EXIT_SUCCESS);
}

void    send_message(pid_t server_pid, unsigned char c)
{
    int bits_count;

    bits_count = 8;
    while(bits_count--)
    {
        if (c & 0b10000000)
            kill(server_pid, SIGUSR1);
        else
            kill(server_pid, SIGUSR2);
        usleep(500);
        c <<= 1;
    }
}
void    signal_init(void)
{
    struct sigaction    sa_action;

    sa_action.sa_handler = &sig_handler;
    sa_action.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &sa_action, NULL) == -1)
        handle_errors("Failed to handle SIGUSR1");
    if (sigaction(SIGUSR2, &sa_action, NULL) == -1)
        handle_errors("Failed to handle SIGUSR2");
}

void    sig_handler(int signum)
{
    if (signum == SIGUSR2)
        write(1, "Character received!\n", 20);
}

void    check_input(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc != 3)
        handle_errors("Invalid number of arguments");
    while (argv[1][i])
        if (!ft_isdigit(argv[1][i++]))
            handle_errors("Invalid PID");
    if (*argv[2] == 0)
        handle_errors("Empty message input");
}

void	handle_errors(char *error_msg)
{
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}