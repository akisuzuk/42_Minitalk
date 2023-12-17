/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <XXX>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:20:22 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/10 20:46:12 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_size(int n);

static	size_t	count_size(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = count_size(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		if (n < 0)
			str[len - 1] = -(n % 10) + '0';
		else
			str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

//#include <stdio.h>
//
//int main(void)
//{
//	ft_itoa(0);
//	return (0);
//}

//int	main(void)
//{
//	char *result;
//
//	//result = ft_itoa(-12345);
//	result = ft_itoa(-123);
//	printf("ft_itoa = %s\n", result);
//	free(result);
//	return (0);
//}
//
