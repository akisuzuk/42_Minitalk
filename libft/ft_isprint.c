/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <XXX>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:45:51 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/10 20:19:25 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
		return (0);
	else
		return (1);
}

/*
int	main(void)
{
	char	moji1;
	char	moji2;

	moji1 = 'c';
	moji2 = '3';
	printf("[origin]moji1=%d\n", isascii(moji1));
	printf("[origin]moji2=%d\n", isascii(moji2));
	printf("[ft]moji1=%d\n", ft_isascii(moji1));
	printf("[ft]moji2=%d\n", ft_isascii(moji2));
	return (0);
}
*/
