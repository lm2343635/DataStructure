#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *root=NULL;

struct node *insert_node(int x, struct node *p) {
	if(p==NULL) {
		p=(struct node *)malloc(sizeof(struct node));
		p->data=x;
		p->left=NULL;
		p->right=NULL;
		return p;
	}
	if(x==p->data)
		return p;
	if(x<p->data)
		p->left=insert_node(x, p->left);
	else
		p->right=insert_node(x, p->right);
	return p;
}

int sum_node(struct node *p) {
	if(p==NULL)
		return 0;
	return sum_node(p->left)+sum_node(p->right)+p->data;
}

int search_node(int x, struct node *p) {
	struct node *q;
	q=p;
	while(q!=NULL) {
		if(x==q->data)
			return 1;
		if(x<q->data)
			q=q->left;
		else
			q=q->right;
	}
	return 0;
}

void inorder(struct node *p) {
	if(p==NULL)
		return;
	inorder(p->left);
	printf("%d ", p->data);
	inorder(p->right);
}

int main(int argc, char const *argv[]) {
	insert_node(1, root);
	insert_node(2, root);
	insert_node(3, root);
	insert_node(4, root);
	insert_node(5, root);
	inorder(root);
	printf("sum_node: %d\n", sum_node(root));
	printf("search_node 5: %d\n", search_node(5, root));
	return 0;
}
