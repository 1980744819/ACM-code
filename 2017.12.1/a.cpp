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
bool book[maxn];
int main(){
	freopen("test.txt","r",stdin);
	//freopen("test.out","w",stdout);
	book[1]=false;
	book[2]=true;
	book[3]=false;
	for(int i=4;i<maxn;i++){
		for(int j=1;j*j<=j;j++){
			if(i%j==0){
				if(book[i-j]||book[i-i/j]){
					book[i]=true;
					break;
				}
			}
		}
	}
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int a;
		int flag=true;
		int ans=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			if(book[a]==false&&flag){
				flag=false;
				ans=i+1;
			}
		}
		if(flag){
			printf("bingyu is niu bi\n");
		}
		else{
			printf("%d\n",ans);
		}
	}
    return 0;
}
