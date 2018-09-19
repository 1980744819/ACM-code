#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define NULL 0
#define len sizeof(struct stu)
int LEN=0;
struct stu{
    char name[30];
    int cur;
}lis[11];
void print(){
    int i;
    for(i=0;i<11;i++){
        printf("%-8s%2d\n",lis[i].name,lis[i].cur);
    }
    printf("********************\n");
}
void sea(){
    char b[30];
    int i,m;
    m=1;
    scanf("%s",b);
    int k;
    k=lis[1].cur;
    while(strcmp(b,lis[k].name)!=0){
        k=lis[k].cur;
        m++;
    }
    if(strcmp(b,lis[k].name)==0){
        printf("%2d\n",m);
    }
}
void in(){
    LEN++;
    int n,m;
    m=1;
    int k,t;
    scanf("%d",&n);
    if(lis[0].cur<=10){
            scanf("%s",lis[lis[0].cur].name);
        if(LEN==n&&n!=1){
            k=lis[1].cur;
            while(m<n){
                t=k;
                k=lis[k].cur;
                m++;
            }
            int a=lis[lis[0].cur].cur;
            lis[lis[0].cur].cur=lis[t].cur;
            lis[t].cur=lis[0].cur;
            lis[0].cur=a;
        }
        else if(n==1){
                int b=lis[lis[0].cur].cur;
            lis[lis[0].cur].cur=lis[1].cur;
            lis[1].cur=lis[0].cur;
            lis[0].cur=b;
        }
        else{
            k=lis[1].cur;
            t=k;
            while(m<n){
                    t=k;
                k=lis[k].cur;
                m++;
            }
        int c=lis[lis[0].cur].cur;
           lis[lis[0].cur].cur=lis[t].cur;
            lis[t].cur=lis[0].cur;
            lis[0].cur=c;
        }
    }
}
void de(){
    LEN--;
    int m=1,n;
    //char b[20];
    int t,k;
    scanf("%d",&n);
    k=lis[1].cur;
    t=k;
    while(m<n){
            t=k;
        k=lis[k].cur;
        m++;
    }
    if(m==n){
            int c=lis[t].cur;
        lis[t].cur=lis[k].cur;
        lis[k].cur=lis[0].cur;
        lis[0].cur=c;
    }
}
int main(){
    int i,j;
    for(i=0;i<11;i++){
        lis[i].cur=i+1;
    }
    lis[0].cur=2;
    lis[1].cur=0;
    lis[10].cur=0;
    char a[30];
    while(~scanf("%s",a)){
        if(strcmp(a,"show")==0){
            print();
        }
        else if(strcmp(a,"insert")==0){
                in();
                print();
        }
        else if(strcmp(a,"search")==0){
            sea();
        }
        else if(strcmp(a,"delete")==0){
            de();
            print();
        }
        memset(a,'\0',sizeof(a));
    }
    return 0;
}
