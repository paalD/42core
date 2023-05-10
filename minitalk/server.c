/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:01:22 by dpaal             #+#    #+#             */
/*   Updated: 2022/06/23 22:19:56 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_pid(void)
{
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

void	send_control(pid_t pid, unsigned int mask)
{
	if (!mask)
	{
		ft_putstr_fd("\n\nMessage received on PID: ", 1);
		ft_putnbr_fd(getpid(), 1);
		ft_putendl_fd("!", 1);
		kill(pid, SIGUSR2);
	}
	else
	{
		ft_putchar_fd(mask, 1);
		kill(pid, SIGUSR2);
	}
}

static void	handler(int signum, siginfo_t *info, void *context)
{
	static unsigned int		mask = 0;
	static int				j = 0;

	(void)context;
	if (j < 8)
	{
		if (signum == SIGUSR1)
			mask |= 0;
		else if (signum == SIGUSR2)
			mask |= 1;
	}
	j++;
	if (j >= 8)
	{
		send_control(info->si_pid, mask);
		j = 0;
		mask = 0;
	}
	else
	{
		mask <<= 1;
		kill(info->si_pid, SIGUSR1);
	}
}

static void	term_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)context;
	(void)info;
	ft_putstr_fd("\nProgram exited\n", 1);
	exit (0);
}

int	main(void)
{
	struct sigaction	action;
	struct sigaction	term;

	print_pid();
	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	term.sa_sigaction = term_handler;
	term.sa_flags = SA_SIGINFO;
	sigemptyset(&term.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGINT, &term, NULL);
	sigaction(SIGTERM, &term, NULL);
	while (1)
		pause();
	return (0);
}
