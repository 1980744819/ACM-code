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
ll c[105][105];
void mart(){
	for(int i=0;i<25;i++){
		for(int j=0;j<=i;j++){
			if(j==0||i==j){
				c[i][j]=1;
			}
			else{
				c[i][j]=c[i-1][j-1]+c[i-1][j];
			}
			printf("%lld ",c[i][j]);
		}
		printf("\n");
	}
	ll ans=0;
	for(int i=0;i<=20;i++){
		ans+=c[20][i];
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("test.txt","r",stdin);
	mart();
    return 0;
}
