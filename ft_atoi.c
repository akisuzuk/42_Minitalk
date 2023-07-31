/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <XXX>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:38:35 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/10 20:45:52 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	bool	is_over_long(long ret, const char *str, int sign);

static	bool	is_over_long(long ret, const char *str, int sign)
{
	if (sign == 1)
	{
		if (ret > LONG_MAX / 10)
			return (true);
		if (ret == LONG_MAX / 10 && *str - '0' > LONG_MAX % 10)
			return (true);
	}
	else
	{
		if (ret < LONG_MIN / 10)
			return (true);
		if (ret == LONG_MIN / 10 && - (*str - '0') < LONG_MIN % 10)
			return (true);
	}
	return (false);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	ret;

	if (!*str)
		return (0);
	ret = 0;
	sign = 1;
	while (*str == 0 || (*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	if (*str < '0' || *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1 && is_over_long(ret, str, sign))
			return ((int)LONG_MAX);
		if (sign == -1 && is_over_long(ret, str, sign))
			return ((int)LONG_MIN);
		ret = ret * 10 + (*str++ - '0') * (sign);
	}
	return (ret);
}

//int	main(void)
//{
//	//char escape[] = {9, 10, 11, 12, 13, 0};
//	char escape[] = {9, 10, 11, 12, 13, 0};

//	//argc = 1;
//	//printf("str=%s\n", argv[1]);
//	//printf("str=%s\n", escape);
//	//printf("ft_atoi = %d\n", ft_atoi(escape));
//	//printf("str=%s\n", escape);
//	//printf("---test21--------\n");
//	//printf("orgin_atoi = %d\n", atoi("-9223372036854775808"));
//	//printf("ft_atoi = %d\n", ft_atoi("-9223372036854775808"));
//	//printf("---test28--------\n");
//	//printf("orgin_atoi = %d\n", atoi("-9223372036854775809"));
//	//printf("ft_atoi = %d\n", ft_atoi("-9223372036854775809"));
//	//printf("---test35--------\n");
//	//printf("orgin_atoi = %d\n", atoi("-9223372036854775807"));
//	//printf("ft_atoi = %d\n", ft_atoi("-9223372036854775807"));
//	//printf("---test34--------\n");
//	//printf("orgin_atoi = %d\n", atoi("9223372036854775806"));
//	//printf("ft_atoi = %d\n", ft_atoi("9223372036854775806"));
//	printf("orgin_atoi = %d\n", atoi(""));
//	printf("ft_atoi = %d\n", ft_atoi(""));
//	return (0);
//}

//ret = ret*10 + str[i] - '0';
