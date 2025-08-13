/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzukikaisei <suzukikaisei@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:03:35 by suzukikaise       #+#    #+#             */
/*   Updated: 2025/08/11 15:08:42 by suzukikaise      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <sys/types.h>

int main(void)
{
    const pid_t pid = getpid();

    ft_dprintf(STDOUT_FILENO, "%d\n", pid);
    
}