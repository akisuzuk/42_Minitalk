/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:54:50 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/12/03 10:58:31 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

volatile sig_atomic_t	g_bit_char = 0;

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit_digit;
	char		c;

	(void) info;
	(void) context;
	g_bit_char = g_bit_char << 1;
	if (signum == SIGUSR1)
		g_bit_char = g_bit_char | 1;
	else if (signum == SIGUSR2)
		;
	bit_digit++;
	if (bit_digit == 8)
	{
		c = 0xff & g_bit_char;
		write(1, &c, 1);
		bit_digit = 0;
	}
}

int	main(void)
{
	struct sigaction	act1;
	// struct sigaction	act2;

	write(1, "PID:", 4);
	ft_putnbr_fd((int)(getpid()), 1);
	write(1, "\n", 1);
	ft_memset(&act1, 0, sizeof(sigaction));
	// ft_memset(&act2, 0, sizeof(sigaction));
	act1.sa_sigaction = signal_handler;
	// act2.sa_sigaction = signal_handler;
	act1.sa_flags = SA_SIGINFO;
	// act2.sa_flags = SA_SIGINFO;
	sigaddset(&act1.sa_mask, SIGUSR1);
	sigaddset(&act1.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &act1, NULL);
	sigaction(SIGUSR2, &act1, NULL);
	while (1)
		pause();
	// return (0);
}
