/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <XXX>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:09:35 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/10 20:22:12 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*head;
	int		s_len;
	int		int_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *) s);
	int_len = (int)len;
	if (int_len > s_len)
		len = (size_t)s_len;
	ret = malloc((sizeof(char) * (len + 1)));
	if (!ret)
		return (NULL);
	head = ret;
	while (start-- && *s != '\0')
		s++;
	while (len-- && *s != '\0')
		*ret++ = *s++;
	*ret = '\0';
	return (head);
}

//int	main(void)
//{
//	char	str1[] = "abcdefgh";
//	char	*sub;
//
//	printf("str1=%s\n", str1);
//	sub = ft_substr(str1, 2, 3);
//	printf("ret=%s\n", sub);
//	free(sub);
//}
//
