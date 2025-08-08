/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:42:00 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/08/08 15:04:54 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#define PID_ARG 2
#define CLIENT_ARG_NUM 3 // program_name, pid, arg

void print_usage(void)
{
	ft_dprintf(STDERR_FILENO, "Usage: PID args\n");
}

t_bool is_arg_digit(char *arg)
{
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (FALSE);
		arg++;
	}
	return (TRUE);
}

t_bool parse(int argc, char **argv)
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

