#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		write(2, "Fail: ./client <server_pid> <message>\n", 38);
		return (0);
	}

	int	server_pid;
	int	i;
	int	j;
	char	*message;

	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	if(server_pid == -1)
	{
		ft_putstr_fd("pid: can't be -1\n", 1);
		return (0);
	}
	while(message[i])
	{
		j = 0;
		while(j < 8)
		{
			if(message[i] & (1 << j))
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			usleep(500);
			j++;
		}
		i++;
	}
	return (0);
}
