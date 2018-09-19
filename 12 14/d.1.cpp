#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    int i,j,k;
    int a,b,s;
    int num;
    while(scanf("%d %d %d",&a,&b,&s)){
            if(a<0)
                a=0-a;
            if(b<0)
                b=0-b;
            num=a+b;
        if(s%2==0){
            if(num%2==0&&num<=s)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else{
            if(num%2!=0&&num<=s)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}

