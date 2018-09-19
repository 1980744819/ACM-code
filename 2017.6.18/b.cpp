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
using namespace std;
int main(){
	int len[105];
	int n,k;
	int i,j;
	int num1,num2;
	char s[105];
	int lenth;
	while(~scanf("%d %d",&n,&k)){
		memset(len,0,sizeof(len));
		for(i=0;i<n;i++){
			scanf("%s",s);
			lenth=strlen(s);
			len[lenth]++;
		}
		scanf("%s",s);
		lenth=strlen(s);
		num1=num2=0;
		for(i=0;i<lenth;i++){
			num1+=len[i];
		}
		num2+=num1+len[lenth];
		int tmp1=num1/k;
		int tmp2=(num2-1)/k;
		printf("%d %d\n",tmp1*5+num1+1,tmp2*5+num2);
	}
    return 0;
}
