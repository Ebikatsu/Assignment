#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

void preorder(struct node *p)
{
	if(p == NULL) return;
	printf("%d", p->data);
	preorder(p->left);
	preorder(p->right);
}

main()
{
	struct node *root, *p[5];
	int i;

	for(i = 0; i < 5; i++){
		p[i] = (struct node *)malloc(sizeof(struct node));
		p[i]->data = i;
		p[i]->left = NULL;
		p[i]->right = NULL;
	}

	p[0]->left = p[1];
	p[0]->right = p[2];
	p[1]->left = p[3];
	p[1]->right = p[4];

	root = p[0];

	preorder(root);

	return 0;
}
