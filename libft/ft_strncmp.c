/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:00:11 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/11 20:21:12 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		if (i == n - 1)
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

//int	main(void)
//{
//
//	char *str = "libft-test-tokyo";
//	char *cmp = "libft";
//	size_t	n;
//
//	cmp[5] = -42;
//	n = 20;
//	printf("str=%s\n", str);
//	printf("cmp=%s\n", cmp);
//	//printf("ft = %d\n", ft_strncmp(str, cmp, n));
//	printf("-------------\n");
//	printf("origin = %d\n", strncmp(str, cmp, n));
//	return (0);
//}
