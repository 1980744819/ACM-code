#include<stdio.h>
#include<malloc.h>//ɾ����������ͬ������
struct Linknode{
    int a;
    struct Linknode *next;
    struct Linknode *last;
}*head=NULL,*rear=NULL;
struct Linknode *Create(int a){
    struct Linknode *p;//�ṹ��ָ��p;
    p=(struct Linknode *)malloc(sizeof(struct Linknode));//����ռ�
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
    q->next=NULL;//�ÿգ�ʹq��Ϊһ�������Ľڵ㣬Ȼ��ɾ��
    free(q);
}
int PrintLink(struct Linknode *p){
    for(p=head;p->next!=NULL;p=p->next){
        //printf("%d ",p->a);//�������ͬ������ǰһ������Ȼ��ɾ������һ����
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
