/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <XXX>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:15:47 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/10 20:21:41 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 1;
	while (len < dstsize && *src)
	{
		*dst++ = *src++;
		len++;
	}
	if (dstsize)
		*dst = '\0';
	while (*src++)
		len++;
	return (len - 1);
}

//
//int	main(void)
//{
//	char			str1[6];
//	char			str2[4];
//	int				n;
//	unsigned int	ret;
//
//	str1[0] = 'a';
//	str1[1] = 'b';
//	str1[2] = 'c';
//	str1[3] = 'd';
//	str1[4] = 'e';
//	str1[5] = '\0';
//	str2[0] = 'F';
//	str2[1] = 'G';
//	str2[2] = 'H';
//	str2[3] = '\0';
//	n = 2;
//	printf("%s\n", str1);
//	printf("%s\n", str2);
//	ret = ft_strlcpy(str1, str2, -1);
//	//ret = strlcpy(str1, str2, -1);
//	printf("---PROCESSED---\n");
//	printf("%s\n", str1);
//	printf("%s\n", str2);
//	printf("%d\n", ret);
//	return (0);
//}
//
