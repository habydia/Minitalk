#include "include/minitalk.h"


void    send_bits(int pid, char c)
{
    int i;
    int bit;

    i = 0;
    while (i < 8)
    {
        bit = (c >> i) & 1;
        if (bit == 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        i++;
        usleep(100);
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int pid;
        char *str_to_send;
        int i;
        
        pid = ft_atoi(argv[1]);
        if (pid <= 0)
            return (-1);
        str_to_send = argv[2];
        i = 0;
        
        while(str_to_send[i])
            send_bits(pid, str_to_send[i++]);
        send_bits(pid, '\n');
    }
    else
        return (-1);
        
    return (0);
}