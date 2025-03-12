/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hadia <Hadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:07:46 by Hadia             #+#    #+#             */
/*   Updated: 2025/03/12 18:11:32 by Hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

volatile sig_atomic_t g_received = 0;

void    handler(int signal, siginfo_t *info, void *context)
{
    static int bit;
    static int i;
    static pid_t client_pid;
    
    (void)context;
    
    // Always use the PID from the current signal
    client_pid = info->si_pid;
        
    if (signal == SIGUSR1)
        i |= (0x01 << bit);
    
    bit++;
    
    if (bit == 8)
    {
        write(1, &i, 1);
        bit = 0;
        i = 0;
    }
    
    usleep(100);
    kill(client_pid, SIGUSR1);
}

int main(int argc, char **argv)
{
    int id;
    struct sigaction sa;
    
    (void)argv;
    id = getpid();

    if (argc != 1)
    {
        write(1, "Use: ./server\n", 14);
        return (-1);
    }
    server_signals(&sa);
    write(1, "Server PID: ", 12);
    ft_putnbr_fd(id, 1);
    write(1, "\n", 1);
    
    while(1)
        pause();
        
    return (0);
}