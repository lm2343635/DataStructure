#include <stdio.h>

#define SIZE 5

void print_array(int a[], int n) {
    int i;
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void sort(int data[], int size) {
	int i, j, t;
	for(i=0; i<size; i++) {
		for(j=i+1; j<size; j++) {
			if(data[i]>data[j]) {
				t=data[i];
				data[i]=data[j];
				data[j]=t;
			}
		}
	}
}


int b[SIZE];
void sortsub(int a[], int l, int r) {
	int i, j, k, m;
	if(l<r) {
		m=(l+r)/2;
		sortsub(a, l, m);
		sortsub(a, m+1, r);
		for(i=l; i<=m; i++)
			b[i]=a[i];
		for(j=m+1; j<=r; j++)
			b[r-j+m+1]=a[j];
		i=l;
		j=r;
		for(k=l; k<=r; k++) {
			if(b[i]<b[j])
				a[k]=b[i++];
			else
				a[k]=b[j--];
		}
	}
}

void sort1(int data[], int size) {
	sortsub(data, 0, size-1);
}

int main(int argc, char const *argv[]) {
	int array[SIZE]={0, 1, 3, 1, 5};
	sort1(array, SIZE);
	print_array(array, SIZE);
	return 0;
}