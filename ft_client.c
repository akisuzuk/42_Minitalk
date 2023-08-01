/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:54:46 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/08/02 00:28:25 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://onedrive.live.com/?cid=A5113E935F3D0D56&id=A5113E935F3D0D56%2132182&parId=A5113E935F3D0D56%2132181&o=OneUp
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
// ★SIGUSER1とは、ユーザーが定義したシグナルのことで、内容は自由に決められる

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
// 流れとしてはserver.cをバックグラウンドで起動し、その後client.cを起動する
// client.cは、kill関数を使ってサーバーに文字を送る
// これ、ターミナルを2つ開いて、それぞれでserver.cとclient.cを起動することで実現できるってこと？

// 20230730
// ポイントは、sigactionで組むことだけではなく、シグナルを2種類しか使えないということ
// なので、char型の情報を送るには、8bitの情報を1bitずつ送る必要がある
// これが、シリアル通信的な通信ということらしい
// コード上は、client.cがkill関数を使って文字を1bitずつ2種類のシグナルを使って送る

// 「割り込み」
// Xxx

// とりあえず「本当はむずかしいminitalk」のコードを追っかけてプログラムの流れを確認（sigaction使ってるp17あたり）

#include "ft_minitalk.h"

void	send_char(const pid_t pid, char c)
{
	int	digit;

	digit = 7;
	while (digit >= 0)
	{
		if (c & (1 << digit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		digit--;
		usleep(100);
	}
}

void	send_str(const pid_t pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
}

//						unsigned long long num_ull);

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);
}
