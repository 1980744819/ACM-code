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
const int maxn=10000;

int main(){
	freopen("test.txt","r",stdin);
	//freopen("test.out","w",stdout);
	int p;
	int a[10],b[10];
	int ans[10];
	while(~scanf("%d",&p)){
		// printf("%d",p);
		memset(ans,0,sizeof(ans));
		for(int i=0;i<6;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<6;i++){
			scanf("%d",&b[i]);
		}
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
				int tmp=(a[i]+b[j])%p;
				ans[tmp]++;
			}
		}
		int flag=0;
		for(int i=0;i<p-1;i++){
			if(ans[i]!=ans[i+1]){
				flag=1;
				printf("NO\n");
				break;
			}
		}
		if(!flag)
			printf("YES\n");
	}
    return 0;
}
