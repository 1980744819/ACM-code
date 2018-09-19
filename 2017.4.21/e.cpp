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
int t[100005],c[100005],r[100005],x[100005];
int mx[105][105];
int main(){
	int n,m;
	int i,j;
	int q;
	int tmp;
	scanf("%d %d %d",&m,&n,&q);
	int a,b;
	for(i=1;i<=q;i++){
		scanf("%d",&t[i]);
		if(t[i]==1){
			scanf("%d",&r[i]);
		}
		else if(t[i]==2){
			scanf("%d",&c[i]);
		}
		else{
			scanf("%d %d %d",&r[i],&c[i],&x[i]);
		}
	}
	 i=q;
	while(t[i]!=3){
		i--;
	}
	while(i>=1){
		while(t[i]==3&&i>=1){
			mx[r[i]][c[i]]=x[i];
			i--;
		}
		while(t[i]!=3&&i>=1){
			if(t[i]==1){
				a=r[i];
				tmp=mx[a][n];
				for(j=n-1;j>=1;j--){
					mx[a][j+1]=mx[a][j];
				}
				mx[a][1]=tmp;
			}
			else{
				a=c[i];
				tmp=mx[m][a];
				for(j=m-1;j>=1;j--){
					mx[j+1][a]=mx[j][a];
				}
				mx[1][a]=tmp;
			}
			i--;
		}
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			printf("%d",mx[i][j]);
			if(j!=n)
				printf(" ");
		}
		printf("\n");
	}
    return 0;
}
