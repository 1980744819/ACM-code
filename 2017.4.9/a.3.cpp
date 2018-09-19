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
using namespace std;
struct stu{
    int coe;
    int exp;
    struct stu *next;
};
struct stu *create(){
    struct stu *p,*node;
    struct stu *head=NULL;
    int a,b;
    int i=0;
    while(~scanf("%d %d",&a,&b)){
        if(a==-1&&b==-1){
            return head;
        }
        else{
            node=(struct stu *)malloc(sizeof(struct stu));
            if(i==0){
                head=node;
                p=head;
            }
            else{
                p->next=node;
                p=p->next;
            }
            i++;
            p->coe=a;
            p->exp=b;
            p->next=NULL;
        }
    }
    return head;
}
struct stu *add(struct stu *roota,struct stu *rootb){
    struct stu *head=NULL;
    struct stu *pa,*pb;
    struct *node,*p;
    int i=0;
    int a,b,c,d;
    pa=roota;
    pb=rootb;
    i=0;
    while(pa!=NULL&&pb!=NULL){
        b=pa->exp;
        d=pb->exp;
        if(b==d){
            a=pa->coe;
            c=pb->coe;
        }
    }
    return head;
}
void print(struct stu *root){
    struct stu *p=root;
    if(p==NULL)
        printf("0");
    while(p!=NULL){
        printf("%d %d ",p->coe,p->exp);
        p=p->next;
    }
    printf("\n");
}
int main(){
    struct stu *root1=NULL,*root2=NULL,*ans=NULL;
    root1=create();
    print(root1);
    root2=create();
    print(root2);
    return 0;
}

