#include <stdio.h>
#include <stdlib.h>

#define N 8

int Adj[N][N]={
	{0,1,1,0,0,0,0,0},
	{0,0,1,0,0,1,0,0},
	{0,0,0,1,0,0,0,0},
	{0,0,0,0,1,0,1,0},
	{0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0}
};

struct element {
	struct element *next;
	int data;
};

struct queue {
	struct element *head;
	struct element *tail;
};

struct queue *make_queue() {
	struct queue *q;
	q=malloc(sizeof(struct queue));
	q->head=NULL;
	q->tail=NULL;
	return q;
};

int is_empty(struct queue *q) {
	return q->head==NULL&&q->tail==NULL;
}

int dequeue(struct queue *q) {
	struct element *element;
	int data;
	if(is_empty(q))
		return -1;
	element=q->head;
	data=element->data;
	q->head=element->next;
	if(q->head==NULL)
		q->tail=NULL;
	free(element);
	return data;
}

void enqueue(struct queue *q, int data) {
	struct element *p, *element;
	element=(struct element *)malloc(sizeof(struct element));
	element->data=data;
	element->next=NULL;
	if(q->head!=NULL) {
		p=q->head;
		while(p->next!=NULL)
			p=p->next;
		p->next=element;
	} else {
		p=element;
		q->head=p;
	}
	q->tail=p;
}

void destroy_queue(struct queue *q) {
	struct element *p, *t;
	p=q->head;
	while(p!=NULL) {
		free(t);
		t=p;
		p=p->next;
	}
	free(p);
	free(q);
}

void traverse(int start, int goal) {
	struct queue *q;
	int dist[N];
	int prev, node;
	for(node=0; node<N; node++) {
		dist[node]=-1;
	}
	q=make_queue();
	dist[start]=0;
	enqueue(q, start);
	printf("Start from Node %d\n\n", start);
	while(!is_empty(q)) {
		prev=dequeue(q);
		for(node=0; node<N; node++) {
			if(Adj[prev][node]==1) {
				if(dist[node]==-1) { //已经被找过的节点不需要进入队列，因为它在之前的查找中已经出现在一条更短的路径中了。
					dist[node]=dist[prev]+1;
					printf("Visiting Node %d from Node %d, distance %d\n", node, prev, dist[node]);
					if(node==goal) {
						printf("Path found from Node %d to Node %d, distance %d\n", start, goal, dist[node]);
						destroy_queue(q);
						return;
					} else {
						enqueue(q, node);
					}
				}
			}
		}
	}
	printf("No path from Node %d to Node %d\n", start, goal);
	destroy_queue(q);
}

int main(int argc, char const *argv[])
{
	// （1）
	struct queue *q;
	q=make_queue();
	enqueue(q, 10);
	enqueue(q, 5);
	enqueue(q, 5);
	enqueue(q, 20);
	printf("%d, ", dequeue(q));
	printf("%d, ", dequeue(q));
	printf("%d, ", dequeue(q));
	printf("%d, ", dequeue(q));
	destroy_queue(q);
	// （3）
	traverse(1, 0);
	return 0;
}