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
const int maxn=20;
const int inf=99999999;
int c[maxn][maxn];
int pre[maxn];
bool book[maxn];
using namespace std;
int main(){
	freopen("test.txt","r",stdin);
	int t;
	int ca;
	int i,j;
	int n,m;
	scanf("%d",&t);
	ca=0;
	int ans;
	int mini;
	int start,end,weight;
	while(t--){
		ca++;
		scanf("%d %d",&n,&m);
		memset(c,0,sizeof(c));
		while(m--){
			scanf("%d %d %d",&start,&end,&weight);
			c[start][end]+=weight;
		}
		ans=0;
		while(1){
			memset(pre,0,sizeof(pre));
			memset(book,false,sizeof(book));
			queue<int>que;
			que.push(1);
			book[1]=true;
			mini=inf;
			while(!que.empty()){
				int num=que.front();
				if(num==n)
					break;
				for(i=1;i<=n;i++){
					if(book[i]==false&&c[num][i]>0){
						book[i]=true;
						que.push(i);
						pre[i]=num;
						mini=min(mini,c[num][i]);
					}
				}
				que.pop();
			}
			if(book[n]==false)
				break;
			int tmp=n;
			while(pre[tmp]!=0){
				c[pre[tmp]][tmp]-=mini;
				c[tmp][pre[tmp]]+=mini;
				tmp=pre[tmp];
			}
			ans+=mini;
		}
		printf("Case %d: %d\n",ca,ans);
	}
	return 0;
}