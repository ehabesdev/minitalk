#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	handle_signal(int sig)
{
	static int	bit_counter;
	static int	rec_char;

	if(sig == SIGUSR1)
		;
	else if(sig == SIGUSR2)
	{
		rec_char |= (1 << bit_counter);
	}
	(bit_counter)++;
	if(bit_counter == 8)
	{
		if(rec_char == '\\')
			write(1, "\n", 1);
		else
			write(1, &rec_char, 1);
		bit_counter = 0;
		rec_char = 0;
	}
}

int main(void)
{
	ft_putstr_fd("process id: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);

	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);

	while(1)
	{
		pause();
	}
	return (0);
}
