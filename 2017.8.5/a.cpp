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
const int maxn=305;
const int inf=1<<29;
int c[maxn][maxn];
bool book[maxn];
int pre[maxn];
int main(){
	//freopen("test.txt","r",stdin);
	int n,np,nc,m;
	char c1,c2,c3;
	//int i,j;
	int ans;
	int mini;
	int first,second,third;
	char temp[40];
	int num;
	//while(cin>>n>>np>>nc>>m){
	while(~scanf("%d %d %d %d",&n,&np,&nc,&m)){
		//memset(c,0,sizeof(c));
		n++;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				c[i][j]=0;
			}
		}
		for(int i=0;i<m;i++){
			scanf("%s",temp);sscanf(temp,"(%d,%d)%d",&first,&second,&third);
			first++;second++;
			c[first][second]+=third;
		}
		for(int i=0;i<np;i++){
			scanf("%s",temp);sscanf(temp,"(%d)%d",&first,&second);
			first++;
			c[0][first]+=second;
		}
		for(int i=0;i<nc;i++){
			scanf("%s",temp);sscanf(temp,"(%d)%d",&first,&second);
			first++;
			c[first][n]+=second;
		}
		ans=0;
		while(1){
			for(int i=0;i<=n;i++){
				//book[i]=false;
				pre[i]=-1;
			}
			queue<int>q;
			mini=inf;
			q.push(0);
			book[0]=true;
			while(!q.empty()){
				num=q.front();
				q.pop();
				if(pre[n]!=-1)
					break;
				for(int i=0;i<=n;i++){
					if(pre[i]==-1&&c[num][i]>0){
						//book[i]=true;
						pre[i]=num;
						mini=min(mini,c[num][i]);
						q.push(i);
					}
				}
			}
			if(pre[n]==-1)
				break;
			ans+=mini;
			int tmp=n;
			while(pre[tmp]!=-1){
				c[pre[tmp]][tmp]-=mini;
				c[tmp][pre[tmp]]+=mini;
				tmp=pre[tmp];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}