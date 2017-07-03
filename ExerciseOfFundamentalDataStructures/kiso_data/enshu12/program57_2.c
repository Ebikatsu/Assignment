#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SKIP_LENGTH 26

int skip[SKIP_LENGTH];

void BMmatching(char *text, char *key);
void mkskip(char *key);

int main(void)
{
	//char text[100], key[10];
	char *text = "abcabcababcababxabcabx", *key = "abcaba";
	//scanf("%s %s", text, key);
	mkskip(key);
	BMmatching(text, key);
	return EXIT_SUCCESS;
}

void BMmatching(char *text, char *key)
{
	int i, j, m, n, pos, k;
	m = strlen(text);
	n = strlen(key);
	pos = n - 1;
	while(pos < m)
	{
		if(text[pos] == key[n - 1])
		{
			printf("text[%d] = %cとkey[%d] = %cは一致\n", pos, text[pos], n - 1, key[n - 1]);
			k = pos - 1;
			j = n - 2;
			while(j > 0 && text[k] == key[j])
			{
				printf("text[%d] = %cとkey[%d] = %cは一致\n", k, text[k], j, key[j]);
				k--;
				j--;
			}
			if(j == 0)printf("照合開始位置:%d\n", k + 1);
		}
		pos += skip[text[pos] - 'a'];
		printf("posにskipの数値を加算:pos = %d\n", pos);
	}
	return;
}

void mkskip(char *key)
{
	int i, n;
	n = strlen(key);
	for(i = 0; i < SKIP_LENGTH; i++)
	{
		skip[i] = n;
		printf("skip[%d] = %d\n", i, skip[i]);
	}
	for(i = 0; i < n - 1; i++)
	{
		skip[key[i] - 'a'] = n - i - 1;
		printf("skip[%d] = %d\n", i, skip[i]);
	}
	return;
}
