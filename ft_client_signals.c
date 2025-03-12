/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hadia <Hadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:07:07 by Hadia             #+#    #+#             */
/*   Updated: 2025/03/12 18:07:11 by Hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

void client_signals(struct sigaction *sa)
{
    sa->sa_handler = ack_handler;
    sa->sa_flags = 0;
    sigemptyset(&sa->sa_mask);
    sigaction(SIGUSR1, sa, NULL);
}