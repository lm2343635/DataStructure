//
//  27-2.c
//  DataStructure
//
//  Created by limeng on 12/10/15.
//  Copyright © 2015 limeng. All rights reserved.
//

#include <stdio.h>

#define N 5

char a[N][N];
int sorted[N], indegree[N], nodestack[N], stackp=0;

void count_indegree() {
    int tail, head;
    for(head=0; head<N; head++) {
        indegree[head]=0;
        for(tail=0; tail<N; tail++) {
            if(a[head][tail]==1) {
                indegree[head]++;
            }
        }
    }
}

void remove_node(int node) {
    int head;
    for(head=0; head<N; head++) {
        if(a[node][head]==1) {
            indegree[head]--;
            if(indegree[head]==0) {
                nodestack[stackp]=node;
                stackp++;
            }
        }
    }
}

int sort(int sorted[]) {
    int count=0, node;
    count_indegree();
    for(node=0; node<N; node++) {
        if(indegree[node]==0) {
            nodestack[stackp]=node;
            stackp++;
        }
    }
    while (stackp>0) {
        stackp--;
        node=nodestack[stackp];
        sorted[count]=node;
        count++;
        remove_node(node);
    }
    return count;
}

//int main(int argc, const char * argv[]) {
//    char b[N][N]={
//        {0, 0, 0, 1, 0},
//        {1, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0},
//        {1, 0, 1, 0, 0}
//    };
//    for(int i=0;i<N;i++) {
//        for(int j=0;j<N;j++) {
//            a[i][j]=b[i][j];
//        }
//    }
//    printf("%d\n", sort(sorted));
//    for(int i=0;i<N;i++) {
//        printf("%d ", sorted[i]);
//    }
//
//}