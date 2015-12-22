#include <stdio.h>
#include <stdlib.h>

struct element {
	struct element *link;
	int data;
};

struct element *sp;

void push (int data) {
	struct element *e;
	e=malloc(sizeof(struct element));
	e->link=sp;
	e->data=data;
	sp=e;
}

int pop() {
	struct element *e;
	int data;
	if(sp==NULL)
		return -999999;
	e=sp;
	data=e->data;
	sp=e->link;
	free(e);
	return data;
}

void sub() {
	int arg1, arg2, res;
	arg2=pop();
	arg1=pop();
	res=arg1-arg2;
	push(res);
}

void mul() {
	int arg1, arg2, res;
	arg2=pop();
	arg1=pop();
	res=arg1*arg2;
	push(res);
}

void print() {
	int data;
	data=pop();
	printf("%d\n", data);
}

void swap() {
	int arg1, arg2;
	arg2=pop();
	arg1=pop();
	push(arg2);
	push(arg1);
}

void negate() {
	push(-1);
	swap();
	mul();
}

int main(int argc, char const *argv[]) {
	push(10);
	push(20);
	push(30);
	mul();
	sub();
	print();

	push(30);
	negate();
	print();
	return 0;
}