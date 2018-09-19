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
const long long mod=1e9+7;
const int maxn=1e5+5;
int a[maxn],b[maxn];
vector<int>aa;
vector<int>bb;
bool book[maxn];
int main(){
	freopen("test.txt","r",stdin);
	int i,j;
	int n,m;
	int start;
	int coun;
	int cur;
	int kase=0;
	while(~scanf("%d %d",&n,&m)){
		//printf("%d %d\n",n,m);
		kase++;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			//printf("%d ",a[i]);
		}
		for(i=0;i<m;i++){
			scanf("%d",&b[i]);
		}
		memset(book,false,sizeof(book));
		aa.clear();
		bb.clear();
		for(i=0;i<n;i++){
			if(book[i]==true)
				continue;
			book[i]=true;
			cur=i;
			coun=1;
			while(a[cur]!=i){
				cur=a[cur];
				book[cur]=true;
				coun++;
			}
			aa.push_back(coun);
		}
		memset(book,false,sizeof(book));
		for(i=0;i<m;i++){
			if(book[i]==true)
				continue;
			book[i]=true;
			cur=i;
			coun=1;
			while(b[cur]!=i){
				cur=b[cur];
				book[cur]=true;
				coun++;
			}
			bb.push_back(coun);
		}
		long long ans=1;
		long long tmp;
		for(i=0;i<aa.size();i++){
			//printf("%d ",aa[i]);
			tmp=0;
			for(j=0;j<bb.size();j++){
				if(aa[i]%bb[j]==0){
					tmp+=bb[j];
					tmp%=mod;
				}
			}
			ans=(ans*tmp)%mod;
		}
		//printf("\n");
		printf("Case #%d: %lld\n",kase,ans);
	}
	return 0;
}