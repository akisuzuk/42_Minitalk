/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <XXX>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:15:47 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/10 20:20:38 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ret;

	ret = (unsigned char *)b;
	while (len--)
		*ret++ = (unsigned char)c;
	return (b);
}

//int	main(void)
//{
//	char	str1[256];
//	int		n;
//	char	*result;
//
//	str1[0] = 'a';
//	str1[1] = 'b';
//	str1[2] = 'c';
//	str1[3] = 'd';
//	str1[4] = 'e';
//	str1[5] = '\0';
//
//	printf("str1=%s\n", str1);
////	printf("%s\n", str2);
//	result = ft_memset(str1, 1, 2);
//	printf("str1=%s\n", result);
//	printf("------------\n");
//	return (0);
//}
