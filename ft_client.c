/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:54:46 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/07/16 18:44:44 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// file:///Users/akisuzuk/Downloads/645763cf71dca0d205219559.pdf
// https://onedrive.live.com/?authkey=%21ABrqrVGxVxFhHMU&id=518C1E08C43073F5%211605&cid=518C1E08C43073F5&parId=root&parQt=sharedby&parCid=A5113E935F3D0D56&o=OneUp
// https://qiita.com/keitean/items/c641b3e158e01dacb7f6
// https://en-junior.com/sigaction-signal/


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

// 異なるプロセス(プログラム)間での通信には、kill関数を使う
// kill関数は、kill(プロセスID, シグナルの種類)という形で使う
// 今回使えるシグナルはSIGUSR1とSIGUSR2のみ

// 今回の課題では、サーバー側で受け取った文字を表示するということを行う
// 流れとしてはserverをバックグラウンドで起動し、その後clientを起動する
// clientは、kill関数を使ってサーバーに文字を送る
// これ、ターミナルを2つ開いて、それぞれでserverとclientを起動することで実現できるってこと？


#include "ft_minitalk.h"

int	main(int ac, char **av)
{
    (void)ac;
    kill((pid_t)atoi(av[1]), SIGSEGV);
    return 0;
}
