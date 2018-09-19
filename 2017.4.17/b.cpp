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
	int a[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,9,25,49,4};
	int i;
	int ans=0;
	char s[10];
	for(i=0;i<19;i++){
		printf("%d\n",a[i]);
		fflush(stdout);
		scanf("%s",s);
		if(s[0]=='y')
			ans++;
	}
	if(ans<=1)
		printf("prime\n");
	else
		printf("composite\n");
    return 0;
}
