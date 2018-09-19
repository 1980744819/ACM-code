#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#define NULL 0
char s[10000];
int a=0;
typedef struct bitnode{
    char data;
    struct bitnode *lchild,*rchild;
}bitnode,*bitree;
typedef struct {
    bitree *st[10000];
    int f,r;
}qnode, *que;
void creat(bitree *t){
    char ch=s[a++];
    if(ch==' ')
        (*t)=NULL;
    else{
        (*t)=(bitree)malloc(sizeof(bitnode));
        if(!*t)
            exit(0);
        (*t)->data=ch;
        creat(&(*t)->lchild);
        creat(&(*t)->rchild);
    }
}
void pre(bitree t){
    if(t==NULL)
        return;
    printf("%c ",t->data);
    pre(t->lchild);
    pre(t->rchild);
}
void in(bitree t){
    if(t==NULL)
        return;
    in(t->lchild);
    printf("%c ",t->data);
    in(t->rchild);
}
void po(bitree t){
    if(t==NULL)
        return;
     po(t->lchild);
     po(t->rchild);
     printf("%c ",t->data);
}
void cen(bitree t){
    que q=(que)malloc(sizeof(qnode));
    q->f=0;
    q->r=0;
    int i;
    if(t==NULL)
        return;
    printf("%c",t->data);
    bitree p=t;
    q->st[q->r]=t;
    (q->r)++;
    while((q->f)<q->r){
        t=q->st[q->f];
        (q->f)++;
        if(t->lchild!=NULL){
            q->st[q->r]=t->lchild;
            printf("%c",t->lchild->data);
            (q->r)++;
        }
        if(t->rchild!=NULL){
            q->st[q->r]=t->rchild;
            printf("%c",t->rchild->data);
            (q->r)++;
        }
    }
}
int main(){
    gets(s);
    bitree t=NULL;
    creat(&t);
    /*pre(t);
    printf("\n");
    in(t);
    printf("\n");*/
    in(t);
    printf("\n");
    /*po(t);
    printf(" ");
    //cen(t);
    printf("\n");*/
    return 0;
}

