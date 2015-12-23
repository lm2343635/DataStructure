#include <stdio.h>

double factorial(int n) {
	int i;
	double f=1;
	for(i=1; i<=n; i++)
		f*=i;
	return f;
}

double power(double x, int n) {
	double y, z;
	y=1.0;
	z=x;
	while(n>0) {
		if(n%2!=0)
			y*=z;
		z=z*z;
		n/=2;
	}
	return y;
}

double my_sin(double x, int n) {
	int i;
	double sin=0.0;
	for(i=0; i<=n; i++) 
		sin+=(i%2==0? 1: -1)*power(x, 2*i+1)/factorial(2*i+1);	
	return sin;
}

int main(int argc, char const *argv[]) {
	printf("%f\n", my_sin(3.1415926/2, 10));
	return 0;
}