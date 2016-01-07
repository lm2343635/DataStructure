#include <stdio.h>
#include <stdlib.h>

#define MAX 99999

typedef struct queue_head {
	unsigned count, head;
	int data[MAX];
} *queue;

queue newq() {
	queue q=malloc(sizeof(struct queue_head));
	q->count=q->head=0;
	return q;
}

unsigned sizeq(queue q) {
	return q->count;
}

void enq(queue q, int v) {
	q->data[(q->head+q->count-1)%MAX]=v;
	q->count++;
}

int peekq(queue q) {
	return q->data[q->head];
}

int deq(queue q) {
	int value=peekq(q);
	q->head=(q->head+1)%MAX;
	q->count--;
	return value;
}

void split(queue q, queue subq[]) {
	int i=0;
	subq[0]=newq();
	subq[1]=newq();
	while(sizeq(q)>0) {
		enq(subq[i], deq(q));
		i=(i+1)%2;
	}
}

queue merge(queue q1, queue q2) {
	queue q=newq();
	while(sizeq(q1)>0||sizeq(q2)>0) {
		if(sizeq(q1)==0) {
			enq(q, deq(q2));
		} else if(sizeq(q2)==0) {
			enq(q, deq(q1));
		} else if(peekq(q1)<peekq(q2)) {
			enq(q, deq(q1));
		} else {
			enq(q, deq(q2));
		}
	}
	return q;
}

queue ms(queue q) {
	if(sizeq(q)<=1) {
		return q;
	} else {
		queue subq[2];
		split(q, subq);
		return merge(ms(subq[0]), ms(subq[1]));
	}
}

queue sort(queue q) {
	return ms(q);
}

void show(queue q) {
	int i=0;
	for(i=q->head; i<q->count; i++) {
		printf("%d ", q->data[i%MAX]);
	}
	printf("\n");
}

int main(int argc, char const *argv[]) {
	queue q=newq();
	enq(q, 3);
	enq(q, 2);
	enq(q, 0);
	enq(q, 1);	
	show(q);
	return 0;
}