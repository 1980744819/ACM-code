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
char s[1010];
int main(){
	freopen("test.txt","r",stdin);
	int t,n;
	scanf("%d",&t);
	int ca=0;
	while(t--){
		scanf("%s",s);
		int pos[26];
		for(int i=0;i<26;i++)
			pos[i]=-1;
		int mini=99999999;
		int ans=-1;
		for(int i=0;i<strlen(s);i++){
			int x=s[i]-'a';
			if(pos[x]!=-1){
				//ans=i-pos[x];
				mini=min(mini,i-pos[x]);
				pos[x]=i;
				//break;
			}
			else{
				pos[x]=i;
			}
		}
		printf("Case #%d: ",++ca);
		if(mini==99999999)
			printf("-1\n");
		else
			printf("%d\n",mini);
	}
	return 0;
}