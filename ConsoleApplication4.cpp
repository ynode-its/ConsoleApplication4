// ConsoleApplication4.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define ULONGLONG unsigned long long

typedef struct _double
{
	ULONGLONG cnt;
	double dbl;
	double dbl100;
	char str[64];
	char str100[64];
	char strres[64];
} ST_DOUBLE;

ULONGLONG CreateDouble(ST_DOUBLE* pdbl, ULONGLONG cnt)
{
	pdbl->cnt = cnt;
	sprintf(pdbl->str, "%llu.%08llu", cnt / 100000000, cnt % 100000000);
	sprintf(pdbl->strres, "%llu.%02llu", cnt / 100, cnt % 100);
	pdbl->dbl = atof(pdbl->str);
	pdbl->dbl100 = pdbl->dbl * 1000000;
	sprintf(pdbl->str100, "%.2f", pdbl->dbl100);

	cnt++;
	return cnt;
}
void Disp(ST_DOUBLE* pdbl)
{
	printf("\033[38;5;09%s(%lld): %s =! %s %.20f\033[0m\n", pdbl->str, pdbl->cnt, pdbl->strres, pdbl->str100, pdbl->dbl);
}

int main()
{
	char tm[64];
	time_t t;
	ST_DOUBLE dbl;
	ULONGLONG cnt = (ULONGLONG)3355443199299999;
	ULONGLONG end = (ULONGLONG)9999999999999999;

	t = time(NULL);
	strftime(tm, sizeof(tm), "%Y/%m/%d %H:%M:%S\n", localtime(&t));
	printf("S %s", tm);

	while (end >= cnt)
	{
		cnt = CreateDouble(&dbl, cnt);
		if (0 != strcmp(dbl.str100, dbl.strres))
		{
			Disp(&dbl);
		}
		if (cnt % 10000000 == 0)
		{
			t = time(NULL);
			strftime(tm, sizeof(tm), "%Y/%m/%d %H:%M:%S", localtime(&t));
			printf("%lld\n", cnt / 10000000);
			printf("%s\n", tm);
			Disp(&dbl);
		}
	}
	t = time(NULL);
	strftime(tm, sizeof(tm), "%Y/%m/%d %H:%M:%S\n", localtime(&t));
	printf("E %s", tm);
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
