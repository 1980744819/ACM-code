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
int main(){
	freopen("test.txt","r",stdin);
	int t;
	int i,j;
	int n;
	int acount,bcount;
	int num;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		acount=0;//odd
		bcount=0;
		while(n--){
			scanf("%d",&num);
			if(num%2){
				acount++;
			}
			else
				bcount++;
		}
		printf("2 ");
		if(acount>=bcount)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}