/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:54:50 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/08/12 23:12:20 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	main(void)
{
	struct sigaction	act1;
	struct sigaction	act2;

	printf("not so bad minitalk server pid=%d\n", getpid());
	// 構造体の初期化
	ft_memset(&act1, 0, sizeof(sigaction));
	ft_memset(&act2, 0, sizeof(sigaction));
	act1.sa_sigaction = signal_handler;
	act2.sa_sigaction = signal_handler;
	// フラグは0でもOKらしいが、SA_SIGINFOを指定する
	// SA_SIGINFOを指定するとシグナルの詳細な情報が引数に渡されるとか
	// (両者の違い分かってないけど)SA_SIGINFOを指定するとsa_sigactionが呼ばれる
	// SA_SIGINFOを指定しないとsa_handlerが呼ばれる
	act1.sa_flags = SA_SIGINFO;
	act2.sa_flags = SA_SIGINFO;
	while (1)
		return (0);
}
