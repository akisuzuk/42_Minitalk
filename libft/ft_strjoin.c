/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <XXX>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:40:53 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/10 20:47:59 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*store(char const *pre, char const *suf, char *ret);

static	char	*store(char const *pre, char const *suf, char *ret)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (pre[i] != '\0')
	{
		ret[j] = pre[i];
		i++;
		j++;
	}
	i = 0;
	while (suf[i] != '\0')
	{
		ret[j] = suf[i];
		i++;
		j++;
	}
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	prelen;
	size_t	suflen;

	if (!s1 || !s2)
		return (NULL);
	prelen = ft_strlen(s1);
	suflen = ft_strlen(s2);
	ret = malloc(sizeof(char) * (prelen + suflen + 1));
	if (!ret)
		return (NULL);
	ret = store(s1, s2, ret);
	ret[prelen + suflen] = '\0';
	return (ret);
}

// char	*ft_strjoin(const char *s1, const char *s2)
// {
// 	char	*ret;
// 	char	*head;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
// 	if (ret == NULL)
// 		return (0);
// 	head = ret;
// 	while (*s1)
// 		*ret++ = *s1++;
// 	while (*s2)
// 		*ret++ = *s2++;
// 	*ret = '\0';
// 	return (head);
// }

//int	main(void)
//{
//	char	str1[] = "tripouille";
//	char	str2[] = "42";
//	char	*joined;
//
//	printf("str1=%s\n", str1);
//	printf("str2=%s\n", str2);
//	joined = ft_strjoin(str1, str2);
//	// あれっこれ公式関数が存在しない？
//	//joined = strjoin(str1, str2);
//	printf("ret=%s\n", joined);
//	printf("strcmp=%d\n", strcmp(joined, "42"));
//	free(joined);
//}
//
