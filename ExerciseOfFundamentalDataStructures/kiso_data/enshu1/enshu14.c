#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char c;
	printf("アルファベットを1文字入力してください。>>>");
	scanf("%c",&c);
	if(65 <= c && c <= 90)printf("文字は%c\n",c + 32);
	if(97 <= c && c <= 122)printf("文字は%c\n",c - 32);
	return EXIT_SUCCESS;
}
