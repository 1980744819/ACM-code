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
struct stu *ins(struct stu *head1,struct stu *head2){
    struct stu *head;
    //struct stu *Head;
    head=head1;
    //Head=head1;
    while(head->next!=NULL){
        head=head->next;
    }
    if(head2->next!=NULL){
        head->next=head2;
        head2=head->next;
    }
    return head1;
};
//struct stu *mul()
struct stu *sort(struct stu *head){
        struct stu *endpt;
        struct stu *p;
        struct stu *p1,*p2,*p3;
        p1=(struct stu *)malloc(len);
        p1->next=head;
        head=p1;
        for(endpt=NULL;endpt!=head;endpt=p){
            for(p=p1=head;p1->next->next!=endpt;p1=p1->next){
                if(p1->next->b<p1->next->next->b){
                    p2=p1->next->next;
                    p1->next->next=p2->next;
                    p2->next=p1->next;
                    p1->next=p2;
                    p=p1->next->next;
                }
            }
        }
        p1=head;
        head=head->next;
        free(p1);
        p1=NULL;
        return head;
};
struct stu *add1(struct stu *head){
    struct stu *p1;
    //struct stu *p2;
    if(head==NULL){
        return head;
    }
    p1=head;
    while(p1->next!=NULL){
        if(p1->b==p1->next->b){
            p1->a+=p1->next->a;
            p1->next->a=0;
            //p2=p1->next;
            //p2->next=NULL;
            //p1=p1->next->next;
        }
          p1=p1->next;
    }
    free(p1);
    p1=NULL;
    return head;
};
void print(struct stu *head){
    struct stu *p;
    p=head;
    int flag=1;
    while(p!=NULL){
            if(p->a!=0&&p->next!=NULL){
                    flag=0;
                printf("%d %d",p->a,p->b);
                if(p->next!=NULL)
                    printf(" ");
                }
        p=p->next;
    }
    if(flag) printf("0");
    printf("\n");
    free(p);
    p=NULL;
}
void des(struct stu *head){
    struct stu *p;
    if(head==NULL)
        return 0;
    while(head){
        p=head->next;
        free(head);
        head=p;
    }
    return 1;
}
int main(){
    struct stu *head1;
    struct stu *head2;
    head1=creat();
    head2=creat();
    head1=ins(head1,head2);
    //print(head1);
    head1=sort(head1);
    //print(head1);
    head1=add1(head1);
    print(head1);
    des(head1);
    return 0;
}

