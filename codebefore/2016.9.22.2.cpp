#include<iostream>
#include<cstdio>
#include<cstring>
#include<malloc.h>
#include<cmath>
using namespace::std;
struct stu{
    int data,val;
    int book;
}a[105];
int M,N;
typedef struct BiNode{
    int data;
    int val;
    struct BiNode *lchild,*rchild;
}BiNode,*BiTree;
int main(){
    int i,j;
    while(~scanf("%d",&M)){
        while(M--){
            scanf("%d",&N);
            for(i=0;i<N;i++){
                scanf("%d",&a[i].data);
            }
            for(i=0;i<N;i++){
                scanf("%d",&a[i].val);
                a[i].book=0;
            }

        }
    }
    return 0;
}

