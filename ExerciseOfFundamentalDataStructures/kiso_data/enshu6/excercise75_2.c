#include <stdio.h>
#include <stdlib.h>

#define NODELENGTH 9

struct node{
	int data;
	struct node *left;
	struct node *right;
};

/*
void preorder(struct node *p)
{
	if(p == NULL) return;
	printf("%d", p->data);
	preorder(p->left);
	preorder(p->right);
}
*/

void inorder(struct node *p)
{
	if(p == NULL) return;
	inorder(p->left);
	printf("%d", p->data);
	inorder(p->right);
}

/*
void postorder(struct node *p)
{
	if(p == NULL) return;
	postorder(p->left);
	postorder(p->right);
	printf("%d", p->data);
}
*/

main()
{
	struct node *root, *p[NODELENGTH];
	int i;

	for(i = 1; i <= NODELENGTH ; i++){
		p[i-1] = (struct node *)malloc(sizeof(struct node));
		p[i-1]->data = i;
		p[i-1]->left = NULL;
		p[i-1]->right = NULL;
	}

	/*
	p[0]->left = p[1];
	p[0]->right = p[2];
	p[1]->left = p[3];
	p[1]->right = p[4];
	*/
	p[3-1]->left = p[8-1];
	p[3-1]->right = p[5-1];
	p[8-1]->left = p[1-1];
	p[8-1]->right = p[9-1];
	p[1-1]->left = p[4-1];
	p[1-1]->right = p[6-1];
	p[5-1]->right = p[7-1];
	p[7-1]->left = p[2-1];

	root = p[3-1];

	//preorder(root);
	inorder(root);

	return 0;
}
