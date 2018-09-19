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
int a[105];
int main(){
	//freopen("test.txt","r",stdin);
	int m,n;
	int i,j;
	int num;
	while(~scanf("%d %d",&m,&n)){
		memset(a,0,sizeof(a));
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				scanf("%d",&num);
				a[j]+=num;
			}
		}
		for(i=0;i<n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
	} 
	return 0;
}