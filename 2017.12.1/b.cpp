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
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		bool flag=true;
		int a;
		int ans=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			if(flag&&a%2==1){
				flag=false;
				ans=i+1;
			}
		}
		if(flag){
			printf("bingyu is niu bi\n");
		}
		else{
			printf("%d\n",ans);
		}
	}
    return 0;
}
