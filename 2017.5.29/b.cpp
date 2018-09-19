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
int p[100005];
int main(){
	int i,j;
	int num;
	int n;
	scanf("%d",&n);
	int maxnum=0;
	for(i=0;i<n;i++){
		scanf("%d",&num);
		if(num>maxnum)
			maxnum=num;
		for(j=1;j*j<num;j++){
			if(num%j==0){
				p[j]++;
				p[num/j]++;
			}
		}
		if(j*j==num)
			p[j]++;
	}
	int ans=1;
	for(i=2;i<=maxnum;i++){
		ans=max(ans,p[i]);
	}
	printf("%d\n",ans);
    return 0;
}
