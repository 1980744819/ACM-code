#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#define ll long long
#define read(a) scanf("%d",&a);
using namespace std;
const int maxn=405;	
const int inf=99999999;
int f,d,n;
int c[maxn][maxn];
int dis[maxn];
int pre[maxn];
int main(){
	freopen("test.txt","r",stdin);
	int fi,di;
	int num;
	int ans;
	while(~scanf("%d %d %d",&n,&f,&d)){
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++){
			scanf("%d %d",&fi,&di);
			for(int j=1;j<=fi;j++){//food
				scanf("%d",&num);
				c[num][i+f]=1;
				c[0][num]=1;
			}
			for(int j=1;j<=di;j++){//drink	
				scanf("%d",&num);
				c[f+n+i][num+f+n+n]=1;
				c[num+f+n+n][f+n+n+d+1]=1;
			}
			c[i+f][i+f+n]=1;
		}
		n=n+n+f+d;
		n++;
		ans=0;
		while(1){
			memset(pre,-1,sizeof(pre));
			queue<int>que;
			que.push(0);
			while(!que.empty()){
				int num=que.front();
				que.pop();
				if(num==n)
				 	break;
				for(int i=0;i<=n;i++){
					if(c[num][i]>0&&pre[i]==-1){
						pre[i]=num;
						que.push(i);
					}
				}				
			}
			if(pre[n]==-1)
				break;
			ans+=1;
			int tmp=n;
			while(tmp!=0){
				c[pre[tmp]][tmp]-=1;
				c[tmp][pre[tmp]]+=1;
				tmp=pre[tmp];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}