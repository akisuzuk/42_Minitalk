/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:54:50 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/11/18 19:31:39 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

volatile sig_atomic_t	g_char = 0;

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;
	char		c;

	(void) info;
	(void) context;
	g_char = g_char << 1;
	if (signum == SIGUSR1)
		g_char = g_char | 1;
	else if (signum == SIGUSR2)
		;
	i++;
	c = 0xff & g_char;
	if (i == 8)
	{
		write(STDOUT_FILENO, &c, 1);
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	act1;
	struct sigaction	act2;

	ft_putnbr_fd((int)(getpid()), 0);
	write(1, "\n", 1);
	ft_memset(&act1, 0, sizeof(sigaction));
	ft_memset(&act2, 0, sizeof(sigaction));
	act1.sa_sigaction = signal_handler;
	act2.sa_sigaction = signal_handler;
	act1.sa_flags = SA_SIGINFO;
	act2.sa_flags = SA_SIGINFO;
	sigaddset(&act1.sa_mask, SIGUSR2);
	sigaddset(&act2.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &act1, NULL);
	sigaction(SIGUSR2, &act2, NULL);
	while (1)
		pause();
}
