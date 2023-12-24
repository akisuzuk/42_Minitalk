/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <XXX>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:15:47 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/10 20:27:38 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*unchar_dst;
	const unsigned char	*cons_unchar_src;

	if (!dst && !src)
		return (NULL);
	if (n != 0)
	{
		i = 0;
		unchar_dst = (unsigned char *)dst;
		cons_unchar_src = (const unsigned char *)src;
		while (i < n)
		{
			*unchar_dst++ = *cons_unchar_src++;
			i++;
		}
	}
	return (dst);
}

//int	main(void)
//{
//	char	str1[256];
//	char	str2[256];
//	int		n;
//
//	str1[0] = 'a';
//	str1[1] = 'b';
//	str1[2] = 'c';
//	str1[3] = 'd';
//	str1[4] = 'e';
//	str1[5] = '\0';
//	str2[0] = 'A';
//	str2[1] = 'B';
//	str2[2] = 'C';
//	str2[3] = '\0';
//	n = 0;
//	printf("str1=%s\n", str1);
//	printf("%s\n", str2);
//	ft_memcpy(str1+1, str2, 2);
//	//memset(str1+1, 1, 2);
//	printf("str1=%s\n", str1);
//	printf("%s\n", str2);
//	return (0);
//}
//
