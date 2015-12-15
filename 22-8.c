#include <stdio.h>
#include <stdlib.h>

struct list {
	int data;
	struct list *next;
};

struct list *head=NULL;

int sum_list() {
	struct list *p;
	int sum;
	sum=0;
	p=head;
	while(p!=NULL) {
		sum+=p->data;
		p=p->next;
	}
	return sum;
}

void insert_list(int x) {
	struct list *p, *q, *t;
	q=NULL;
	for(p=head; p!=NULL; p=p->next) {
		if(p->data>=x)
			break;
		q=p;
	}
	t=(struct list *)malloc(sizeof(struct list));
	t->data=x;
	if(q==NULL)
		head=t;
	else 
		q->next=t;
	t->next=p;
}

void delete_list(int x) {
	struct list *p, *q;
	q=NULL;
	for(p=head; p!=NULL; p=p->next) {
		if(p->data==x) {
			if(q==NULL) 
				head=NULL;
			else
				q->next=p->next;
			free(p);
		}
		q=p;
	}
}

int main(int argc, char const *argv[]) {
	insert_list(1);
	insert_list(2);
	insert_list(3);
	printf("%d\n", sum_list());
	delete_list(2);
	printf("%d\n", sum_list());
	return 0;
}