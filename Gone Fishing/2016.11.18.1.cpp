#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
char Map[105][105];
int m,n;
struct stu{
    int x,y;
}node;
int nextx[8]={-1,-1,0,1,1,1,0,-1};
int nexty[8]={0,1,1,1,0,-1,-1,-1};
void bfs(int a,int b){
    queue<struct stu>que;
    node.x=a;
    node.y=b;
    que.push(node);
    struct stu store;
    int i,j;
    while(!que.empty()){
        node=que.front();
        for(i=0;i<8;i++){
            a=node.x+nextx[i];
            b=node.y+nexty[i];
            if(a<0||a>=m||b<0||b>=n)
                continue;
            if(Map[a][b]!='@')
                continue;
            Map[a][b]='.';
            store.x=a;
            store.y=b;
            que.push(store);
        }
        que.pop();
    }
}
int main(){
    int i,j,k;
    int ans;
    while(~scanf("%d %d",&m,&n)){
        if(m==0&&n==0)
            break;
        getchar();
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                scanf("%c",&Map[i][j]);
            }
            getchar();
        }
        ans=0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(Map[i][j]=='@'){
                    ans++;
                    bfs(i,j);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
