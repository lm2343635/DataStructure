#include <stdio.h>

#define N 1000

void divisor(int n) {
    int i;
    for(i=1; i<=n/2; i++) {
        if(n%i==0)
	    printf("%d\n", i);
    }
}

int is_perfect(int n) {
    int i, sum;
    if(n<=0)
	return 0;
    sum=0;
    for(i=1; i<n; i++) {
	sum+=n%i==0? i: 0;
    }
    if(sum==n)
	return 1;
    else
	return 0;
}

void perfect1000() {
    int i, j, sum[N+1];
    for(i=1; i<=N; i++)
	sum[i]=0;
    for(j=1; j<N/2; j++) {
	for(i=2; i<=N; i++) {
	    if(i*j>N)
		break;
	    sum[i*j]+=j;
	}
    }
    for(i=1; i<=N; i++) {
	if(sum[i]==i)
	    printf("%d\n", i);
    }
}

int main() {
    divisor(6);
    printf("6 is perfect? %d\n", is_perfect(6));
    perfect1000();
    return 0;
}
