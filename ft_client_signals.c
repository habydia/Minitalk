#include "include/minitalk.h"

void client_signals(struct sigaction *sa)
{
    sa->sa_handler = ack_handler;
    sa->sa_flags = 0;
    sigemptyset(&sa->sa_mask);
    sigaction(SIGUSR1, sa, NULL);
}