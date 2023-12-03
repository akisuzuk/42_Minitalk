/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <XXX>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:01:18 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/10 20:19:02 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

//
//int	main(void)
//{
//	printf("[origin]=%d\n", isalnum('a'-1));
//	printf("[ft]=%d\n", ft_isalnum('a'-1));
//	printf("=========\n");
//	return (0);
//}
//
