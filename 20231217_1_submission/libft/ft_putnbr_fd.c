/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <XXX>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:53:51 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/10 20:46:58 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_len(int n);
static	size_t	ft_pow(size_t n);

static	size_t	count_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static	size_t	ft_pow(size_t n)
{
	size_t	ret;
	size_t	i;

	ret = 1;
	i = 0;
	while (i < n)
	{
		ret *= 10;
		i++;
	}
	return (ret);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		base;
	int		num_len;
	char	num;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
		write(fd, "-", 1);
	num_len = count_len(n);
	base = ft_pow(num_len - 1);
	while (num_len)
	{
		if (n < 0)
			num = ((n / base) % 10) * -1 + '0';
		else
			num = n / base % 10 + '0';
		write(fd, &num, 1);
		num_len--;
		base /= 10;
	}
}

//int	main(void)
//{
//	ft_putnbr_fd(-2147483648, 1);
//	printf("\n");
//	ft_putnbr_fd(123456789, 1);
//	printf("\n");
//	ft_putnbr_fd(-123, 1);
//	printf("\n");
//	ft_putnbr_fd(0, 1);
//	printf("\n");
//	ft_putnbr_fd(-123, 1);
//	printf("\n");
//	ft_putnbr_fd(-2, 1);
//	printf("\n");
//	return (0);
//}
//
//
