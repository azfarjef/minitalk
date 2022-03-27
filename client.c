/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:04:42 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/03/27 21:12:37 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

static void	handler(int	sig)
{
	(void)sig;
}

static void	send_msg(char *str, int spid)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = 8;
		while (j--)
		{
			if (((str[i] >> j) & 1) == 0)
				kill(spid, SIGUSR2);
			else if (((str[i] >> j) & 1) == 1)
				kill(spid, SIGUSR1);
			usleep(100);
		}
	}
	exit(0);
}

int	main(int ac, char **av)
{
	if (ac != 3 || ft_strlen(av[2]) == 0)
		return (1);
	write(1, "Characters sent: ", 17);
	ft_putnbr_fd(ft_strlen(av[2]), 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	send_msg(av[2], ft_atoi(av[1]));
	while (1)
		pause();
	return (0);
}
