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
using namespace std;
int F[100005];
int a[100005],b[100005];
bool book[100005];
int main(){
	//freopen("test.txt","r",stdin);
	int i,j;
	int n,m;
	int ans;
	int kase=0;
	while(~scanf("%d %d",&n,&m)){
		kase++;
		memset(book,false,n);
		memset(F,-1,n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<m;i++)
			scanf("%d",&b[i]);
		for(i=0;i<n;i++)
			F[i]=a[i];
		int start;
		ans=1;
		for(i=0;i<n;i++){
			start=i;
			j=i;
			if(book[i]==false){
				book[i]=true;
				while(F[j]!=start){
					j=F[j];
					if(!book[j])
						book[j]=true;
					else
						break;
				}
				ans*=m%1000000007;
				ans%=1000000007;
			}
		}
		printf("Case #%d: %d\n",kase,ans);
	}
	return 0;
}