/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:54:46 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/07/16 18:26:05 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// signalとsigactionを使う課題だと理解
// シグナルハンドラという、プログラムに対してシグナルが送られた時に実行される関数を作っていく(登録する、と言う
// そのシグナルハンドラの登録に、signalとsigactionがあること

// signal関数は、signal(シグナルの種類, シグナルハンドラとしたい関数)という形で使う
// ※シグナルの種類。。。SIGINT, SIGQUIT, SIGKILL, SIGSEGV, SIGTERM, SIGSTOP, SIGCONT, SIGTSTP, SIGUSR1, SIGUSR2, SIGCHLD, SIGWINCH, SIGINFO, SIGPIPE, SIGALRM, SIGFPE, SIGILL, SIGABRT, SIGBUS, SIGTRAP, SIGSYS, SIGURG, SIGXCPU, SIGXFSZ, SIGVTALRM, SIGPROF, SIGIO, SIGPWR, SIGSTKFLT, SIGEMT, SIGINFO, SIGLOST, SIGPOLL, SIGPWR, SIGRTMIN, SIGRTMAX
// ※シグナルハンドラとしたい関数。。。void型の引数を一つ取り、void型の戻り値を返す関数
// 例えば、signal(SIGINT, sigint_handler)とすると、SIGINTというシグナルが送られた時に、sigint_handlerという関数が実行される

// 一方でsigactionは構造体を使用する
// とりあえず①sigactionの構造体を宣言　struct sigaction sa;
// ②sigemptyset(&sa.sa_mask)でsaのシグナルマスクをクリアする→ 例：sigemptyset(&sa.sa_mask);
// ③sa.sa_handlerに、シグナルハンドラとしたい関数を代入する→ 例：sa.sa_handler = function;
// ④sa.sa_flagsに、シグナルハンドラの挙動を指定する→ 例：sa.sa_flags = SA_RESTART;
// ※今回は特に何もなければ、sa.sa_flags = 0;としておけば良い

#include "ft_minitalk.h"

int	main(int ac, char **av)
{
    (void)ac;
    kill((pid_t)atoi(av[1]), SIGSEGV);
    return 0;
}
