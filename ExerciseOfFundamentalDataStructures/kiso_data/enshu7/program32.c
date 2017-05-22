#include <stdio.h>
#include <string.h>

#define N 10
#define dKeySize (12)

typedef struct _NODE
{
	char key[dKeySize];
} NODE;

/*
int LinearSearch(char *target, NODE table[], int n)
{
	int pos;

	for(pos = 0; pos < n; pos++) {
		if(!strcmp(target, table[pos].key)) {
			return pos;
		}
	}

	return -1;
}
*/

int SentinelSearch(char *target, NODE table[], int n)
{
	int pos;

	strcpy(table[n].key, target);
	pos = 0;
	while(strcmp(target, table[pos].key)){
		pos++;
	}

	return pos == n ? -1 : pos;
}

int main(void){

	NODE table[N] = {{"grape"},{"banana"},{"apple"},{"cherry"},{"orange"},{"melon"},{"strawberry"}};
	//注意：構造体の配列の初期化(7件分のデータを格納)

	char Key[dKeySize];
	int s;

	printf("search data ? ");
	scanf("%s", Key);

	//s = LinearSearch(Key, table, 7);
	s = SentinelSearch(Key, table, 7);

	if(s == -1)
		printf("Not find !\n");
	else
		printf("%d\n", s);

	return 0;
}
