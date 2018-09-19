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
int main(){
	freopen("test.txt","r",stdin);
	int t;
	int n,k;
	scanf("%d",&t);
	int ca=1;
	while(t--){
		scanf("%d %d",&n,&k);
		ll left=(1<<k)-n;
		//printf("%d\n",n);
		//printf("%d\n",left);
		printf("Case #%d:\n",ca++);
		for(int i=1;i<k;i++){
			if(left&(1<<i)){
				//left-=1<<i;
				printf("%d -\n",1<<(i-1));
			}
			else{
				printf("%d +\n",1<<(i-1));
			}
		}
		if(left&1)
			printf("%d +\n",(1<<(k-1)));
		else
			printf("%d +\n",(1<<(k-1))+1);
	}
	return 0;
}