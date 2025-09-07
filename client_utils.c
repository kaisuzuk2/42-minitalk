/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:05:17 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/09/07 11:27:26 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
endian = msb
*/

static int send_char_bits(pid_t pid, unsigned char c)
{
    int i;

    i = 7;
    while (i >= 0)
    {
        if ((c >> i) & 1)
        {
            if (kill(pid, BIT1_SIG) == -1)
                return (errno);
        }
        else
            if (kill(pid, BIT0_SIG) == -1)
                return (errno);
        i--;
        usleep(SEND_DELAY_US);
    }
    return (0);
}

void send_string(pid_t pid, char *arg)
{
    while (*arg)
    {
        send_char_bits(pid, *arg);
        arg++;
    }
}