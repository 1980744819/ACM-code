#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<malloc.h>
using namespace std;
struct stu{
    int coe;//系数
    int exp;//指数
    struct stu *next;
};
struct stu *create(){
    int a,b;
    struct stu *head=NULL,*p1,*p2;
    int i,j;
    i=0;

    while(~scanf("%d %d",&a,&b)){
        //scanf("%d %d",&a,&b);
        if(a==-1&&b==-1){
            //free(p2);
            //p2=NULL;
            return head;
        }
        p1=(struct stu *)malloc(sizeof(struct stu));
        if(i==0){
            head=p1;
            p2=head;
            p2->coe=a;
            p2->exp=b;
            p2->next=NULL;
        }
        else{
            p2->next=p1;
            p2=p2->next;
            p2->coe=a;
            p2->exp=b;
            p2->next=NULL;
        }
        i++;
    }
    return head;
}
void print(struct stu *root){
    struct stu *p=root;
    int cou;
    cou=0;
    while(p!=NULL){
        if(p->coe!=0){
            printf("%d %d ",p->coe,p->exp);
            cou++;
        }
        p=p->next;
    }
    if(cou!=0)
        printf("\n");
    else
        printf("0\n");
    free(p);
    p=NULL;
    return;
}
struct stu *coun(struct stu *roota,struct stu *rootb){
    struct stu *head;
    struct stu *p1,*p2;
    struct stu *pa,*pb;
    int coea,coeb;
    int expa,expb;
    int i=0;
    pa=roota;
    pb=rootb;
    while(pa!=NULL&&pb!=NULL){
        p1=(struct stu *)malloc(sizeof(struct stu));
        if(i==0){
            head=p1;
            p2=head;
        }
        else{
            p2->next=p1;
            p2=p2->next;
        }
        i++;
        expa=pa->exp;
        expb=pb->exp;
        if(expa==expb){
            //("ab\n");
            coea=pa->coe;
            coeb=pb->coe;
            p2->coe=coea+coeb;
            p2->exp=expa;
            p2->next=NULL;
            pa=pa->next;
            pb=pb->next;
        }
        else if(expa>expb){
            //printf("a\n");
            coea=pa->coe;
            p2->coe=coea;
            p2->exp=expa;
            p2->next=NULL;
            pa=pa->next;
        }
        else{
            //printf("b\n");
            coeb=pb->coe;
            p2->coe=coeb;
            p2->exp=expb;
            p2->next=NULL;
            pb=pb->next;
        }
    }
    while(pa!=NULL){
        //printf("a\n");
        coea=pa->coe;
        expa=pa->exp;
        p1=(struct stu *)malloc(sizeof(struct stu));
        if(i==0){
            head=p1;
            p2=head;
        }
        else{
            p2->next=p1;
            p2=p2->next;
        }
        i++;
        p2->next=NULL;
        p2->coe=coea;
        p2->exp=expa;
        pa=pa->next;
    }
    while(pb!=NULL){
        //printf("b\n");
        coeb=pb->coe;
        expb=pb->exp;
        p1=(struct stu *)malloc(sizeof(struct stu));
        if(i==0){
            head=p1;
            p2=head;
        }
        else{
            p2->next=p1;
            p2=p2->next;
        }
        i++;
        p2->next=NULL;
        p2->coe=coeb;
        p2->exp=expb;
        pb=pb->next;
    }
    return head;
}
void destroy(struct stu *root){
    struct stu *p;
    while(root){
        p=root->next;
        free(root);
        root=p;
    }
}
int main(){
    freopen("C:/Users/资霄/Desktop/test7.in.svn-base","r",stdin);
    struct stu *root1=NULL;
    struct stu *root2=NULL;
    struct stu *ans=NULL;
    root1=create();
    //print(root1);
    root2=create();
    //print(root2);
    ans=coun(root1,root2);
    print(ans);
    destroy(root1);
    destroy(root2);
    destroy(ans);
    return 0;
}

