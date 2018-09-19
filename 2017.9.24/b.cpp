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
#define ll long long
using namespace std;
const int maxn=10000;
int main(){
	freopen("test.txt","w",stdout);
	int n,m;
	n=5;
	m=5;
	printf("%d\n%d\n",n,m);
	for(int i=0;i<m;i++){
		int r,num,p;
		r=rand()%20;
		printf("%d",r);
		for(int j=1;j<=5;j++){
			printf(" %d %d",j,rand()%20);
		}
		printf(" -1");
		printf("\n");
	}
	printf("5\n");
	for(int i=1;i<=5;i++)
		printf("%d\n",i);
    return 0;
}
