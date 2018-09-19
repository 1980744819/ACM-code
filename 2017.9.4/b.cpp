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
const int maxn=100005;
const int inf=99999999;
int a[maxn];
int n;
bool solve_1(){//xiao dao da
	int sum=0;
	a[0]=0-inf;
	a[n+1]=inf;
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1]){
			if(sum==1){
				return false;
			}
			sum++;
			if(a[i+1]>=a[i-1]||a[i]>=a[i-2])
				continue;
			else
				return false;
		}
	}
	return true;
}
bool solve_2(){//da dao xiao 
	int sum=0;
	a[0]=inf;
	a[n+1]=0-inf;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			if(sum==1){
				return false;
			}
			sum++;
			if(a[i+1]<=a[i-1]||a[i]<=a[i-2])
				continue;
			else
				return false;
		}
	}
	return true;
}
int main(){
	freopen("test.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		// if(n==2){
		// 	printf("YES\n");
		// 	continue;
		// }
		// int  flag=0;
		// for(int i=1;i<n-1;i++){
		// 	if(a[i]>a[i-1]&&a[i]>a[i+1]){
		// 		flag++;
		// 	}
		// 	else if(a[i]<a[i-1]&&a[i]<a[i+1]){
		// 		flag++;
		// 	}
		// 	if(flag>=2)
		// 		break;
		// }
		// if(flag>=2)
		// 	printf("NO\n");
		// else
		// 	printf("YES\n");
		if(solve_1()||solve_2())
			printf("YES\n");
		else
			printf("NO\n");
	}
    return 0;
}
