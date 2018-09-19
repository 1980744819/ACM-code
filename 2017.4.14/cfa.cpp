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
int a[25];
int main(){
	int n;
	int k;
	scanf("%d %d",&n,&k);
	int i,j;
	int coun;
	coun=1;
	bool flag=false;
	for(i=2;i<=n;i++){
		if(n%i==0){
			printf("%d\n",i);
			while(n%i==0&&coun<k){
				a[coun]=i;
				n/=i;
				coun++;
			}
		}
	}
	if(coun<k||n==1){
		printf("-1\n");
	}
	else{
		for(i=1;i<k;i++){
			printf("%d ",a[i]);
		}
		printf("%d\n",n);
	}
    return 0;
}
