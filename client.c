/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-12 10:45:14 by ehabes            #+#    #+#             */
/*   Updated: 2025/02/12 17:10:12 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	send_bit(char *message, int server_pid)
{	
	int		i;
	int		j;

	i = 0;
	while (message[i])
	{
		j = 0;
		while (j < 8)
		{
			if (message[i] & (1 << j))
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			usleep(500);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;

	if (argc != 3)
	{
		write(2, "Fail: ./client <server_pid> <message>\n", 38);
		return (0);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid == -1)
	{
		ft_putstr_fd("pid: can't be -1\n", 1);
		return (0);
	}
	send_bit(argv[2], server_pid);
	return (0);
}
