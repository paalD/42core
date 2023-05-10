/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:52:47 by dpaal             #+#    #+#             */
/*   Updated: 2022/06/23 18:55:37 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_ctrl_sig = 0;

static int	counter(int check)
{
	static int	counter;

	if (!counter)
		counter = 0;
	if (check == 1)
		counter++;
	return (counter);
}

static void	send_zero_str(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ctrl_sig = 0;
		kill(pid, SIGUSR1);
		i++;
		while (!g_ctrl_sig)
			;
	}
}

static void	send_str(int pid, char *str)
{
	int	i;
	int	j;
	int	mask;

	i = 0;
	while (str[i])
	{
		mask = 0b10000000;
		j = 0;
		while (j < 8)
		{
			usleep(50);
			g_ctrl_sig = 0;
			if ((str[i] & mask) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			mask = mask >> 1;
			j++;
			while (!g_ctrl_sig)
				;
		}
		i++;
	}
	send_zero_str(pid);
}

static void	handler(int signum)
{
	g_ctrl_sig = 1;
	if (signum == SIGUSR2)
		counter(1);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_putendl_fd("Input wrong! use ./client <Server PID> <String>", 1);
		return (1);
	}
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_str(pid, argv[2]);
	ft_putnbr_fd(counter(0) - 1, 1);
	ft_putstr_fd(" Bytes send!\n", 1);
	return (0);
}
