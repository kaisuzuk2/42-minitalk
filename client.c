/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:42:00 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/09/07 11:33:02 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// program_name, pid, arg
#define PID_ARG 1
#define CLIENT_ARG_NUM 3

static void print_usage(void)
{
	dprintf(STDERR_FILENO, "Usage: PID args\n");
}

static int ft_isdigit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

static t_bool parse(int argc, char **argv)
{
	int i;
	
	if (argc != CLIENT_ARG_NUM)
		return (FALSE);
	if (ft_isdigit(argv[PID_ARG]))
		return (FALSE);
	return (TRUE);
}

int main(int argc, char *argv[])
{
	pid_t pid;
	
	if (!parse(argc, argv))
		return (print_usage(), 1);
	pid = atoi(argv[PID_ARG]);
	send_string(pid, argv[2]);
}

