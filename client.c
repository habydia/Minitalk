/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hadia <Hadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:07:55 by Hadia             #+#    #+#             */
/*   Updated: 2025/03/12 18:08:01 by Hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

volatile sig_atomic_t g_ack_received = 0;

void ack_handler(int sig)
{
    (void)sig;
    g_ack_received = 1;
}

void send_bits(int pid, char c)
{
    int i;
    int bit;

    i = 0;
    while (i < 8)
    {
        bit = (c >> i) & 1;
        
        g_ack_received = 0;
        
        if (bit == 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
            
        // Wait for acknowledgment
        while (!g_ack_received)
            usleep(10);
        i++;
    }
}

int main(int argc, char **argv)
{
    struct sigaction sa;
    
    if (argc == 3)
    {
        int pid;
        char *str_to_send;
        int i;
       
        client_signals(&sa);
        pid = ft_atoi(argv[1]);
        if (pid <= 0)
        {
            ft_putstr_fd("Invalid PID\n", 2);
            return (-1);
        }
            
        str_to_send = argv[2];
        i = 0;
        
        while(str_to_send[i])
            send_bits(pid, str_to_send[i++]);
        send_bits(pid, '\n');
        
    }
    else
    {
        ft_putstr_fd("Usage: ./client [server_pid] [message]\n", 2);
        return (-1);
    }      
    return (0);
}