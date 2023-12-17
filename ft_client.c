/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:54:46 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/12/17 14:52:01 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	send_char(const pid_t pid, char c)
{
	int	digit;
	int	killnum;

	digit = 7;
	while (digit >= 0)
	{
		if (c & (1 << digit))
			killnum = kill(pid, SIGUSR1);
		else
			killnum = kill(pid, SIGUSR2);
		if (killnum == -1)
		{
			write(2, "Error : Failed to send signal\n", 30);
			exit (1);
		}
		digit--;
		usleep(1000);
	}
}

void	send_str(const pid_t pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3)
	{
		write(2, "Error : Please enter a single string\n", 37);
		exit (1);
	}
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (ft_isdigit(argv[1][i++]) == 0)
		{
			write(2, "Error : PID contains invalid characters\n", 40);
			exit (1);
		}
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(2, "Error : PID is 0 or Negative or exceeds the limit\n", 47);
		exit (1);
	}
	send_str(pid, argv[2]);
	return (0);
}
