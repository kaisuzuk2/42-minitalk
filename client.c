/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzukikaisei <suzukikaisei@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:42:00 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/08/11 15:02:14 by suzukikaise      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "client.h"

// program_name, pid, arg
#define PID_ARG 2
#define CLIENT_ARG_NUM 3

static void print_usage(void)
{
	ft_dprintf(STDERR_FILENO, "Usage: PID args\n");
}

static t_bool is_arg_digit(char *arg)
{
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (FALSE);
		arg++;
	}
	return (TRUE);
}

static t_bool parse(int argc, char **argv)
{
	int i;
	
	if (argc != CLIENT_ARG_NUM)
		return (FALSE);
	if (!is_arg_digit(PID_ARG))
		return (FALSE);
	return (TRUE);
}

int main(int argc, char *argv[])
{
	if (!parse(argc, argv))
		return (print_usage(), 1);
	
}

