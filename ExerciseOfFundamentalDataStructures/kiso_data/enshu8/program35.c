#include <stdio.h>

#define dKeySize 12

int Hash(char *key)
{
	return *key - 'a';
}

int main (void){

  char Key[dKeySize];
  int index;

  printf("key data ? "); 
  scanf("%s", Key);

  index = Hash(Key) % 7;   

  printf("%s のハッシュ値は %d\n", Key, index);

  return 0;
}
