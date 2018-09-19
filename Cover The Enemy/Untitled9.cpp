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
struct stu{
    int r1,r2;
}node[100005];
bool cmp(struct stu a,struct stu b){
    return a.r1>b.r1;
}
int main(){
    int t;
    int x1,x2,y1,y2;
    int n;
    int i,j,k;
    int a,b;
    int ra,rb;
    int ans;
    int Max;
    while(~scanf("%d",&t)){
        while(t--){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            scanf("%d",&n);
            for(i=0;i<n;i++){
                scanf("%d %d",&a,&b);
                node[i].r1=(a-x1)*(a-x1)+(b-y1)*(b-y1);
                node[i].r2=(a-x2)*(a-x2)+(b-y2)*(b-y2);
            }
            sort(node,node+n,cmp);
            ans=node[0].r1;
            Max=0;
            node[n].r1=0;
            for(i=0;i<n;i++){
                if(Max<node[i].r2)
                    Max=node[i].r2;
                if(ans>Max+node[i+1].r1){
                    ans=Max+node[i+1].r1;
                }
                //printf("%d\n",ans);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

