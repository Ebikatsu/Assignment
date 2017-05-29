#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dKeySize 12
#define HASH_VALUES 7

typedef struct _NODE
{
	char key[dKeySize];
	struct _NODE *next;
} NODE;

int Hash(char *key)
{
	return *key - 'a';
}

NODE *HashSearch(char *target, NODE *table[], int b)
{
	int index;
	NODE *node;

	index = Hash(target) % b;
	node = table[index];
	while(node != NULL){
		if(!strcmp(node->key, target)){
			return node;
		}
		node = node->next;
	}
	return NULL;
}

int main (void)
{
  NODE *table[HASH_VALUES], *list[HASH_VALUES], *s;
  char Key[dKeySize];
  int i;

  printf("キーを入力して下さい:  ");
  scanf("%s", Key);

  for(i = 0; i < HASH_VALUES; i++){
    table[i] = (NODE *)malloc(sizeof(NODE));
    list[i] = (NODE *)malloc(sizeof(NODE));
    table[i]->next = NULL;
    list[i]->next = NULL;
  }

  strcpy(list[0]->key, "grape");
  strcpy(list[1]->key, "banana");
  strcpy(list[2]->key, "apple");
  strcpy(list[3]->key, "cherry");
  strcpy(list[4]->key, "orange");
  strcpy(list[5]->key, "melon");
  strcpy(list[6]->key, "strawberry");

  //図3.10 チェイン法を参考にせよ
  table[0]->next = list[2];
  list[2]->next = list[4];
  table[1]->next = list[1];
  table[2]->next = list[3];
  table[4]->next = list[6];
  table[5]->next = list[5];
  table[6]->next = list[0];

  s = HashSearch(Key,table,7);

  if(s == NULL)
    printf("入力されたキーは見つかりません\n");
  else 
    printf("%s が見つかりました\n", s->key);

  return 0;
}

