/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:54:50 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/11/18 21:08:05 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

// sig_atmic_tは、シングルハンドラ内でアトミックな操作を行うための"int 整数"の型
// シグナルハンドラ内で変数を変更する場合、その変数が複数のシグナルハンドラから
// 割り込みされることがなくなり、安全に変更される。
// これによりメインプログラムとシグナルハンドラの間でデータの競合が起きなくなる。
// volatileは、Cで使用される修飾子の一つであり、外部から変更されうる変数に対して、
// コンパイラの最適化の対象外とすることを示す。
volatile sig_atomic_t	g_char = 0;

// siginfo構造体はシグナルハンドラに渡される情報を格納する構造体
// 今回は、送信元のプロセスIDを取得するために使用する
void	signal_handler(int signum, siginfo_t *info, void *context)
{
	// 静的なローカル変数のため、プログラムが実行される間はメモリ上に存在し続ける
	// g_charもそうだけど、グローバル変数は1つだけってルールだからこうしてる？？
	static int	i;
	char		c;

	(void) info;
	(void) context;
	// ビットシフト演算子を使って、送信元が送ってきた文字を一つずつ取得する
	g_char = g_char << 1;
	// 送信元のプロセスIDの最下位ビットが1なら、g_charの最下位ビットを1にする
	if (signum == SIGUSR1)
		// g_charと1の論理和をとることで、g_charの最下位ビットを1にする(orなので必ず1になる)
		g_char = g_char | 1;
		//g_char |= 1;
	// 送信元のプロセスIDの最下位ビットが0なら特に何もしない
	// うーんこれわざわざif文で書かなくてもいいんじゃないかな。詳しくないからわからんけど
	else if (signum == SIGUSR2)
		;
	i++;
	// g_charのビット表現と0xffの論理積をとることで、g_charの最下位8ビットを取得する
	// 0xffは、00000000 00000000 00000000 11111111というビット表現を持つ16進数
	// よって、g_charの最下位8ビットを取得できる
	// このような操作は、ビット操作を利用して特定のビット範囲の値をビット範囲の値を取得するために使われる。
	c = 0xff & g_char;
	if (i == 8)
	{
		// 第一引数はいつの標準出力で1にしてるが、略さずに記述するとSTDOUT_FILENO
		write(STDOUT_FILENO, &c, 1);
		i = 0;
	}
}

int	main(void)
{
	// sigaction構造体はシグナルハンドラの情報を格納する構造体
	struct sigaction	act1;
	struct sigaction	act2;

	printf("not so bad minitalk server pid=%d\n", getpid());
	// 構造体の初期化
	ft_memset(&act1, 0, sizeof(sigaction));
	ft_memset(&act2, 0, sizeof(sigaction));
	// シグナルハンドラに関数を割り当て(シグナルハンドラの設定)
	// 他の構造体メンバーであるsa_handlerにも割り当てることができるが、
	// sa_sigactionを使うと、シグナルハンドラに引数を渡すことができるなど複雑な操作ができる
	act1.sa_sigaction = signal_handler;
	act2.sa_sigaction = signal_handler;
	// フラグは0でもOKらしいが、SA_SIGINFOを指定する
	// SA_SIGINFOを指定するとシグナルの詳細な情報が引数に渡されるとか
	// (両者の違い分かってないけど)SA_SIGINFOを指定するとsa_sigactionが呼ばれる
	// SA_SIGINFOを指定しないとsa_handlerが呼ばれる
	act1.sa_flags = SA_SIGINFO;
	act2.sa_flags = SA_SIGINFO;
	// act1,2を実行中はお互いのシグナルをブロックするようにマスクを追加
	sigaddset(&act1.sa_mask, SIGUSR2);
	sigaddset(&act2.sa_mask, SIGUSR1);
	// 最後にsigaction関数を使って、シグナルハンドラの登録完了
	// ここで初めてSIGUSR1, 2に対応するシグナルハンドラ（に、対応する関数）を割り当てる
	// 第一引数はシグナルの種類、第二引数はシグナルハンドラの情報を格納した構造体
	// 第三引数は、シグナルハンドラの登録前のシグナルハンドラの情報を格納した構造体
	sigaction(SIGUSR1, &act1, NULL);
	sigaction(SIGUSR2, &act2, NULL);
	// シグナルハンドラの登録完了後は、無限ループで待機する
	// ctl + cで終了する
	while (1)
		// pause関数は、シグナルが届くまでプロセスを停止する
		pause();
}
