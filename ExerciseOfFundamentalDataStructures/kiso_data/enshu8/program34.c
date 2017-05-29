#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dKeySize 12

typedef struct _NODE
{
	char key[dKeySize];
	struct _NODE *left;
	struct _NODE *right;
} NODE;

NODE *TreeSearch(char *target,NODE *root)
{
	NODE *node = root;
	int cmp;

	while(node != NULL){
		cmp = strcmp(node->key, target);
		if(cmp < 0){
			node = node->right;
		}
		else if(cmp > 0){
			node=node -> left;
		}
		else{
			return node;
		}
	}
	return NULL;
}

NODE *GenTree(NODE *p, char *w)//木の作成の再帰手続き
{
	if(p == NULL){
	    p = (NODE *)malloc(sizeof(NODE));
	    strcpy(p->key, w);
	    p->left = NULL;
	    p->right = NULL;
	} else if(strcmp(w, p->key) < 0)
	         p->left = GenTree(p->left, w); 
	  else
	         p->right = GenTree(p->right, w); 

	return (p);
}

int main (void){
	char key[dKeySize];
	NODE *root, *node;
	
	root = NULL;
	while(scanf("%s", key) != EOF){
	  root = GenTree(root, key);//木の作成
	}
	printf("search data ? ");
	while(scanf("%s", key) != EOF){
          if((node = TreeSearch(key, root)) != NULL)  
	  	printf("%s is finded\n", node->key);
	  else
                printf("Not find\n");
	  printf("search data ? ");
	}

	return 0;
}

