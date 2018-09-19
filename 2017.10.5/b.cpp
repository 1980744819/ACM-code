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
int c[25][25];
int get(){
	for(int i=0;i<25;i++){
		for(int j=0;j<=i;j++){
			if(j==0||j==i){
				c[i][j]=1;
			}
			else{
				c[i][j]=c[i-1][j-1]+c[i-1][j];
			}
			printf("%d ",c[i][j]);
		}
		printf("\n");	
	}
}
int main(){
	freopen("test.txt","w",stdout);
	
	get();
    return 0;
}
