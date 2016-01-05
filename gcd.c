#include <stdio.h>

int gcd(int a, int b) {
	int r, q, d, t;
	if(a==b)
		return a;
	d=a>b? a: b;
	r=a>b? b: a;
	while(r!=0) {
		q=0;
		while(q*r<=d)
			q++;
		q--;
		printf("%d=", d);
		t=r;
		r=d-q*r;
		d=t;
		printf("%d*%d+%d\n", q, d, r);
	}
	return d;
}

int main(int argc, char const *argv[]) {
	printf("%d\n", gcd(210, 715));
	return 0;
}