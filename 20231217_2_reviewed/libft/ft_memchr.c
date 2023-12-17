/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <XXX>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:30:57 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/10 20:19:52 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*char_s;
	unsigned char	unchar_c;

	if (n == 0)
		return (NULL);
	char_s = (unsigned char *)s;
	unchar_c = (unsigned char)c;
	while (n--)
	{
		if (*char_s == unchar_c)
			return (char_s);
		char_s++;
	}
	if (unchar_c == 0 && *char_s == unchar_c)
		return (char_s);
	return (NULL);
}

/*
int	main(void)
{
	char	test[] = "tripouille";
	char	*p;

	//printf("%c\n", 't'+1);

	//p = ft_memchr(test, 0, 0);
	p = memchr(test, 0, 0);
	printf("ret= %s\n", p);
	return (0);
}
*/
