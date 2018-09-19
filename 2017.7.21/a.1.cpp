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

int main(){
	//freopen("test.txt","r",stdin);
	int i,j;
	int len;
	int Max;
	int ans;
	int coun=0;
	while(~scanf("%s",s)){
		Max=0;
		len=strlen(s);
		ans=0;
		for(i=0;i<len;i++){
			if(s[i]>='0'&&s[i]<='9')
				s[i]-='0';
			if(s[i]>='A'&&s[i]<='Z')
				s[i]=s[i]-'A'+10;
			if(Max<s[i])
				Max=s[i];
			ans+=s[i];
			//printf("%d ",s[i]);
		}
		//printf("\n");
		bool flag=false;
		for(j=Max+1;j<=36;j++){
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