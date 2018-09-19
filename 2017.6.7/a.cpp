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
	int n,k;
	int a[205],b[205];
	int c[205];
	int i,j;
	int p;
	while(~scanf("%d %d",&n,&k)){
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			b[i]=a[i];
			if(a[i]==0)
				p=i;
		}
		for(i=0;i<k;i++)
			scanf("%d",&c[i]);
		if(k==1){
			a[p]=c[0];
			//sort(b,b+n);
			int flag=0;
			for(i=1;i<n;i++){
				if(a[i]<a[i-1]){
					flag=1;
					printf("Yes\n");
					break;
				}
			}
			if(flag==0)
				printf("No\n");
		}
		else{
			printf("Yes\n");
		}
	}
    return 0;
}
