#include <stdio.h>

#define N 6
#define M 99999

typedef enum {
	FALSE=0,
	TRUE=1
} Bool;

struct vertices {
	Bool Vertex[N];
	int Vcount;
};

Bool remain(struct vertices *v) {
	if(v->Vcount!=0)
		return TRUE;
	return FALSE;
}

Bool member(int x, struct vertices *v) {
	return v->Vertex[x];
}

void show_d(int d[], int num) {
	int i;
	for(i=0; i<num; i++) {
		if(d[i]==M)
			printf("M ");
		else
			printf("%d ", d[i]);
	}	
	printf("\n");
}

void set_vertices(struct vertices *v, Bool b) {
	int i;
	for(i=0; i<N; i++)
		v->Vertex[i]=b;
	if(b==TRUE)
		v->Vcount=N;
	else
		v->Vcount=0;
}

int select_min(int d[N], struct vertices *v) {
	int i, min=M, min_i;
	for(i=0; i<N; i++) {
		if(member(i, v)&&d[i]<min) {
			min=d[i];
			min_i=i;
		}
	}
	return min_i;
}

void remove_vertex(int i, struct vertices *v) {
	v->Vertex[i]=FALSE;
	v->Vcount--;
}

void add_vertex(int i, struct vertices *v) {
	v->Vertex[i]=TRUE;
	v->Vcount++;
}

void Dijkstra(int p, int w[N][N], int d[N]) {
	int i, u, x, k;
	struct vertices U, V;
	set_vertices(&V, FALSE);
	set_vertices(&U, TRUE);
	for(i=0; i<N; i++)
		d[i]=M;
	d[p]=0;
	while(remain(&U)) {
		u=select_min(d, &U);
		add_vertex(u, &V);
		remove_vertex(u, &U);
		for(x=0; x<N; x++) {
			if(w[u][x]<M&&member(x, &U)) {
				k=d[u]+w[u][x];
				if(d[x]>k)
					d[x]=k;
			}
		}
		printf("while u=%d, array d is ", u);
		show_d(d, N);
	}
}

int main(int argc, char const *argv[])
{
	int w[N][N]= {
		{0,M,M,60,M,5},
		{5,0,6,M,50,M},
		{M,M,0,5,M,M},
		{M,M,M,0,5,M},
		{30,M,20,M,0,M},
		{M,40,M,M,5,0}
	};
	int d[N];
	Dijkstra(1, w, d);
	show_d(d, N);
	return 0;
}