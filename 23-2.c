#include <stdio.h>

void swap(int *x, int *y) {
	int t=*x;
	*x=*y;
	*y=t;
}

void shift_up(int b[], int n) {
	if(n==0)
		return;
	if(b[(n-1)/2]<b[n]||b[(n-1)/2]==b[n])
		return;
	swap(&b[n], &b[(n-1)/2]);
	shift_up(b, (n-1)/2);
}

void shift_down(int b[], int i, int size) {
	int left=2*i+1, right=2*i+2;
	int smallest=i;
	if(right<size&&b[smallest]>b[right])
		smallest=right;
	if(left<size&&b[smallest]>b[left])
		smallest=left;
	if(smallest!=i) {
		swap(&b[i], &b[smallest]);
		shift_down(b, smallest, size);
	}
}

void show(int b[], int n) {
	for(int i=0; i<n; i++) 
		printf("%d ", b[i]);
	printf("\n");
}

void sort2(int a[], int n) {
	int i;
	printf("create heap: \n");
	for(i=0; i<n; i++) {
		shift_up(a, i);
		show(a, n);
	}
	printf("sort: \n");
	for(i=0; i<n; i++) {
		swap(&a[0], &a[n-1-i]);
		show(a, 10);
		shift_down(a, 0, n-1-i);
	}
}

int main(int argc, char const *argv[])
{
	int b[10]={6, 10, 5, 8, 7, 9, 7, 3, 1, 5};
	sort2(b, 10);
	printf("result: \n");
	show(b, 10);
	return 0;
}