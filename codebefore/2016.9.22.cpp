#include<iostream>
#include<cstdio>
#include<cstring>
#include<malloc.h>
using namespace::std;
typedef struct BiNode{
    int data;
    int val;
    struct BiNode *lchild,*rchild;
}BiNode,*BiTree;
int a1[105],a2[105];
int M,N;
int k=0;
int time=0;
int getmin(){
    int t;
    t=9999999;
    int i;
    for(i=0;i<N;i++){
        if(a2[i]<t){
            k=i;
            t=a2[i];
        }
    }
    a2[k]=9999999;
    //cout<<t<<"  ";
    return t;
}
void CreatBiTree(BiTree *T,int e){
    int i,j;
    if(e==9999999)
        return;
        //cout<<1<<" ";
    if((*T)==NULL){
        (*T)=(BiTree)malloc(sizeof(BiNode));
        if(!*T)
            exit(0);
        (*T)->data=a1[k];
        //cout<<"     "<<a1[k]<<endl;
        (*T)->lchild=NULL;
        (*T)->rchild=NULL;
         int minval;
        minval=getmin();
        if(a1[k]<(*T)->data){
            CreatBiTree(&(*T)->rchild,minval);
        //cout<<"R    ";
        }
        else{
            CreatBiTree(&(*T)->lchild,minval);
        //cout<<"L    ";
        }
    }
}
void pre(BiTree *T){
    if((*T)==NULL){
        cout<<5;
        return;
    }
    BiTree L=(*T);
    cout<<(*T)->data;
    pre(&L->lchild);
    pre(&L->rchild);
}
int MAX(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int getdeepth(BiTree *T){
    BiTree L=*T;
    if(L==NULL)
            return 0;
        else return 1+MAX(getdeepth(&L->lchild),getdeepth(&L->rchild));
}
int main(){
    int i,j;
    while(~scanf("%d",&M)){
        while(M--){
            scanf("%d",&N);
            for(i=0;i<N;i++){
                scanf("%d",&a1[i]);
            }
            for(i=0;i<N;i++){
                scanf("%d",&a2[i]);
            }
            time=0;
            BiTree T=NULL;
            int minval;
            minval=getmin();
            CreatBiTree(&T,minval);
            int deepth=getdeepth(&T);
            cout<<deepth<<endl;
            pre(&T);
        }
    }
    return 0;
}
