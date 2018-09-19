
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#define ll long long
const int maxn=1005;
const int inf=999999999;
using namespace std;


int main(){
	freopen("test.txt","r",stdin);
	// freopen("test.out","w",stdout);
	int n,m,s,t;
	int dis[maxn];
	int book[maxn];
	while(~scanf("%d %d %d %d",&n,&m,&s,&t)){
		std::vector<int> vec[maxn];
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		for(int i=1;i<=n;i++){
			dis[i]=inf;
		}
		for(int i=0;i<vec[s].size();i++){
			dis[vec[s][i]]=1;
		}
		dis[s]=0;
		memset(book,0,sizeof(book));
		book[s]=1;
		for(int i=1;i<n;i++){
			int Min=inf;
			int id=0;
			for(int j=1;j<=n;j++){
				if(book[j]==1)
					continue;
				else{
					if(Min>dis[j]){
						id=j;
						Min=dis[j];
					}
				}
			}
			book[id]=1;
			for(int j=0;j<vec[id].size();j++){
				int num=vec[id][j];
				if(dis[num]>dis[id]+1){
					dis[num]=dis[id]+1;
				}
			}
		}

		for(int i=1;i<=n;i++){
			printf("%d ",dis[i]);
		}
		printf("\n");
	}
    return 0;
}
