#include "include/minitalk.h"

void server_signals(struct sigaction *sa)
{
    sa->sa_sigaction = handler;
    sa->sa_flags = SA_SIGINFO;
    sigemptyset(&sa->sa_mask);
    sigaddset(&sa->sa_mask, SIGUSR1);
    sigaddset(&sa->sa_mask, SIGUSR2);
    
    sigaction(SIGUSR1, sa, NULL);
    sigaction(SIGUSR2, sa, NULL);
}