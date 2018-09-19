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
struct stu{
	int len,sum;
}le[105];
bool cmp(struct stu a,struct stu b){
	return a.sum<b.sum;
}
int main(){
	char st[105];
	int n,k;
	int num1,num2;
	int i,j;
	int l;
	while(~scanf("%d %d",&n,&k)){
		for(i=0;i<105;i++){
			le[i].len=i;
			le[i].sum=0;
		}
		for(i=0;i<n;i++){
			scanf("%s",st);
			//puts(st);
			l=strlen(st);
			le[l].sum++;
		}
		scanf("%s",st);
		//puts(st);
		l=strlen(st);
		num1=0;
		num2=0;
		for(i=0;i<l;i++)
			num1+=le[i].sum;
		num2=num1+le[l].sum;
		printf("%d %d\n",num1/k*5+1+num1,num2/k*5+num2);
	}
    return 0;
}
