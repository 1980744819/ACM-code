#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<malloc.h>
#include<cmath>
#include<cstring>
using namespace std;
typedef struct BiTnode{
    int data;
    struct BiTnode *lchild,*rchild;
}BiTnode,*BiTree;
 bool SearchBST(BiTree T,int key,BiTree f,BiTree *p){
    if(!T){
        *p=f;
        return false;
    }
    else if(key==T->data){
        *p=T;
        return true;
    }
    else if(key<T->data){
        return SearchBST(T->lchild,key,T,p);
    }
    else{
        return SearchBST(T->rchild,key,T,p);
    }
 }
 bool DeleteBST(BiTree *T,int key){
    if(!*T){
        return false;
    }
    else{
        if(key==(*T)->data)
            return Delete(T);
        else if(key<(*T)->data){
            return DeleteBST(&(*T)->lchild,key);
        else
            return DeleteBST(&(*T)->rchild,key);
        }
    }
 }
 bool Delete(BiTree *p){
    BiTree q,s;
    if((*p)->rchild==NULL){
        q=*p;
        *p=(*p)->lchild;
        free(q);
    }
    else if((*p)->lchild==NULL){
        q=*p;
        *p=(*p)->rchild;
        free(q);
    }
    else{
        q=(*p);
        s=(*p)->lchild;
        while(s->rchild){
            q=s;
            s=s->rchild;
        }
        (*p)->data=s->data;
        if(q!=*p){
            q->rchild=s->rchild;
        }
        else{
            q->lchild=s->lchild;
        }
        free(s);
    }
    return true;
 }
 bool InsertBST(BiTree *T,int key){
    BiTree p,s;
    if(!(SearchBST(*T,key,NULL,&p))){
        s=(BiTree)malloc(sizeof(BiTnode));
        s->data=data;
        s->lchild=s->rchild=NULL;
        if(!p){
            *T=s;
        }
        else if(key<p->data)
            p->lchild=s;
        else
            p->rchild=s;
        return true;
    }
    else return false;
 }
int main(){
    return 0;
}
