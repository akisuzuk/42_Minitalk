/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:56:58 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/12/17 13:58:37 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
// # include <climits> // not for C but CPP
# include <limits.h>
# include <stdbool.h>
# include <stdarg.h>
# include <fcntl.h>
# include <signal.h>

int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putnbr_fd(int n, int fd);
int		ft_isdigit(int c);

#endif
