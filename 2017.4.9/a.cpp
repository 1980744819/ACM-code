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
  int num;
  struct stu *next;
};
struct stu *create(){
    struct stu *p=NULL;
    p=(struct stu *)malloc(sizeof(struct stu));
    if(p==NULL){
        exit(0);
    }
    p->next=NULL;
    p->num=0;
    return p;
}
struct stu *put(int a,int b,struct stu *root){
    struct stu *p=NULL;
    struct stu *p1;
    //root=p1;
    //p1=p;
    int i,j;
    for(i=0;i<=b;i++){
        if(p==NULL){
            p=create();
            if(i==0){
                root=p;
            }
            else{
                p1->next=p;
            }
            //printf("%d\n",i);
            //p=p->next;
        }
        else{
            //printf("%d\n",i);
            p1=p;
            p=p->next;
        }
    }
    if(p==NULL){
        p=create();//printf("0\n");
        p1->next=p;
    }
    //printf("0\n");
    p->num=a;
    //printf("0\n");
    //root=p1;
    return root;
}
void print(struct stu *root){
    struct stu *p=root;
    int num=0;
    while(p!=NULL){
        printf("%d %d   ",p->num,num);
        p=p->next;
        num++;
    }
    printf("\n");
}
int main(){
    int a,b;
    int i,j;
    int coun;
    struct stu *root1,*root2;
    root1=NULL;
    root2=NULL;
    coun=0;
    while(~scanf("%d %d",&a,&b)){
        if(a==-1&&b==-1){
            coun++;
        }
        if(coun==1){
            //put(a,b,root2);
        }
        else{
            root1=put(a,b,root1);
            if(root1==NULL){
                printf("000000\n");
            }
            print(root1);
        }
    }
    return 0;
}

