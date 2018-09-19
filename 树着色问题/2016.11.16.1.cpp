#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
int n,r;
struct stu{
    int ti;//包含的子集数量
    int ci;
    int ans;
    int father;
    bool flag;
}tree[1005];
int find_father(int son){
    if(tree[tree[son].father].flag&&son!=tree[son].father){
        tree[son].father=find_father(tree[son].father);
    }
    return tree[son].father;
}
int main(){
    int i,j,k;
    int a,b;
    double Max;
    int Max_num;
    int f;
    while(~scanf("%d%d",&n,&r)){
        if(n==0&&r==0)
            break;
        for(i=1;i<=n;i++){
            scanf("%d",&tree[i].ci);
            tree[i].flag=0;
            tree[i].ans=tree[i].ci;
            tree[i].ti=1;
        }
        for(i=1;i<=n-1;i++){
            scanf("%d%d",&a,&b);
            tree[b].father=a;
        }
        tree[r].father=r;
        for(i=1;i<n;i++){
            Max=0;
            for(j=1;j<=n;j++){
                if(tree[j].flag==0&&tree[j].ci*1.0/tree[j].ti>Max&&j!=r){
                    Max=tree[j].ci*1.0/tree[j].ti;
                    Max_num=j;
                }
            }
            f=find_father(Max_num);
            tree[Max_num].flag=1;
            tree[f].ans+=tree[Max_num].ans+tree[Max_num].ci*tree[f].ti;
            tree[f].ti+=tree[Max_num].ti;
            tree[f].ci+=tree[Max_num].ci;
        }
        printf("%d\n\n",tree[r].ans);
    }
    return 0;
}
