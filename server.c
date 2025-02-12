#include "include/minitalk.h"

void    handler(int signal)
{
    static int bit;
    static int i;

    if (signal == SIGUSR1)
    {
        i |= (0x01 << bit);
    }
    bit++;
    if (bit == 8)
    {
        write(1, &i, 1);
        bit = 0;
        i = 0;
    }
}

int main(int argc, char **argv)
{
    int id;
    (void)argv;
    id = getpid();

    if (argc != 1)
    {
        write(1, "Use: ./server\n", 14);
        return (-1);
    }
    write(1, "Server PID: ", 12);
    ft_putnbr_fd(id, 1);
    write(1, "\n", 1);
    while(argc == 1)
    {
        signal(SIGUSR1, handler);
        signal(SIGUSR2, handler);
        pause ();
    }
    return (0);
}