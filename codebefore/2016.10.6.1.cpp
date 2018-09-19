#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct stu{
    int nu,all,a,b,c;
};
bool comp(struct stu A,struct stu B){
    if(A.all!=B.all)
        return A.all>B.all;
    else if(A.a!=B.a)
        return A.a>B.a;
    else if(A.b!=B.b)
        return A.b>B.b;
    else
        return A.c>B.c;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        int i,j,k;
        struct stu num[10005];
        int num1,num2,num3;
        for(i=0;i<n;i++){
            scanf("%d %d %d",&num1,&num2,&num3);
            num[i].all=num1+num2+num3;
            num[i].a=num1;
            num[i].b=num2;
            num[i].c=num3;
            num[i].nu=i;
        }
        sort(num,num+n,comp);
       int m;
       scanf("%d",&m);
       int t;
       for(i=1;i<=m;i++){
            scanf("%d",&t);
            printf("%d\n",num[t-1].nu+1);
       }
    }
    return 0;
}
