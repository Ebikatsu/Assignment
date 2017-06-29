#include<stdio.h>

int main(void)
{
	//試験点、課題点、演習点、成績の整数変数
	int	shiken,kadai,kougi,enshu,seiseki;
	float	f1;	//四捨五入の処理に使う実数変数
	//キーボードから点数を入力する。
	printf("試験点を入力してください。> ");	scanf("%d", &shiken);
	printf("課題点を入力してください。> ");	scanf("%d", &kadai);
	printf("演習点を入力してください。> ");	scanf("%d", &enshu);
	//講義点を実数で計算し(そのままキャストすると小数点以下切り捨てになってしまうので四捨五入するために)0.5を加える
	f1 = shiken*0.5+kadai*0.23+0.5;
	kougi = (int)f1;	//四捨五入のため小数点以下を切り捨て
	printf("講義点:%d点\n", kougi);	//講義点を表示
	seiseki = kougi + enshu;	//成績を求める
	//成績60点以上でも講義点44点未満の場合、成績59点の不合格とし表示する
	if(kougi < 44)seiseki = 59;
	//printf("成績の判定を表示/n");
	printf("成績:%d点\n", seiseki);	//printfを使っているということは点数を表示しろということでは？
	if(seiseki >= 0 && seiseki <= 59)puts("不可・再履修が必要");
	if(seiseki >= 60 && seiseki <= 69)puts("可・何とか合格");
	if(seiseki >= 70 && seiseki <= 79)puts("良・がんばった");
	if(seiseki >= 80 && seiseki <= 100)puts("優・優秀です");
	if(seiseki < 0 || seiseki > 100)puts("入力誤り");
	return(0);	//0を返して終了
}

