#include <stdio.h>

#define M 999999
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
	for(i=0; i<N; i++) {
		for(j=i; j<N; j++) {
			if(edge[i][j]>0) {
				printf("(%c)--%d--(%c)\n", node[i], edge[i][j], node[j]);
			}
		}
	}
}

int is_empty(int edge[N][N]) {
	int i, j;
	for(i=0; i<N; i++) {
		for(j=i; j<N; j++) {
			if(edge[i][j]>0) {
				return 0;
			}
		}
	}
	return 1;
}

int has_loop_r(int edge[N][N], int min_i, int min_j) {
	int i, j, start, end;
	start=min_i>min_j? min_j: min_i;
	end=min_i>min_j? min_j: min_j;
	if(edge[start][end]>0)
		return 1;
	for(i=0; i<start; i++) {
		if(edge[i][start]>0) {
			if(has_loop_r(edge, i, end)==1)
				return 1;
		}
	}
	for(j=end; j<N; j++) {
		if(edge[end][j]>0) {
			if(has_loop_r(edge, start, j)==1)
				return 1;
		}
	}
	return 0;
}

int has_loop(int edge[N][N], int min_i, int min_j) {
	int i, j;
	if(edge[min_i][min_j]>0||edge[min_j][min_i])
		return 1;
	for(i=0; i<N; i++) {
		for(j=i; j<N; j++) {
			if(edge[i][min_i]>0) {
				if(has_loop(edge, i, min_j)==1)
					return 1;
			}
			if(edge[i][min_j]>0) {
				if(has_loop(edge, min_i, i)==1)
					return 1;
			}
			if(edge[min_i][j]>0) {
				if(has_loop(edge, j, min_j)==1)
					return 1;
			}
			if(edge[min_j][j]>0) {
				if(has_loop(edge, min_i, j)==1)
					return 1;
			}
		}
	}
	return 0;
}

void prim(int tree[N][N]) {
	int i, j, min_i, min_j, min_edge;
	while(is_empty(edge)!=1) {
		min_edge=M;
		for(i=0; i<N; i++) {
			for(j=i; j<N; j++) {
				if(edge[i][j]>0&&edge[i][j]<min_edge) {
					min_edge=edge[i][j];
					min_i=i;
					min_j=j;
				}
			}
		}
		printf("%d\n", has_loop(tree, min_i, min_j));
		if(has_loop(tree, min_i, min_j)==0) {
			tree[min_i][min_j]=min_edge;
		}
			
		edge[min_i][min_j]=0;
	}
	
}

int main(int argc, char const *argv[]) {
	printf("graph\n");
	print_graph(node, edge);
	int tree[N][N]={0};
	prim(tree);
	printf("tree\n");
	print_graph(node, tree);
	return 0;
}