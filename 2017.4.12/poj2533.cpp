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
int st[1005];
int binary(int num,int len){
	int low,high;
	low=1;
	high=len;
	int mid;
	while(low<high){
		mid=(low+high)/2;
		if(num>=st[mid]){
			low=mid+1;
		}
		else{
			high=mid;
		}
	}
	return low;
}
int main(){
	int a[1005];
	int n;
	int i,j;
	int top;
	int pos;
	while(~scanf("%d",&n)){
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		st[1]=a[1];
		top=1;
		for(i=2;i<=n;i++){
			//printf("\n");
			if(a[i]>st[top]){
				top++;
				st[top]=a[i];
			}
			else{
				pos=binary(a[i],top);
				st[pos]=a[i];
			}
		}
		printf("%d\n",top);
	}
    return 0;
}
