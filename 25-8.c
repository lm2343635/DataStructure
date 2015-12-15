#include <stdio.h>
#include <string.h>

#define NUM_CHAR 128

int skip[NUM_CHAR];

int calc_skip(char *pattern) {
	int i, m;
	m=strlen(pattern);
	for(i=0; i<NUM_CHAR; i++)
		skip[i]=m;
	for(i=0; i<m; i++) 
		skip[pattern[i]]=m-i;
	return m;
}

int faster_match(char *text, char *pattern, int n) {
	int m=calc_skip(pattern)-1;
	int i=m, j;
	while(i<n) {	
		j=m;
		while(j>=0) {
			if(text[i]==pattern[j]) {
				if(j==0)
					return 1;
				i--, j--;
			} else {
				break;
			}
		}
		printf("old i=%d, ", i);
		i+=m-j+skip[text[i]];
		printf("new i=%d\n", i);
	}
	return -1;
}

int simple_match(char *text, char *pattern) {
	int i=0, j=0;
	while(text[i]!='\0') {
		if(text[i]!=pattern[j]) {
			i=i-j+1;
			j=0;
		} else if (pattern[j+1]=='\0') {
			return 1;
		} else  {
			i++;
			j++;
		}
	}
	return -1;
}

int main(int argc, char const *argv[]) {
	// char *text="XYXZde0XZZkWXYZ";
	// char *pattern="WXYZ";
	char *text="With the development of our country, environment problem...";
	char *pattern="tries";
	int n=strlen(text);
	printf("Using simple match: %d\n", simple_match(text, pattern));
	printf("Using faster match: %d\n", faster_match(text, pattern, n));
	return 0;
}