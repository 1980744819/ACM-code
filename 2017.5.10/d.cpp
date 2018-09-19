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
int c[25][25];
int main(){
	int i,j;
	int n;
	for(i=0;i<25;i++){
		for(j=0;j<=i;j++){
			if(j==0||j==i)
				c[i][j]=1;
			else{
				c[i][j]=c[i-1][j-1]+c[i-1][j];
			}
		}
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
    return 0;
}
