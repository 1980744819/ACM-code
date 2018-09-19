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
using namespace std;
const int maxn=105;
const int inf=99999999;
char mp[maxn][maxn];

int main(){
	freopen("test.txt","r",stdin);
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		//printf("%d %d\n",n,m);
		for(int i=1;i<=n;i++){
			scanf("%s",mp[i]);
			//puts(mp[i]);
		}
		int b=0;
		int left=inf,up=inf,down=0,right=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<m;j++){
				if(mp[i][j]=='B'){
					b++;
					if(left>j)
						left=j;
					if(right<j)
						right=j;
					if(up>i)
						up=i;
					if(down<i)
						down=i;
				}
			}
		}
		int len=0;
		//printf("%d\n",b);
		if(len<down-up+1)
			len=down-up+1;
		if(len<right-left+1)
			len=right-left+1;
		//printf("%d %d\n%d %d\n",left,right,up,down);
		//printf("len:%d\n",len);
		if(len>m||len>n)
			printf("-1\n");
		else if(b==0)
			printf("1\n");
		else
			printf("%d\n",len*len-b);
	}
    return 0;
}
