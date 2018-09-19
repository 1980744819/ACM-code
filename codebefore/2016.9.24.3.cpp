#include<iostream>
#include<cstdio>
#include<cstring>
#include<malloc.h>
#include<cmath>
using namespace::std;
struct stu{
    int data;
    int val;
}s[105];
int m;
int n;
typedef struct binode{
    int data;
    int val;
    struct binode *lchild,*rchild;
}binode,*bitree;
void Swap(int low,int high){
    int data,val;
    data=s[low].data;
    val=s[low].val;
    s[low].data=s[high].data;
    s[low].val=s[high].val;
    s[high].data=data;
    s[high].val=val;
}
int Partition(int low,int high){
    int pivotkey;
    pivotkey=s[low].val;
    while(low<high){
        while(low<high&&s[high].val>=pivotkey){
            high--;
        }
        Swap(low,high);
        while(low<high&&s[low].val<=pivotkey){
            low++;
        }
        Swap(low,high);
    }
    return low;
}
void Qsort(int low,int high){
    int pivot;
    if(low<high){
        pivot=Partition(low,high);
        Qsort(low,pivot-1);
        Qsort(pivot+1,high);
    }
}
void QuickSort(){
    Qsort(1,n);
}
bool searchbt(bitree T,int data,bitree f,bitree *p){
    if(!T){
        *p=f;
        return false;
    }
    else if(data==T->data){
        return true;
    }
    else if(data<T->data)
        return searchbt(T->rchild,data,T,p);
    else
        return searchbt(T->lchild,data,T,p);
}
bool insertbt(bitree *T,int data,int val){
    bitree p,q;
    if(!searchbt(*T,data,NULL,&p)){
        q=(bitree)malloc(sizeof(binode));
        q->data=data;
        q->val=val;
        q->lchild=q->rchild=NULL;
        if(!p)
            *T=q;
        else if(data<p->data)
            p->rchild=q;
        else
            p->lchild=q;
        return true;
    }
    else
        return false;
}

int Max(int a,int b){
    if(a>b)
        return a;
    return b;
}
int getdeepth(bitree *root){
    bitree p;
    p=(*root);
    if(p==NULL)
        return 0;
    else return 1+Max( getdeepth(&p->lchild), getdeepth(&p->rchild));
}
void pre(bitree *root){
    //bitree p=(*root);
    if((*root)==NULL)
        return ;
    cout<<(*root)->data<<"    "<<(*root)->val<<endl;
    pre(&(*root)->lchild);
    pre(&(*root)->rchild);
}
int main(){
    while(~scanf("%d",&m)){
        while(m--){
            scanf("%d",&n);
            int i,j;
            for(i=1;i<=n;i++){
                scanf("%d",&s[i].data);
            }
            for(i=1;i<=n;i++){
                scanf("%d",&s[i].val);
            }
            QuickSort();
            bitree root;
            root=NULL;
            for(i=1;i<=n;i++){
                insertbt(&root,s[i].data,s[i].val);
                //printf("%d %d\n",s[i].data,s[i].val);
            }
            //creatbt(&root);
            //pre(&root);
            int deep=getdeepth(&root);
            cout<<deep<<endl;
        }
    }
    return 0;
}

