#include <stdio.h>

#define N 5

char node[N]={'a', 'b', 'c', 'd', 'e'};

int edge[N][N]= {
	{0,7,4,5,1},
	{0,0,0,6,0},
	{0,0,0,2,3},
	{0,0,0,0,0},
	{0,0,0,0,0}
};

void print_graph(char node[], int edge[N][N]) {
	int i, j;
	for(int i=0; i<N; i++) {
		for(int j=i; j<N; j++) {
			if(edge[i][j]>0) {
				printf("(%c)--%d--(%c)\n", node[i], edge[i][j], node[j]);
			}
		}
	}
}

void prim(int tree[N][N]) {
	int min_i, min_j;
	for(int i=0; i<N; i++) {
		for(int j=i; j<N; j++) {
			if(edge[i][j]>0) {
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	print_graph(node, edge);
	return 0;
}