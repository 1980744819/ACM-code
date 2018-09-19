#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<malloc.h>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
int mp_father[1005];
bool book[1005];
int c[1005];
int main(){
    int i,j;
    int n,r;
    int fnode,snode;
    int ans;
    int time;
    int max_j;
    int Max;
    while(~scanf("%d%d",&n,&r)){
        if(n==0&&r==0)
            break;
        for(i=1;i<=n;i++)
            scanf("%d",&c[i]);
        for(i=0;i<n-1;i++){
            scanf("%d %d",&fnode,&snode);
            mp_father[snode]=fnode;
        }
        vector<int>que;
        int Front ,Trail;
        Front=0;
        Trail=0;
        que.push_back(r);
        Trail++;
        ans=c[r];
        time=1;
        book[r]=1;
        max_j=1;
        //printf("%d\n",ans);
        while(time<n){
            Max=0;
            time++;
            for(i=0;i<Trail;i++){
                for(j=1;j<=n;j++){
                    if(mp_father[j]==que[i]&&book[j]==false){
                        if(Max<time*c[j]){
                            Max=time*c[j];
                            max_j=j;
                            //printf("%d\n",Min);
                        }
                    }
                }
            }
            ans+=Max;
            book[max_j]=1;
            que.push_back(max_j);
            Trail++;
        }
        printf("%d\n",ans);
    }
    return 0;
}


