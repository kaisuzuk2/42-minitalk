/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:41:10 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/09/06 15:23:49 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
 #define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>

typedef int t_bool;
#define TRUE 1
#define FALSE 0

// signal
#define BIT0_SIG SIGUSR1
#define BIT1_SIG SIGUSR2

// sleep time
#define SEND_DELAY_US 200

// client_utils.c
int send_string(pid_t pid, char *arg);
 
#endif