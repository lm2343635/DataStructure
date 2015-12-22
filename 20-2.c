#include <stdio.h>
#include <stdlib.h>

void print_array(int sz, int d[]) {
	int i;
	for(i=0; i<sz; i++)
		printf("%d ", d[i]);
	printf("\n");
}

void is(int sz, int d[]) {
	int i, j, m;
	for(i=1; i<sz; i++) {
		m=d[i];
		for(j=i-1; j>=0&&d[j]>=m; j--)
			d[j+1]=d[j];
		d[j+1]=m;
	}
}

void in(int dt, int *val) {
	int i;
	val[0]++;
	for(i=val[0]; i>1&&dt<val[i/2]; i=i/2) 
		val[i]=val[i/2];
	val[i]=dt;
}

int dl(int *val) {
	int i=1, j, ret=val[1];
	while(i<=val[0]/2) {
		j=i*2;
		if(j+1<val[0]&&val[j+1]<val[j])
			j++;
		if(val[val[0]]<val[j])
			break;
		val[i]=val[j];
		i=j;
	}
	val[i]=val[i+1];
	val[0]--;
	return ret;
}

void hs(int sz, int d[]) {
	int i, *val;
	val=malloc(sizeof(int)*(sz+1));
	val[0]=0;
	for(i=0; i<sz; i++)
		in(d[i], val);
	print_array(sz+1, val);
	for(i=0; i<sz; i++)
		d[i]=dl(val);
}

int main(int argc, char const *argv[]) {
	int d[]={2, 0, 3, 1, 4, 9, 7, 5};
	// is(4, d);
	
	hs(8, d);
	print_array(8, d);
	return 0;
}