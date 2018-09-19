#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#define NULL 0
int k=0;
typedef struct btnode{
    char data;
    struct btnode *lchild,*rchild;
}btnode,*bitree;
typedef struct{
    btnode *s[10000];
    int f,r;
}qnode,*que;
int getroot(char *a,char x){
    int i;
    for(i=0;a[i]!='\n';i++){
        if(a[i]==x)
            return i;
    }
    return -1;
}
btnode *creat(btnode *t,char *a,char *b,int n){
    if(n==0)
        return NULL;
    int i=getroot(b,*a);
    t=(btnode *)malloc(sizeof(btnode));
    t->data=*a;
    t->lchild=NULL;
    t->rchild=NULL;
    t->lchild=creat(t->lchild,a+1,b,i);
    t->rchild=creat(t->rchild,a+i+1,b+i+1,n-(i+1));
    return t;
}
void pos(btnode *t){
    if(t){
        pos(t->lchild);
        pos(t->rchild);
        printf("%c",t->data);
    }
}
void cen(btnode *t){
    qnode *q=(qnode *)malloc(sizeof(qnode));
    q->f=0;
    q->r=0;
    int i;
    if(t==NULL)
        return;
    printf("%c",t->data);
    btnode *p=t;
    q->s[q->r]=t;
    (q->r)++;
    while((q->f)<(q->r)){
            t=q->s[q->f];
            (q->f)++;
            if(t->lchild!=NULL){
                q->s[q->r]=t->lchild;
                printf("%c",t->lchild->data);
                (q->r)++;
            }
            if(t->rchild!=NULL){
                q->s[q->r]=t->rchild;
                printf("%c",t->rchild->data);
                (q->r)++;
            }
    }
}
int main(){
    char a[10000];
    char b[10000];
    btnode *t=NULL;
    int num;
    scanf("%d",&num);
    while(num--){
        scanf("%s",a);
        scanf("%s",b);
        //puts(a);
        //puts(b);
        int n=strlen(a);
        t=creat(t,a,b,n);
        pos(t);
        /*printf(" ");
        cen(t);*/
        printf("\n");
    }
    return 0;
}

