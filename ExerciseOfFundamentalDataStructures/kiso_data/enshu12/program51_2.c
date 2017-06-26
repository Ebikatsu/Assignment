#include<stdio.h>
#include<string.h>

main()
{
	//char text[100], key[10];
	char *text = "abcabcababcababxabcabx", *key = "abcaba";
	int i, j, m, n;
	//scanf("%s %s", text, key);
	m = strlen(text);
	n = strlen(key);
	for(i = 0; i <= m - n; i++){
		printf("i = %d; ", i);
		for(j = 0; text[i + j] == key[j]; j++){
			printf("j = %d; ", j);
			if(j == n - 1)printf("%d\n", i + 1);
		}
		printf("\n");
	}
	return 0;
}
