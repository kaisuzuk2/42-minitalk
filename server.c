/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:03:35 by suzukikaise       #+#    #+#             */
/*   Updated: 2025/09/07 11:23:11 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>


// volatileがどのような働きをするか調べよう
static volatile sig_atomic_t bit_idx = 7;
static unsigned char cur = 0;

static void on_signal(int sig)
{
    int bit = (sig == BIT1_SIG);
    if (bit)
        cur |= (1u << bit_idx);
    if (bit_idx == 0)
    {
        if (cur == '\0')
            write(1, "\n", 1);
        else
            write(1, &cur, 1);
        cur = 0;
        bit_idx = 7;
    }
    else
        bit_idx--;
}

int main(void)
{
    struct sigaction sa;
    const pid_t pid = getpid();

    dprintf(STDOUT_FILENO, "%d\n", pid);
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, BIT0_SIG);
    sigaddset(&sa.sa_mask, BIT1_SIG);
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = on_signal;

    if (sigaction(BIT0_SIG, &sa, NULL) == -1)
        return (-1);
    if (sigaction(BIT1_SIG, &sa, NULL) == -1)
        return (-1);
    while (1)
        pause();
}