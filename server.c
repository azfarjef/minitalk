/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:05:01 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/03/27 21:12:27 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

static void	act(int sig, siginfo_t *info, void *context)
{
	static pid_t	cpid = 0;
	static char		c = 0;
	static int		counter = 0;

	(void)context;
	if (cpid == 0)
		cpid = info->si_pid;
	if (sig == SIGUSR1)
		c |= 1;
	if (++counter == 8)
	{
		write(1, &c, 1);
		counter = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "Server PID : ", 13);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sa.sa_sigaction = act;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
