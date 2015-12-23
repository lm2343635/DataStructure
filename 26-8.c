//
//  26-8.c
//  DataStructure
//
//  Created by limeng on 12/10/15.
//  Copyright © 2015 limeng. All rights reserved.
//

#include <stdio.h>

#define SIZE 5

void print_array(int a[], int n) {
    int i;
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void swap(int *a, int *b) {
    int c;
    c=*a;
    *a=*b;
    *b=c;
}

void f2(int data[], int s, int e) {
    int i=s, j=e, p;
    if(i>=j)
        return;
    p=data[s];

    while (1) {
        while (data[i]<p)
            i++;
        while (data[j]>p)
            j--;
        if(i>=j) {
            break;
        }
        swap(&data[i], &data[j]);
        print_array(data, SIZE);
        i++;
        j--;
    }
    f2(data, s, i-1);
    f2(data, j+1, e);
}

void f1(int data[], int size) {
    f2(data, 0, size-1);
}

void f3(int data[], int size) {
    int i,j;
    for(i=0; i<size-1; i++)
        for(j=0; j<size-i-1; j++)
            if(data[j-1]>data[j])
                swap(&data[j-1], &data[j]);
}

int main() {
    int array[SIZE]={0, 1, 3, 1, 4};
    f1(array, SIZE);
    print_array(array, SIZE);
    return 0;
}