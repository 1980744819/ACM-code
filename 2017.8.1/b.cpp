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
using namespace std;
int a[100];
int main(){
	//freopen("test.txt","r",stdin);
	int t;
	int n;
	int i,j,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		// for(i=1;i<=n;i++){
		// 	scanf("%d",&a[i]);
		// }
		int cnt=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				for(k=1;k<=n;k++){
					int ans1=i^j;
					int ans2=j^k;
					if(ans1<ans2)
						printf("%d %d %d %d %d %d %d\n",++cnt,i,j,k,ans1,ans2,i^jn);
				}
			}
		}
	}
	return 0;
}