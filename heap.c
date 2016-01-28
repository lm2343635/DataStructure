#include <stdio.h>

#define N 7

int a[N]={3,5,4,4,9,5,1};

void print_array(int a[], int n) {
    for(int i=0; i<n; i++) 
       printf("%d ", a[i]);
   printf("\n");
}

void downheap(int k, int r) {
	int j, v;
	v=a[k];
	while(1) {
		j=2*k+1;
		if(j>r) 
			break;
		if(j!=r&&a[j+1]>a[j])
			j++;
		if(v>=a[j])
			break;
		a[k]=a[j];
		k=j;
	}
	a[k]=v;
}

int main(int argc, char const *argv[]) {
	int i, j, t;
	for(i=N-1; i>=0; i--) {
		downheap(i, N-1);
	}
	for(i=N-1; i>=0; i--) {
		downheap(0, i);
		t=a[0];
		for(j=0; j<i; j++)
			a[j]=a[j+1];
		a[i]=t;
	}
	print_array(a, N);
	return 0;
}