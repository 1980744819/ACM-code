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
char s[105];
int main(){
	freopen("test.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		int ans=0;
		for(int i=0;s[i]!='\0';i++){
			if(s[i]=='H'){
				ans++;
			}
			else if(s[i]=='O'){
				ans+=16;
			}
			else{
				ans+=12;
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}
