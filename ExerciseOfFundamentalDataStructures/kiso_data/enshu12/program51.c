#include<stdio.h>
#include<string.h>

//#define DEBUG

main()
{
	//char text[100], key[10];
	char *text = "abcabcababcababxabcabx", *key = "abcaba";
	int i, j, m, n;


	//scanf("%s %s", text, key);

	m = strlen(text);
	n = strlen(key);

	#ifdef DEBUG
	printf("n = %d\n", n);
	printf("m = %d\n", m);
	#endif

	for(i = 0; i <= m - n; i++){

		#ifdef DEBUG
		printf("i = %d\n", i);
		#endif

		for(j = 0; text[i + j] == key[j]; j++){

			#ifdef DEBUG
			printf("j = %d\n", j);
			#endif

			if(j == n - 1)printf("%d\n", i + 1);
		}
	}

	return 0;
}
