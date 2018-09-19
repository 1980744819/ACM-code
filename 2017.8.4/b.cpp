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
const int maxn=205;
const int inf=99999999;
int c[maxn][maxn];
bool book[maxn];
int pre[maxn];
int main(){
	freopen("test.txt","r",stdin);
	int start,end,weight;
	int n,m;
	int i,j;
	int ans;
	while(~scanf("%d %d",&m,&n)){
		memset(c,0,sizeof(c));
		for(i=0;i<m;i++){
			scanf("%d %d %d",&start,&end,&weight);
			c[start][end]+=weight;
		}
		ans=0;
		while(1){
			memset(book,false,sizeof(book));
			memset(pre,0,sizeof(pre));
			queue<int>que;
			que.push(1);
			book[1]=true;
			int mini=inf;
			while(!que.empty()){
				int num=que.front();
				if(num==n)
					break;
				//printf("%d\n",num);
				for(i=1;i<=n;i++){
					if(book[i]==false&&c[num][i]>0){
						book[i]=true;
						que.push(i);
						pre[i]=num;
						//printf("%d ",i);
						mini=min(mini,c[num][i]);
					}
				}
				//printf("\n");
				que.pop();
			}
			//printf("%d\n",mini);
			if(book[n]==false){
				//printf("!!!!!!");
				break;
			}
			int tmp=n;
			while(pre[tmp]!=0){
				c[pre[tmp]][tmp]-=mini;
				c[tmp][pre[tmp]]+=mini;
				tmp=pre[tmp];
			}
			ans+=mini;
			//printf("%d\n",ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}