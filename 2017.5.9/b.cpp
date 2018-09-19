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
int a[505][505];
int main(){
	int n,k;
	int i,j;
	int num;
	scanf("%d %d",&n,&k);
	num=1;
	for(i=1;i<=n;i++){
		for(j=1;j<k;j++){
			a[i][j]=num;
			num++;
		}
	}
	for(i=1;i<=n;i++){
		for(j=k;j<=n;j++){
			a[i][j]=num;
			num++;
		}
	}
	int sum=0;
	for(i=1;i<=n;i++){
		sum+=a[i][k];
	}
	printf("%d\n",sum);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
    return 0;
}
