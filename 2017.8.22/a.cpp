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
const int maxn=2505;
char a[maxn],b[maxn];
int lena,lenb;
int flag;
int ex;
void dfs(int pa,int pb,int cnt){
	//printf("%d %d\n",pa,pb);
	if(flag)
		return;
	if(pa==lena&&pb==lenb&&cnt==ex){
		flag=1;
		return;
	}
	else if(pa>lena||pb>lenb||cnt>ex){
		return;
	}
	if(b[pb]=='.'){
		dfs(pa+1,pb+1,cnt);
	}
	else if(b[pb]=='*'){
		dfs(pa,pb+1,cnt);
		if(b[pb-1]=='.'){
			if(a[pa-1]==a[pa]){
				dfs(pa+1,pb,cnt+1);
			}
			else
				return;
		}
		else{
			if(a[pa]==b[pb-1]){
				dfs(pa+1,pb,cnt+1);
			}
			else
				return;
		}
	}
	else{
		if(a[pa]==b[pb])
			dfs(pa+1,pb+1,cnt);
		else
			return;
	}
}
int main(){
	freopen("test.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",a);
		scanf("%s",b);
		lena=strlen(a);
		lenb=strlen(b);
		if(b[0]!=a[0]&&b[0]!='.'){
			printf("no\n");
		}
		else{
			int cnt=0;
			for(int i=0;i<lenb;i++){
				if(b[i]!='*')
					cnt++;
			}
			if(cnt>lena){
				printf("no\n");
			}
			else{
				ex=lena-cnt;
				flag=0;
				dfs(1,1,0);
				if(flag)
					printf("yes\n");
				else
					printf("no\n");
			}
			
		}
	}
	return 0;
}