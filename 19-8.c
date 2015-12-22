#include <stdio.h>
#include <stdlib.h>

struct element {
	struct element *link;
	int data;
};

struct queuehead {
	struct element *first;
	struct element *last;
};

struct queuehead *init_queue() {
	struct queuehead *qh=malloc(sizeof(struct queuehead));
	qh->first=NULL;
	qh->last=NULL;
	return qh;
}

void print_queue(struct queuehead *qh) {
	struct element *e;
	if(qh->first==NULL) {
		printf(" \n");
		return;
	}
	for(e=qh->first; e!=NULL; e=e->link)
		printf("%d ", e->data);
	printf("\n");
}

void enqueue(struct queuehead *qh, int data) {
	struct element *e;
	e=(struct element *)malloc(sizeof(struct element));
	e->link=NULL;
	e->data=data;
	if(qh->first==NULL) {
		qh->first=e;
		qh->last=e;
	} else {
		e->link=qh->first;
		qh->first=e;
	}
}

int dequeue(struct queuehead *qh) {
	int data;
	struct element *e, *del;
	if(qh->last==NULL)
		return -1;
	e=qh->first;
	del=qh->last;
	data=del->data;
	if(e==del) {
		qh->first=NULL;
		qh->last=NULL;
		free(del);
		return data;
	}
	while(e->link!=qh->last)
		e=e->link;
	e->link=NULL;
	qh->last=e;
	free(del);
	return data;
}

#define M 10
struct queuehead pokects[M];

void radix_sort(struct queuehead *input, struct queuehead *output, int n) {
	int data, div, i;
	for(i=0, div=1; i<n; i++)
		div*=M;
	while((data=dequeue(input))>=0) {
		i=(data/div)%M;
		enqueue(&pokects[i], data);
	}
	for(i=0; i<M; i++) {
		while((data=dequeue(&pokects[i]))>=0)
			enqueue(output, data);
	}
}

void input_array(struct queuehead *qh, int a[], int n) {
	int i;
	for(i=0; i<n; i++)
		enqueue(qh, a[i]);
}

int main(int argc, char const *argv[]) {
	struct queuehead *input, *output0, *output1;
	int data[8]={52, 97, 74, 0, 37, 14, 57, 95};
	input=init_queue();
	output0=init_queue();
	output1=init_queue();
	input_array(input, data, 8);
	radix_sort(input, output0, 0);
	print_queue(output0);
	radix_sort(output0, output1, 1);
	print_queue(output1);
	return 0;
}