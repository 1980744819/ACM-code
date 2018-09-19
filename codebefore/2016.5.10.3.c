#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#define Link 0
#define Thread 1
#define NULL 0
char s[10000];
int a=0;
typedef enum{link,thread} pointertag;
typedef struct bitnode{
    int ltag,rtag;
    char data;
    struct bitnode *lchild,*rchild;
}bitnode,*bitree;
bitree pre;
void creat(bitree *t){
    char ch=s[a++];
    if(ch==' ')
        (*t)=NULL;
    else{
        (*t)=(bitree)malloc(sizeof(bitnode));
        if(!*t)
            exit(0);
        (*t)->data=ch;
        (*t)->ltag=link;
        (*t)->rtag=link;
        creat(&(*t)->lchild);
        creat(&(*t)->rchild);
    }
}

void inth(bitree p){
    if(p){
        inth(p->lchild);
        if(!p->lchild){
            p->ltag=thread;
            p->lchild=pre;
        }
        if(!p->rchild){
            pre->rtag=thread;
            pre->rchild=p;
        }
        pre=p;
        inth(p->rchild);
    }
}
int in(bitree t){
    bitree p;
    p=t->lchild;
    while(p!=t){
        while(p->ltag==link)
            p=p->lchild;
            printf("%c ",p->data);
            while(p->rtag==thread&&p->rchild!=t){
                p=p->rchild;
                printf("%c ",p->data);
            }
            p=p->rchild;
    }
    return 1;
}
int main(){
    gets(s);
    bitree t=NULL;
    creat(&t);
    inth(t);
    //in(t);
    printf("\n");
    return 0;
}

