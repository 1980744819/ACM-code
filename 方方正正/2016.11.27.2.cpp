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
int a[110000],b[110000];
int main(){
    int Max;
    int i,j;
    int m,n;
    int sum_a,sum_b;
    int coun;
    while(~scanf("%d %d",&m,&n)){
        sum_a=0;
        sum_b=0;
        Max=0;
        coun=0;
        for(i=0;i<m;i++){
            scanf("%d",&a[i]);
            if(b[i]>Max)
                Max=b[i];
            sum_a+=a[i];
        }
        for(i=0;i<n;i++){
            scanf("%d",&b[i]);
            if(b[i]>0)
                coun++;
            sum_b+=b[i];
        }
        if(sum_a!=sum_b){
            printf("NO\n");
            continue;
        }
        if(Max!=coun){
            printf("NO\n");
        }
        else
            printf("YES\n");
    }
    return 0;
}
