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
const int inf=1<<29;
int c[maxn][maxn];
int pre[maxn];
int n,np,nc,m;
int mini;
int ans;
int num;
// bool findpath(){
// 	for(int i=0;i<=n;i++){
// 		pre[i]=-1;
// 	}
// 	queue<int>que;
// 	que.push(0);
// 	mini=inf;
// 	while(!que.empty()){
// 		num=que.front();
// 		que.pop();
// 		if(num==n)
// 			return true;
// 		for(int i=1;i<=n;i++){
// 			if(pre[i]==-1&&c[num][i]){
// 				pre[i]=num;
// 				mini=min(mini,c[num][i]);
// 				que.push(i);
// 				if(i==n){
// 					return true;
// 				}
// 			}
// 		}
// 	}
// 	if(pre[n]==-1)
// 		return false;
// 	return true;
// }
// void updata(){
// 	int tmp=n;
// 	while(pre[tmp]!=-1){
// 		c[pre[tmp]][tmp]-=mini;
// 		c[tmp][pre[tmp]]+=mini;
// 		tmp=pre[tmp];
// 	}
// 	ans+=mini;
// 	//retutn 0;
//  }
vector<int>mp[maxn];
int main(){
	freopen("test.txt","r",stdin);
	int first,second,third;
	char temp[30];
	while(~scanf("%d %d %d %d",&n,&np,&nc,&m)){
		//memset(c,0,sizeof(c));
		n++;
		for(int i=0;i<=n;i++){
			mp[i].clear();
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				c[i][j]=0;
			}
		}
		for(int i=0;i<m;i++){
			scanf("%s",temp);sscanf(temp,"(%d,%d)%d",&first,&second,&third);
			first++;second++;
			mp[first].push_back(second);
			mp[second].push_back(first);
			c[first][second]+=third;
		}
		for(int i=0;i<np;i++){
			scanf("%s",temp);sscanf(temp,"(%d)%d",&first,&second);
			first++;
			mp[0].push_back(first);
			mp[first].push_back(0);
			c[0][first]+=second;
		}
		for(int i=0;i<nc;i++){
			scanf("%s",temp);sscanf(temp,"(%d)%d",&first,&second);
			first++;
			mp[first].push_back(n);
			mp[n].push_back(first);
			c[first][n]+=second;
		}
		ans=0;
		for(int i=0;i<=n;i++){
			printf("%d : ",i);
			for(int j=0;j<mp[i].size();j++){
				printf("%d ",mp[i][j]);
			}
			printf("\n");
		}
		// while(1){
		// 	for(int i=0;i<=n;i++){
		// 		pre[i]=-1;
		// 	}
		// 	queue<int>que;
		// 	que.push(0);
		// 	mini=inf;
		// 	while(!que.empty()){
		// 		num=que.front();
		// 		que.pop();
		// 		if(num==n)
		// 			break;
		// 		for(int i=0;i<mp[num].size();i++){
		// 			int t=mp[num][i];
		// 			if(pre[t]==-1&&c[num][t]){
		// 				pre[t]=num;
		// 				que.push(t);
		// 				mini=min(mini,c[num][t]);
		// 				if(t==n)
		// 					break;
		// 			}
		// 		}
		// 		if(pre[n]!=-1)
		// 			break;
		// 	}
		// 	if(pre[n]==-1)
		// 		break;
		// 	int tmp=n;
		// 	while(pre[tmp]!=-1){
		// 		c[pre[tmp]][tmp]-=mini;
		// 		c[tmp][pre[tmp]]+=mini;
		// 		tmp=pre[tmp];
		// 	}
		// 	ans+=mini;
		// }
		// // while(findpath()){
		// // 	updata();
		// // }
		// printf("%d\n",ans);
	}
	return 0;
}