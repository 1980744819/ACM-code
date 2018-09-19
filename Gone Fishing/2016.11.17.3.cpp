#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;
int f[30],d[30],ti[30];
int main(){
    int n,h,m;
    int i,j,k;
    int t;
    int a;
    int Max,Max_i;
    int ans;
    while(~scanf("%d",&n)&&n!=0){
        t=0;
        scanf("%d",&h);
        m=60*h;
        for(i=0;i<n;i++)
            scanf("%d",&f[i]);
        for(i=0;i<n;i++)
            scanf("%d",&d[i]);
        for(i=0;i<n-1;i++){
            scanf("%d",&a);
            t+=a*5;
        }
        m-=t;
        ans=0;
        while(m>0){
            Max=-1;
            Max_i=-1;
            for(i=0;i<n;i++){
                if(f[i]>Max){
                    Max=f[i];
                    Max_i=i;
                }
            }
            if(Max==0){
                break;
            }
            else{
                m-=5;
                ti[Max_i]+=5;
                if(f[Max_i]-d[Max_i]>0){
                    f[Max_i]-=d[Max_i];
                    ans+=d[Max_i];
                }
                else{
                    ans+=f[Max_i];
                    f[Max_i]=0;
                }
            }
        }
        for(i=0;i<n-1;i++){
            printf("%d, ",ti[i]);
        }
        printf("%d \n",ti[n-1]);
        printf("Number of fish expected: %d \n",ans);
        memset(ti,0,sizeof(ti));
    }
    return 0;
}

