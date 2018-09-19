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
	int a[1005],b[1005];
	int l;
	int i,j;
	int n;
	int c[5];
	bool book[1005];
	while(~scanf("%d",&n)){
		memset(book,false,sizeof(book));
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		l=0;
		for(i=0;i<n;i++){
			if(a[i]!=b[i]){
				c[l]=i;
				l++;
			}
			else{
				book[a[i]]=true;
			}
		}
		if(l==1){
			for(i=1;i<=n;i++){
				if(book[i]==false){
					a[c[0]]=i;
				}
			}
		}
		else{
			if(book[a[c[0]]]==false&&book[b[c[1]]]==false){
				a[c[1]]=b[c[1]];
			}
			else{
				a[c[0]]=b[c[0]];
			}
		}
		for(i=0;i<n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
	}
    return 0;
}
