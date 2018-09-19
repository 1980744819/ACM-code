#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<malloc.h>
using namespace std;
struct stu{
    char num[30];
    char name[30];
    int a,b,c;
}stu;
int main(){
    int n;
    while(~scanf("%d",&n)){
        while(n--){
            scanf("%s %s %d %d %d",stu.num,stu.name,&stu.a,&stu.b,&stu.c);
            printf("%s,%s,%d,%d,%d\n",stu.num,stu.name,stu.a,stu.b,stu.c);
        }
    }
}
