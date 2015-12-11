//
//  main.c
//  DataStructure
//
//  Created by limeng on 12/10/15.
//  Copyright © 2015 limeng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

struct node *make_node(int value, struct node *left, struct node *right) {
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->data=value;
    p->left=left;
    p->right=right;
    return p;
}

void make_sample_tree(void) {
    struct node *n2, *n3;
    n3=make_node(3, NULL, NULL);
    n2=make_node(2, NULL, n3);
    root=make_node(1, n2, NULL);
}

int sumup_list1(struct node *p, int value) {
    while (p!=NULL) {
        p->data+=value;
        value=p->data;
        p=p->right;
    }
    return value;
}

int sumup_list2(struct node *p) {
    if(p==NULL)
        return 0;
    p->data+=sumup_list2(p->right);
    return p->data;
}

int sumup_tree1(struct node *p, int value) {
    if(p==NULL)
        return value;
    p->data+=sumup_tree1(p->left, value);
    return sumup_tree1(p->right, p->data);
}

int sumup_tree2(struct node *p) {
    if (p==NULL) {
        return 0;
    }
    //printf("old data: %d\n", p->data);
    p->data+=sumup_tree2(p->left);
    //printf("new data: %d\n", p->data);
    return p->data+sumup_tree2(p->right);
}

void pre_order_traverse(struct node *p) {
    if(p==NULL) {
        return;
    }
    printf("%d ", p->data);
    pre_order_traverse(p->left);
    pre_order_traverse(p->right);
}

void in_order_traverse(struct node *p) {
    if(p==NULL) {
        return;
    }
    in_order_traverse(p->left);
    printf("%d ", p->data);
    in_order_traverse(p->right);
}

void post_order_traverse(struct node *p) {
    if(p==NULL) {
        return;
    }
    post_order_traverse(p->left);
    post_order_traverse(p->right);
    printf("%d ", p->data);
}


//int main(int argc, const char * argv[]) {
////    (1)
////    make_sample_tree();
////    （2）
////    struct node *n2, *n3;
////    n3=make_node(3, NULL, NULL);
////    n2=make_node(2, NULL, n3);
////    root=make_node(1, NULL, n2);
////    sumup_list1(root, 0);
////    (3)
////    struct node *n2, *n3;
////    n3=make_node(6, NULL, NULL);
////    n2=make_node(4, NULL, n3);
////    root=make_node(2, NULL, n2);
////    sumup_list2(root);
////    (5)
//    struct node *n2, *n3, *n4, *n5, *n6, *n7;
//    n7=make_node(7, NULL, NULL);
//    n6=make_node(6, NULL, n7);
//    n5=make_node(5, NULL, n6);
//    n3=make_node(3, n5, NULL);
//    n4=make_node(4, NULL, NULL);
//    n2=make_node(2, n4, n3);
//    root=make_node(1, n2, NULL);
//    //sumup_tree1(root, 0);
//    printf("In Order:\n");
//    sumup_tree2(root);
//    in_order_traverse(root);
//    printf("\nPre Order\n");
//    pre_order_traverse(root);
//    printf("\nPost Order\n");
//    post_order_traverse(root);
//    return 0;
//}
