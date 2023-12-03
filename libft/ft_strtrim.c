/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <XXX>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:40:53 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/07 14:13:26 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	i;
	size_t	head;
	size_t	tail;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return ((char *)ft_calloc(1, 1));
	head = 0;
	while (ft_strchr(set, s1[head]) && s1[head] != '\0')
		head++;
	tail = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[tail]) && head < tail)
		tail--;
	if (head <= tail)
		ret = malloc(sizeof(char) * (tail - head + 2));
	if (tail < head || !ret)
		return ((char *)ft_calloc(1, 1));
	i = 0;
	while (head <= tail)
		ret[i++] = s1[head++];
	ret[i] = '\0';
	return (ret);
}

//int	main(void)
//{
//	char	str1[] = "   xxx   xxx";
//	char	str2[] = " x";
//	//char	str1[] = "lorem ipsum dolor sit amet";
//	//char	str2[] = "te";
//	char	*joined;
//	printf("str1=%s\n", str1);
//	printf("str2=%s\n", str2);
//	printf("strlen(str2)=%lu\n", strlen(str2));
//	printf("---------------\n");
//	joined = ft_strtrim(str1, str2);
//	printf("---------------\n");
//	printf("ret=%s\n", joined);
//	//printf("strcmp=%d\n", strcmp(joined, "42"));
//	free(joined);
//}
//
