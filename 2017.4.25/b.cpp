#include<stdio.h>
#include<malloc.h>//删除链表中相同的数字
struct Linknode{
    int a;
    struct Linknode *next;
    struct Linknode *last;
}*head=NULL,*rear=NULL;
struct Linknode *Create(int a){
    struct Linknode *p;//结构体指针p;
    p=(struct Linknode *)malloc(sizeof(struct Linknode));//分配空间
    p->a=a;
    p->next=NULL;
    return p;
}
void Insert(struct Linknode *p){
    if(head==NULL){
        head=p;
        rear=p;
    }
    else{
        rear->next=p;
        rear=p;
    }
}
void Input(int a){
    struct Linknode *p;
    p=Create(a);
    Insert(p);
}
void Del(struct Linknode *p){
    struct Linknode *q;
    q=p->next;
    p->next=q->next;
    q->next=NULL;//置空，使q成为一个单独的节点，然后删除
    free(q);
}
int PrintLink(struct Linknode *p){
    for(p=head;p->next!=NULL;p=p->next){
        //printf("%d ",p->a);//先输出相同的数的前一个数，然后删除掉后一个数
        if(p->a==p->next->a){
            Del(p);
        }
    }
    for(p=head;p!=NULL;p=p->next){
        printf("%d ",p->a);
    }
}
int main(){
    int a;
    while(~scanf("%d",&a)){
        Input(a);
    }
    PrintLink(head);
    printf("\n");
    return 0;
}
