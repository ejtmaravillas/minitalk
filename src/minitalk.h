#ifndef MINITALK_H
# define MINITALK_H

# include "../lib/libft/libft.h"
# include <signal.h>

void	handle_errors(char *error_msg);
void    check_input(int argc, char **argv);
void    sig_handler(int signum);
void	config_signals(void);
void	handle_sigusr(int signum, siginfo_t *info, void *ucontent);
void    signal_init(void);
#endif