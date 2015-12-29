#include <stdio.h>
#include <string.h>

#define MAX_PATTER_LENGTH 1000
int next[MAX_PATTER_LENGTH];

void print_array(int a[], int n) {
    for(int i=0;i<n;i++) 
       printf("%d ", a[i]);
   printf("\n");
}

void get_next(char *p) {
	int i=0, j, k;
	//初始化条件是next[0]=0
	next[0]=0;
	for(i=0; i<strlen(p)-1; i++) {
		k=next[i];
		//如果k的取值大于i，说明此时k不合法，直接令next[i+1]=1
		if(k>=i) {
			next[i+1]=1;
			continue;
		}
		//首先认为p[i]==p[k-1]，那么next[i+1]=next[i]+1
		next[i+1]=next[i]+1;
		//如果p[i]!=p[k-1]，那么令k=next[k]后再做比较
		//直到k-1为0时停止比较，此时next[i+1]=1=next[0]+1
		while(p[k-1]!=p[i]&&k-1>0) {
			next[i+1]=next[k]+1;
			k=next[k];
		}
	}
}

int kmp(char *str, char *p) {
	int i=0, j=0;
	get_next(p);
	printf("next array is: ");
	print_array(next, strlen(p));
	while(i<strlen(str)&&j<strlen(p)) {
		//如果模式串指针为0或模式串的第j个字符与原字符串的第i个字符一致，i和j指针加1
		if(j==0||str[i]==p[j]) {
			++i;
			++j;
		} 
		//否则模式串的指针j回溯至next[j]-1
		else {
			j=next[j]-1;
		}
	}
	if(j==strlen(p))
		return i-j;
	return -1;
}

int main(int argc, char const *argv[]) {
	char *str="acabaabaabcacaabc";
	char *pattern="abaabcac";
	printf("%s is from %d in %s.\n", pattern, kmp(str, pattern), str);
	return 0;
}