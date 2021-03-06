#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	int value;
	struct node *left;
	struct node *right;
};

struct node *root=NULL;

int height1(struct node *p) {
	int a, b;
	if(p==NULL) 
		return 0;
	a=height1(p->left);
	b=height1(p->right);
	if(a>=b)
		return a+1;
	else
		return b+1;
}

int height() {
	return height1(root);
}

void print1(struct node *p, int level) {
	int i;
	if(p==NULL)
		return;
	for(i=0; i<level; i++)
		printf("*");
	printf("key:%d, value:%d\n", p->key, p->value);
	print1(p->left, level+1);
	print1(p->right, level+1);
}

void print() {
	print1(root, 1);
}

struct node *make_node(int key, int value) {
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->key=key;
	p->value=value;
	p->left=NULL;
	p->right=NULL;
	return p;
}

void put1(struct node *p, int key, int value) {
	if(p->key==key) {
		p->value=value;
	} else if(key<p->key) {
		if(p->left==NULL)
			p->left=make_node(key, value);
		else
			put1(p->left, key, value);
	} else {
		if(p->right==NULL)
			p->right=make_node(key, value);
		else
			put1(p->right, key, value);
	}
}

void put(int key, int value) {
	if(root==NULL)
		root=make_node(key, value);
	else 
		put1(root, key, value);
}

int get1(struct node *p, int key) {
	if(p==NULL)
		return -1;
	if(p->key==key)
		return p->value;
	else if(p->key<key)
		return get1(p->left, key);
	else 
		return get1(p->right, key); 
}

int get(int key) {
	return get1(root, key);
}

int main(int argc, char const *argv[]) {
	// (2)
	put(40, 1);
	put(10, 2);
	put(70, 3);
	put(50, 1);
	put(85, 3);
	put(65, 2);
	// (5)
	// put(10, 2);
	// put(40, 1);
	// put(50, 1);
	// put(65, 2);
	// put(70, 3);
	// put(85, 3);
	print();
	printf("height: %d\n", height());
	printf("get value %d for key 70\n", get(70));
	return 0;
}