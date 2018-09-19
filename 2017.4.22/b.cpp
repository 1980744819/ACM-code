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
int c[10][10];
void init(){
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<=i;j++){
			if(j==0||j==i){
				c[i][j]=1;
			}
			else{
				c[i][j]=c[i-1][j-1]+c[i-1][j];
			}
			//printf("%d ",c[i][j]);
		} 
		//printf("\n");
	}
}
int main(){
	init();
	int t;
	int n;
	int i;
	scanf("%d",&t);
	int ans;
	int tmp;
	int coun=0;
	while(t--){
		scanf("%d",&n);
		printf("0\n");
		ans=1;
		//coun=0;
		for(i=2;i<=n;i++){
			ans*=i;
			tmp=n;
			coun=0;
			while(tmp>=0){
				coun+=c[tmp][i]*ans;
				tmp-=i;
			}
			printf("%d\n",coun);
		}
	}
    return 0;
}
