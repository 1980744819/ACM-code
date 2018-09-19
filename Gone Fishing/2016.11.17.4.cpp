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
int f[30],d[30],use_time[30][30],time[30],m[30],F[30],ans[30];
int main(){
    int Max_ans,Max_ans_i;
    int Max,Max_i;
    int h,n;
    int i,j,k;
    int cas=0;
    while(~scanf("%d",&n)&&n!=0){
        scanf("%d",&h);
        h*=60;
        for(i=0;i<n;i++)
            scanf("%d",&f[i]);
        for(i=0;i<n;i++)
            scanf("%d",&d[i]);
        time[0]=0;
        for(i=1;i<n;i++){
            scanf("%d",&time[i]);
            time[i]=time[i-1]+time[i]*5;
        }
        for(i=0;i<n;i++){
            Max_ans=0;Max_ans_i=0;m[i]=h-time[i];
            for(j=0;j<=i;j++)
                F[j]=f[j];
            while(m[i]>0){
                Max=0;Max_i=0;
                m[i]-=5;
                for(j=0;j<=i;j++){
                    if(Max<F[j]){
                        Max=F[j];Max_i=j;
                    }
                }
                if(Max==0)break;
                ans[i]+=Max;
                use_time[i][Max_i]+=5;
                F[Max_i]-=d[Max_i];
            }
            if(m[i]>0)
                use_time[i][0]+=m[i];
            if(Max_ans<ans[i]){
                Max_ans=ans[i];
                Max_ans_i=i;
            }
        }
        if(cas>0)
            printf("\n");
        cas++;
        for(i=0;i<n-1;i++){
            printf("%d, ",use_time[Max_ans_i][i]);
        }
        printf("%d \n",use_time[Max_ans_i][n-1]);
        printf("Number of fish expected: %d \n",Max_ans);
        memset(use_time,0,sizeof(use_time));
        memset(time,0,sizeof(time));
        memset(m,0,sizeof(m));
        memset(F,0,sizeof(F));
        memset(ans,0,sizeof(ans));
    }
    return 0;
}


