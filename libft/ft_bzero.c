/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <XXX>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:15:47 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/10 20:18:49 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*unchar_s;

	if (n != 0)
	{
		unchar_s = (unsigned char *)s;
		i = 0;
		while (i < n)
		{
			*unchar_s++ = '\0';
			i++;
		}
	}
	return (s);
}

//
//int	main(void)
//{
//	char	str1[256];
////	char	str2[256];
//	int		n;
//
//	str1[0] = 'a';
//	str1[1] = 'b';
//	str1[2] = 'c';
//	str1[3] = 'd';
//	str1[4] = 'e';
//	str1[5] = '\0';
////	str2[0] = 'A';
////	str2[1] = 'B';
////	str2[2] = 'C';
////	str2[3] = '\0';
//	n = 0;
//	printf("str1=%s\n", str1);
//	//ft_memset(str1+1, 1, 2);
//	ft_bzero(str1+1, 2);
//	printf("str1=%s\n", str1);
//	printf("------------\n");
//	return (0);
//}
//
