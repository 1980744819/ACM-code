#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define NULL 0
#define len sizeof(struct stu)

int n;
struct stu{
    int a;
    int b;
    struct stu *next;
};
struct stu *creat(){
    struct stu *p1=NULL;
    struct stu *p2=NULL;
    struct stu *head;
    n=0;
    p1=(struct stu *)malloc(len);
    p2=p1;
    if(p1==NULL){
        return NULL;
    }
    else {
        head=NULL;
        scanf("%d%d",&(p1->a),&(p1->b));
    }
    while(p1->a!=-1&&p1->b!=-1){
            n++;
        if(n==1){
            head=p1;
            p2->next=NULL;
        }
        else{
            p2->next=p1;
        }
        p2=p1;
        p1=(struct stu *)malloc(len);
        scanf("%d%d",&(p1->a),&(p1->b));
    }
    p2->next=NULL;
    free(p1);
    p1=NULL;
    return head;
};
void print(struct stu *head){
    struct stu *p;
    p=head->next;
    while(p!=NULL){
            printf("%d %d ",p->a,p->b);
        p=p->next;
    }
    printf("\n");
}
char cmp(int x,int y){
    if(x>y)
        return '>';
    if(x<y)
        return '<';
    if(x==y)
        return '=';
}
struct stu *add_(struct stu *head1,struct stu *head2){
    struct stu *p1;
    struct stu *p2;
    struct stu *p3;
    struct stu *p4;
    p1=head1->next;
    p2=head2->next;
    if(p1->b>p2->b||p1->b==p2->b){
        p3=head1;
    }
    else
        p3=head2;

    return head1;
};
int main(){
    struct stu *head1;
    struct stu *head2;
    head1=creat();
    //print(head1);
    head2=creat();
    //print(head2);
    head1=add_(head1,head2);
    print(head1);
    return 0;
}
