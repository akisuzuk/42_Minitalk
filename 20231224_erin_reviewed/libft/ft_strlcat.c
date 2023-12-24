/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:10:05 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/11 20:37:08 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(src);
	if (!dst && src && dstsize == 0)
		return (slen);
	dlen = ft_strlen(dst);
	i = 0;
	while (i + (dlen + 1) < dstsize && src[i] != '\0')
	{
		dst[dlen + i] = src[i];
		i++;
	}
	if (dstsize != 0 && dlen < dstsize)
		dst[i + dlen] = '\0';
	if (dlen > dstsize)
		dlen = dstsize;
	return (dlen + slen);
}

// int	main(void)
// {
// 	// あれっターミナルの検証がうまくいってなかったの、printfの書式とかが原因か。。。？
// 	char			str1[] = "AAAAAAAAAA";
// 	const char			str2[] = "BBB";
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	printf("ret = %zu\n", ft_strlcat(str1, str2, sizeof(str1)));
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	printf("-------------\n");
// 	char			str3[] = "AAAAAAAAAA";
// 	char			str4[] = "BBB";
// 	printf("%s\n", str3);
// 	printf("%s\n", str4);
// 	printf("ret = %zu\n", strlcat(str3, str4, sizeof(str3)));
// 	printf("%s\n", str3);
// 	printf("%s\n", str4);
// 	return (0);
// }
