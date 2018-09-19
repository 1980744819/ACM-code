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
int f[30],d[30],F[30],ans[30],t[30],tran[30];
int main(){
    int i,j,k;
    int h,n;
    int Max,id;
    int Max_ans;
    int left_t;
    int sum;
    int cas=0;
    while(~scanf("%d",&n)&&n){
        scanf("%d",&h);
        h*=60;
        for(i=0;i<n;i++)
            scanf("%d",&f[i]);
        for(i=0;i<n;i++)
            scanf("%d",&d[i]);
        t[0]=0;
        for(i=1;i<n;i++){
            scanf("%d",&t[i]);
            t[i]=t[i]*5+t[i-1];
        }
        memset(ans,0,sizeof(ans));
        Max_ans=-1;
        for(i=0;i<n;i++){
            left_t=h-t[i];
            for(j=0;j<=i;j++)
                F[j]=f[j];
            sum=0;
            memset(tran,0,sizeof(tran));
            while(left_t>0){
                Max=0;id=0;
                for(j=0;j<=i;j++){//求最大值
                    if(Max<F[j]){
                        Max=F[j];
                        id=j;
                    }
                }
                if(Max==0)
                    break;
                sum+=Max;
                tran[id]+=5;
                F[id]-=d[id];
                left_t-=5;
            }
            if(left_t>0)
                tran[0]+=left_t;
            if(Max_ans<sum){
                Max_ans=sum;
                for(j=0;j<=i;j++){
                    ans[j]=tran[j];
                    //tran[j]=0;
                }
            }
        }
        if(cas>0)
           printf("\n");
        cas++;
        printf("%d",ans[0]);
        for(i=1;i<n;i++)
            printf(", %d",ans[i]);
        //printf("%d \n",ans[n-1]);
        printf("\n");
        printf("Number of fish expected: %d\n",Max_ans);
        memset(t,0,sizeof(t));
        //printf("\n");
    }
    return 0;
}



