/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hadia <Hadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:07:17 by Hadia             #+#    #+#             */
/*   Updated: 2025/03/12 18:07:31 by Hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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