/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <XXX>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:44:51 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/10 21:18:25 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	slen;
	char	*ret;
	size_t	i;

	slen = 0;
	while (s1[slen] != '\0')
	{
		slen++;
	}
	ret = (char *)malloc((slen + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i <= slen)
	{
		ret[i] = s1[i];
		i++;
	}
	return (ret);
}

/*
int	main(void)
{
	char	*p1;
	char	*p2;
	char	str[] = "abcde";
	p1 = ft_strdup(str);
	p2 = strdup(str);
	str[0] = 'z'; //strを書き換えてもpは新しいアドレスを持つので影響しない
	printf("str = %s\n", str);
	printf("str adress = %p\n", &str);
	printf("p1 = %s\n", p1);
	printf("p1  adress = %p\n", &p1);
	printf("p2 = %s\n", p2);
	printf("p2 adress = %p\n", &p2);
	return (0);
}
*/
