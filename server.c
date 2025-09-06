/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:03:35 by suzukikaise       #+#    #+#             */
/*   Updated: 2025/09/06 15:47:48 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <sys/types.h>

// volatileがどのような働きをするか調べよう
static volatile sig_atomic_t bit_idx = 7;
static unsigned char cur = 0;

static void on_signal(int sig)
{
    int bit = (sig == BIT0_SIG);
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
    const pid_t pid = getpid();

    ft_dprintf(STDOUT_FILENO, "%d\n", pid);
    
}