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
    int m,n;
    int i,j,k;
    int sum_a,sum_b;
    while(~scanf("%d %d",&m,&n)){
        sum_a=0;
        sum_b=0;
        for(i=0;i<m;i++){
            scanf("%d",&a[i]);
            sum_a+=a[i];
        }
        for(i=0;i<n;i++){
            scanf("%d",&b[i]);
            sum_b+=b[i];
        }
        if(sum_a!=sum_b){
            printf("NO\n");
            continue;
        }
        sort(a,a+m);
        sort(b,b+n);
        int u,v;
        int flag=0;
        for(i=n-1;i>=0;i--){
            u=b[i];
            j=m-1;
            while(u>0){
                u--;
                a[j]--;
                if(a[j]<0){
                    flag=1;
                    break;
                }
                j--;
            }
            if(flag)
                break;
        }
        for(i=0;i<m;i++)
            if(a[i]!=0){
                flag=1;
                break;
        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}

