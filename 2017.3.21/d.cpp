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
int main(){
    int n,k,a,b,c;
    int i,j;
    int x,y,z;
    while(~scanf("%d %d %d %d %d",&n,&k,&a,&b,&c)){
        int sum=0;
        int flag=0;
        for(x=0;x<=k;x++){
            for(y=0;x+y<=k;y++){
                sum=a*x+b*y+(k-x-y)*c;
                if(sum==n){
                    flag=1;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

