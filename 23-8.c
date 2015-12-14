#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct {
	int length;
	int digits[N];
} BigDecimal;

void intToBigDecimal(int i, BigDecimal *d) {
	d->length=0;
	do {
		d->digits[d->length]=i%10;
		d->length++;
		i/=10;
	} while(i);
}

void shiftLeftBigDecimal(BigDecimal *d) {
	int i;
	for(i=d->length; i>0; i--) {
		d->digits[i]=d->digits[i-1];
	}
	if(d->length>1||d->digits[0]!=0)
		d->length++;
	d->digits[0]=0;
}

void strToBigDecimal(char *str, BigDecimal *d) {
	intToBigDecimal(0, d);
	int count=0;
	do {
		shiftLeftBigDecimal(d);
		count++;
		d->digits[0]=*str-'0';
		str++;
	} while(*str!='\0');
	printf("count: %d\n", count);
}

int compareBigDecimal(BigDecimal *d1, BigDecimal *d2) {
	int i;
	if(d1->length>d2->length)
		return 1;
	if(d2->length>d1->length)
		return -1;
	for(i=d1->length-1; i>=0; i--) {
		if(d1->digits[i]>d2->digits[i])
			return 1;
		if(d2->digits[i]>d1->digits[i])
			return -1;
	}
	return 0;
}

void show(BigDecimal *d) {
	for(int i=d->length-1; i>=0; i--)
		printf("%d", d->digits[i]);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	BigDecimal *d=(BigDecimal *)malloc(sizeof(BigDecimal));
	// intToBigDecimal(123456, d);
	// show(d);
	// shiftLeftBigDecimal(d);
	// show(d);
	// strToBigDecimal("99999999999999999999999999999999999999999999999999", d);
	// show(d);
	BigDecimal *d1=(BigDecimal *)malloc(sizeof(BigDecimal));
	intToBigDecimal(123756, d);
	intToBigDecimal(123156, d1);
	printf("%d\n", compareBigDecimal(d, d1));
	return 0;
}