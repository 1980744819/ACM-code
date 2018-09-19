#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define NULL 0
#define len sizeof(struct stu)

char s[10];
struct stu{
    char name[31];
    struct stu *next;
};
struct stu *ins(struct stu *head,int num,struct stu *head1){
    struct stu *p1;
    if(head==NULL){
        head=head1;
        head1->next=NULL;
        return head;
    }
    int n;
    n=1;
    p1=head;
    if(head!=NULL&&num==1){
        head1->next=p1;
        head=head1;
        return head;
    }
    while(p1->next!=NULL&&n!=num-1){
        p1=p1->next;
        n++;
    }
    if(n==num-1){
        head1->next=p1->next;
        p1->next=head1;
    }
    return head;
};
void print(struct stu *head){
    struct stu *p;
    int i;
    if(head==NULL){
        printf("\n");
    }
    else{
        p=head;
        while(p!=NULL){
            for(i=0;i<strlen(p->name);i++){
                printf("%c",p->name[i]);
            }
            p=p->next;
            if(p!=NULL)
            printf(" ");
        }
        printf("\n");
    }
}
void se(struct stu *head){
    struct stu *p;
    char b[31];
    scanf("%s",b);
    int n=1;
    p=head;
    while(p!=NULL){
        if(strcmp(p->name,b)==0){
            printf("%d\n",n);
            break;
        }
            p=p->next;
            n++;
    }
}
struct stu *del(struct stu *head){
    struct stu *p1;
    struct stu *p2;
    char b[31];
    scanf("%s",b);
    if(head==NULL){
        return head;
    }
    p1=head;
    while(p1->next!=NULL&&strcmp(p1->name,b)!=0){
        p2=p1;
        p1=p1->next;
    }
    if(strcmp(p1->name,b)==0){
        if(p1==head){
            head=p1->next;
        }
        else{
            p2->next=p1->next;
        }
        free(p1);
        p1==NULL;
    }
    return head;
};
int main(){
    struct stu *head;
    struct stu *head1;
    head=NULL;
    int num;
    char b[20];
    while(~scanf("%s",s)){
        if(strcmp(s,"insert")==0){
            head1=(struct stu *)malloc(len);
            scanf("%d %s",&num,&head1->name);
            head=ins(head,num,head1);
            //print(head);
        }
        else if(strcmp(s,"show")==0){
            print(head);
        }
        else if(strcmp(s,"search")==0){
            se(head);
        }
        else if(strcmp(s,"delete")==0){
            head=del(head);
        }
    }
    return 0;
}
