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
int b[100];
int main(){
	freopen("test.txt","r",stdin);
	char s[15];
	int i,j;
	int m;
	int len;
	int ans;
	int tem;
	int coun;
	while(~scanf("%s %d",s,&m)){
		len=strlen(s);
		ans=0;
		for(i=len-1;i>=0;i--){
			tem=s[i]-'a';
			ans+=pow(tem,len-i);
			//printf("%d\n",ans);
		}
		coun=0;
		while(ans!=0){
			b[coun++]=ans%m;
			ans/=m;
		}
		for(i=coun-1;i>=0;i--){
			printf("%d",b[i]);
		}
		printf("\n");
	}
	return 0;
}