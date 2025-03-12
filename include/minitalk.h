#ifndef MINITALK_H
# define MINITALK_H

# define _DEFAULT_SOURCE
# define _POSIX_C_SOURCE 200809L
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

void    handler(int signal, siginfo_t *info, void *context);
void    ack_handler(int sig);
void client_signals(struct sigaction *sa);
void server_signals(struct sigaction *sa);
#endif

