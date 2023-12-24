/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <XXX>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:40:49 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/10 20:22:00 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)(haystack));
	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] && needle[j] && i + j < len && haystack[i
				+ j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

//int	main(void)
//{
//	char	str1[] = "aaabcabcd";
//	char	str2[] = "aabc";

//	//printf("%s\n", str1);
//	//printf("%s\n", str2);
//	//printf("origin ret = %s\n", strnstr(str1, "abcd", 9));
//	//printf("myfunc ret = %s\n", ft_strnstr(str1, "abcd", 9));
//	//printf("---case114---\n");
//	//printf("origin ret = %s\n", strnstr("", "", 0));
//	//printf("myfunc ret = %s\n", ft_strnstr("", "", 0));
//	//printf("---case115---\n");
//	printf("origin ret = %s\n", ft_strnstr("fake", NULL, 0));
//	printf("myfunc ret = %s\n", strnstr("fake", NULL, 0));
//	return (0);
//}
