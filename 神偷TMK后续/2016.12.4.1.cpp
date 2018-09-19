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
    int n,k;
    int i,j;
    int ans;
    while(~scanf("%d %d",&n,&k)){
        if(k==0)
            printf("1\n");
        else{
            ans=n;
            int t=k;
            int coun=1;
            for(i=n-1;i>=1;i--){
                if(coun==t)
                    break;
                ans*=i;
                coun++;
            }
            coun=0;
            for(i=k;i>=1;i--){
                ans/=i;
                coun++;
                if(coun==t)
                    break;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

