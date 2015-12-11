#include <stdio.h>

#define SIZE 100

unsigned char *input0="{a{()}}b";
unsigned char *input1="{a{(})}b";
unsigned char *input2="][";
unsigned char *input3="[]";

unsigned char stack[SIZE];
int sp;

void init_stack() {
	sp=SIZE;
}

int push(unsigned char data) {
	if(sp==0) 
		return -1;
	sp--;
	stack[sp]=data;
	return 1;
}

int pop(void) {
	unsigned char data;
	if(sp==SIZE)
		return -1;
	data=stack[sp];
	sp++;
	return data;
}

int depth(void) {
	return SIZE-sp;
}

int balance(unsigned char *p) {
	unsigned char c;
	init_stack();
	for( ; (c=*p)!='\0'; p++) {
		switch(c) {
		case '(':
		case '[':
		case '{':
			push(c);
			break;
		case ')':
			if(pop()!='(')
				return 0;
			break;
		case ']':
			if(pop()!='[')
				return 0;
			break;
		case '}':
			if(pop()!='{')
				return 0;
			break;	
		}
	}
	if(depth()==0)
		return 1;
	else 
		return 0;
}

int main(int argc, char const *argv[])
{
	// (1)
	// init_stack();
	// push('(');
	// push('(');
	// push('[');
	// push('{');
	// printf("%c\n", pop());
	// printf("%c\n", pop());
	// printf("%c\n", pop());
	// printf("%c\n", pop());
	// (2)
	
	printf("%d\n", balance(input0));
	printf("%d\n", balance(input1));
	printf("%d\n", balance(input2));
	printf("%d\n", balance(input3));
	return 0;
}