#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#define ll long long
#define read(a) scanf("%d",&a);
using namespace std;
int a[105];
int fab(int a,int b){
	if(a-b<0)
		return b-a;
	return a-b;
}
int main(){
	freopen("test.txt","r",stdin);
	int n,d;
	while(~scanf("%d %d",&n,&d)){
		int num=1;
		bool flag=true;
		for(int i=1;i<=n;i+=d+1){
			a[num]=i;
			if(num>1&&fab(a[num],a[num-1])<=d){
				flag=false;
				break;
			}
			num++;
		}
		if(flag==false){
			printf("-1\n");
			continue;
		}
		for(int i=a[2]-1;i>a[1];i--){
			for(int j=i;j<=n;j+=d+1){
				a[num]=j;
				if(num>1&&fab(a[num],a[num-1])<=d){
					flag=false;
					break;
				}
				num++;
			}
			if(!flag)
				break;
		}
		if(!flag){
			printf("-1\n");
			continue;
		}
		for(int i=2;i<num;i++){
			if(fab(a[i],a[i-1])<=d){
				flag=false;
				break;
			}
		}
		if(!flag){
			printf("-1\n");
			continue;
		}
		printf("%d",a[1]);
		for(int i=2;i<num;i++){
			printf(" %d",a[i]);
		}
		printf("\n");
	}
	return 0;
}