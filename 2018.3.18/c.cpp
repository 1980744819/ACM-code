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
int main(){
	freopen("test.txt","r",stdin);
	// freopen("test.out","w",stdout);
	int n,s;
	int p[maxn];
	while(~scanf("%d %d",&n,&s)){
		for(int i=0;i<n;i++){
			scanf("%d",&p[i]);
		}
		sort(p,p+n);
		for(int i=0;i<n;i++)
			printf("%d ",p[i]);
		printf("\n");
		int sum=0;
		int l=0;
		int r=0;
		sum=p[0];
		while(r<n){
			if(sum<s){
				r++;
				sum+=p[r];
			}
			else{
				if(sum-p[l]>=s){
					l++;
					sum-=p[l];
				}
				else
					break;
			}
		}
		printf("%d %d\n",l,r);
		printf("%d\n",r-l+1);
	}
    return 0;
}
