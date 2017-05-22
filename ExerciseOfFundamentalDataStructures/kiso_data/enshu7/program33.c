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

int BinarySearch(char *target, NODE table[], int n)
{
	int low = 0;
	int high = n - 1;
	int middle;
	int cmp;

	while(low <= high){
		middle = (low + high) / 2;
		cmp = strcmp(table[middle].key, target);
		if(cmp < 0){
			low = middle + 1;
		}
		else if(cmp > 0){
			high = middle - 1;
		}
		else{
			return middle;
		}
	}

	return -1;
}

int main(void){

	//NODE table[N] = {{"grape"},{"banana"},{"apple"},{"cherry"},{"orange"},{"melon"},{"strawberry"}};
	NODE table[N] = {{"apple"},{"banana"},{"cherry"},{"grape"},{"melon"},{"orange"},{"strawberry"}};
	//注意：構造体の配列の初期化(7件分のデータを格納)

	char Key[dKeySize];
	int s;

	printf("search data ? ");
	scanf("%s", Key);

	//s = LinearSearch(Key, table, 7);
	s = BinarySearch(Key, table, 7);

	if(s == -1)
		printf("Not find !\n");
	else
		printf("%d\n", s);

	return 0;
}
