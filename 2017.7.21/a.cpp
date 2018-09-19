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
char s[100005];
long long q_pow(int a,int b){
	//printf("%d %d ",a,b);
	long long ans=1;
	while(b){
		if(b&1)ans*=a;
		b>>=1;
		a*=a;
	}
	//printf("%d\n",ans);
	return ans;
}
int main(){
	//freopen("test.txt","r",stdin);
	int i,j;
	int len;
	int Max;
	long long ans;
	int coun=0;
	while(~scanf("%s",s)){
		Max=0;
		len=strlen(s);
		for(i=0;i<len;i++){
			if(s[i]>='0'&&s[i]<='9')
				s[i]-='0';
			if(s[i]>='A'&&s[i]<='Z')
				s[i]=s[i]-'A'+10;
			if(Max<s[i])
				Max=s[i];
			//printf("%d ",s[i]);
		}
		//printf("\n");
		bool flag=false;
		for(j=Max+1;j<=36;j++){
			//`printf("%d\n",j);
			ans=0;
			coun=0;
			for(i=len-1;i>=0;i--){
				ans+=s[i]*q_pow(j,coun);
				coun++;
			}
			if(ans%(j-1)==0){
				flag=true;
				printf("%d\n",j);
				break;
			}
		}
		if(!flag)
			printf("No Solution\n");
	}
	return 0;
}