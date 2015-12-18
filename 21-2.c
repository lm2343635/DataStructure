#include <stdio.h>
#include <stdlib.h>

void print_array(int a[], int n) {
	int i;
	for(i=0; i<n; i++) 
		printf("%d ", a[i]);
	printf("\n");
}

void shift(int a[], int first, int last) {
	int p;
	for(p=last-1; p>=first; p--)
		a[p+1]=a[p];
}

void insertion_sort(int a[], int n) {
	int w, i, j;
	if(n<=1)
		return;
	for(i=1; i<n; i++) {
		printf("i==%d ", i);
		print_array(a, n);
		w=a[i];
		for(j=0; j<i&&a[j]<=w; j++) 
			continue;
		shift(a, j, i);
		a[j]=w;
	}
	printf("i==%d ", i);
	print_array(a, n);
}

void shift_d(int a[], int first, int last, int d) {

}

void insertion_sort_d(int a[], int n, int d) {
	int w, i, j, k;
	if(n<=d)
		return;
	for(k=0; k<d; k=k+1) {
		for(i=k+d; i<n; i=i+k+d) {
			w=a[i];
			for(j=k; j<n&&a[j]<=w; j=j+d) 
				continue;
			shift(a, j, i, d);
			a[j]=w;
		}
	}
}

int dim[]={1, 2, 4};

void shell_sort(int a[], int n) {
	int l;
	for(l=0; l<n; l++)
		insertion_sort_d(a, n, dim[l]);
}

int main(int argc, char const *argv[]) {
	int array1[]={80, 35, 15, 40, 65};
	insertion_sort(array1, 5);
	return 0;
}