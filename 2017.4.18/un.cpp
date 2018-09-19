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
int a[105];
int main(){
	int i,j;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int sum=0;
	for(i=1;i<n;i++){
		if(a[i]==1){
			if(a[i-1]==1){
				a[i]=0;
				sum++;
			}
		}
		else if(a[i]==2){
			if(a[i-1]==2){
				a[i]=0;
				sum++;
			}
		}
		else if(a[i]==3){
			if(a[i-1]==1){
				a[i]=2;
			}
			else if(a[i-1]==2){
				a[i]=1;
			}
		}
		else{
			sum++;
		}
	}
	if(a[0]==0){
		sum++;
	}
	printf("%d\n",sum);
    return 0;
}
