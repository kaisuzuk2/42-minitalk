/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzukikaisei <suzukikaisei@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:05:17 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/08/11 15:02:22 by suzukikaise      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
endian = msb
*/

static int send_char_bits(pid_t pid, char c)
{
    int i;

    i = 8;
    while (--i)
    {
        if ((c >> i) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
    }
}

int send_string(pid_t pid, char *arg)
{
    while (*arg)
    {
        send_char_bits(pid, *arg);
        arg++;
    }
}