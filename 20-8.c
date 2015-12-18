#include <stdio.h>
#include <stdlib.h>

struct list {
	char *elem;
	struct list *next;
};

void print(struct list *p) {
	if(p==NULL)
		printf("[ ]\n");  //empty list
	else {
		printf("[ %s", p->elem);
		for(p=p->next; p!=NULL; p=p->next)
			printf(", %s", p->elem);
		printf(" ]\n");
	}
}

int length(struct list *p) {
	int n=0;
	while(p!=NULL) {
		n++;
		p=p->next;
	}
	return n;
}

int length_r(struct list *p) {
	if(p==NULL)
		return 0;
	else
		return 1+length_r(p);
}

struct list *f(struct list *p, struct list *q) {
	struct list *pt=p;
	if(p==NULL)
		return q;
	while(pt->next!=NULL)
		pt=pt->next;
	pt->next=q;
	return p;
}

struct list *cons(char *s, struct list *p) {
	struct list *t;
	t=malloc(sizeof(struct list));
	t->elem=s;
	t->next=p;
	return t;
}

struct list *safe_f(struct list *p, struct list *q) {
	struct list *pt=q;
	if(p==NULL) {
		if(q==NULL)
			return NULL;
		else
			return cons(pt->elem , safe_f(pt, pt->next));
	} else {
		return cons()
	}
}

int main(int argc, char const *argv[]) {
	struct list *p1, *p2;
	p1=cons("blue", cons("yellow", cons("red", NULL)));
	p2=cons("black", cons("white", NULL));
	print(f(p1, p2));
	return 0;
}