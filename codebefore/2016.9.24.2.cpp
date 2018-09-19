#include<iostream>
#include<cstdio>
#include<cstring>
#include<malloc.h>
#include<cmath>
using namespace::std;
struct stu{
    int data;
    int val;
}s[1005];
int m;
int n;
typedef struct binode{
    int data;
    int val;
    struct binode *lchild,*rchild;
}binode,*bitree;
void Swap(int low,int high){
    struct stu *p;
    (*p).data=s[low].data;
    (*p).val=s[low].val;
    s[low].data=s[high].data;
    s[low].val=s[high].val;
    s[high].data=(*p).data;
    s[high].val=(*p).val;
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
int searchbt(bitree root,int data,bitree f,bitree &p){
    if((root)==NULL){
        (p)=f;
        return 0;
    }
    else if(data==(root)->data){
        (p)=(root);
        return 1;
    }
    else if(data>(root)->data){
        return searchbt((root)->lchild,data,root,(p));
    }
    else if(data<(root)->data){
        return searchbt((root)->rchild,data,root,(p));
    }
}
int LT(int a,int b){
    if(a<b)
        return 0;
    else
        return 1;
}
int insertbt(bitree &T,int data,int val){
    bitree p,s;
    if(!searchbt(T,data,NULL,p)){
        s=(bitree)malloc(sizeof(binode));
        s->data=data;
        s->val=val;
        s->lchild=NULL;
        s->rchild=NULL;
        if(p==NULL)
            T=s;
        else if(LT(data,p->val))
            p->lchild=s;
        else
            p->rchild=s;
    }
    return 0;
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
                insertbt(root,s[i].data,s[i].val);
            }
            int deep=getdeepth(&root);
            cout<<deep<<endl;
        }
    }
    return 0;
}
