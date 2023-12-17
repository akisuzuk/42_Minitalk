/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <XXX>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:30:57 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/10 20:22:05 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		char_c;
	const char	*last;
	int			flag;

	last = 0;
	char_c = (char)c;
	while (*s)
	{
		if (*s == char_c)
		{
			last = s;
			flag = 1;
		}
		s++;
	}
	if (char_c == '\0')
	{
		last = s;
		flag = 1;
	}
	if (flag == 1)
		return ((char *)last);
	else
		return (NULL);
}

//
//int	main(void)
//{
//	char	test[] = "tripouille";
//	char	*p;
//
//	//printf("%c\n", 't'+1);
//	//p = strrchr(test, 0);
//	p = ft_strrchr(test, '\0');
//	printf("ret= %s\n", p);
//	// ↓ここのif文、pがnullの場合条件文でチェックするだけでセグフォ発動するので注意
//	if(*p == '\0')
//		printf("*p==EOS!\n");
//	if(p == NULL)
//		printf("*p==NULL!\n");
//	return (0);
//}
//
//
