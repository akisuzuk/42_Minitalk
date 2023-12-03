/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <XXX>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:15:47 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/10 20:20:32 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*unchar_dst;
	const unsigned char	*cons_unchar_src;

	if (!dst && !src)
		return (NULL);
	unchar_dst = (unsigned char *)dst;
	cons_unchar_src = (const unsigned char *)src;
	if (dst <= src)
	{
		while (len--)
			*unchar_dst++ = *cons_unchar_src++;
	}
	else
	{
		unchar_dst += len;
		cons_unchar_src += len;
		while (len--)
			*--unchar_dst = *--cons_unchar_src;
	}
	return (dst);
}

//
//int	main(void)
//{
////	char	str1[256];
////	char	str2[256];
////	int		n;
////
////	str1[0] = 'a';
////	str1[1] = 'b';
////	str1[2] = 'c';
////	str1[3] = 'd';
////	str1[4] = 'e';
////	str1[5] = '\0';
////	str2[0] = 'A';
////	str2[1] = 'B';
////	str2[2] = 'C';
////	str2[3] = '\0';
////	n = 0;
////	printf("str1=%s\n", str1);
////	printf("%s\n", str2);
////	//ft_memmove(str1+1, str2, 2);
////	memmove(str1+1, str2, 2);
////	printf("str1=%s\n", str1);
////	printf("%s\n", str2);
////
//	char s[] = {65, 66, 67, 68, 69, 0, 45};
//	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
//	char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
//	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
//	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};
//
//	//ft_memmove(s0, s, 7);
//	//memmove(s0, s, 7);
//	printf("dst=%s\n", s0);
//	printf("src=%s\n", s);
//	ft_memmove(s0, s, 7);
//	memmove(s0, s, 7);
//	printf("dst_after=%s\n", s);
//	return (0);
//}
//
