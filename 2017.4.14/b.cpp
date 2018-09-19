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
	int n;
	int mp[50][50];
	int i,j;
	int tx,ty,nx,ny;
	scanf("%d",&n);
	memset(mp,-1,sizeof(mp));
	mp[1][n/2+1]=1;
	nx=1;
	ny=n/2+1;
	for(i=2;i<=n*n;i++){
		tx=nx;
		ty=ny;
		nx--;
		ny++;
		if(nx<1)
			nx=n;
		if(ny>n)
			ny=1;
		if(mp[nx][ny]!=-1){
			mp[tx+1][ty]=i;
			nx=tx+1;
			ny=ty;
		}
		else{
			mp[nx][ny]=i;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d",mp[i][j]);
			if(j!=n)
				printf(" ");
		}
		printf("\n");
	}
    return 0;
}
