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
const int maxn=1e5+7;
int maxj;
struct node{
	int id;
	int num[maxn]={0};
	// bool operator < (const node &b)const{
	// 	for(int j=maxj;j>=0;j--){
	// 		if(b.num[j]!=num[j]){
	// 			return num[j]>b.num[j];
	// 		}
	// 		return 0;
	// 	}
	// }
}a[30];
bool cmp(node u,node v){
	for(int j=maxj;j>=0;j--){
		if(u.num[j]!=v.num[j])
			return u.num[j]>v.num[j];
	}
	return u.num[0]>v.num[0];
}
bool book[30];
long long  weight[maxn];
char s[maxn];
int main(){
	freopen("test.txt","r",stdin);
	int n;
	int kase=0;
	int i,j;
	weight[0]=1;
	for(i=1;i<=100000;i++){
		weight[i]=(weight[i-1]*26)%mod;
		weight[i]%=mod;
		//printf("%d %lld\n",i,weight[i]);
	}
	maxj=0;
	while(~scanf("%d",&n)){
		//printf("%d",n);
		for(i=0;i<26;i++){
			a[i].id=i;
			book[i]=false;
			for(j=0;j<=maxj;j++){
				a[i].num[j]=0;
			}
		}
		maxj=0;
		kase++;
		for(i=0;i<n;i++){
			scanf("%s",s);
			int len=strlen(s);
			// puts(s);
			// printf("strlen %d\n",len);
			int jj;
			// for(j=0,jj=len-1;jj>=0;j++,jj--){
			// 	int t=s[jj]-'a';
			// 	a[t].num[j]++;
			// 	if(jj==0)
			// 		book[t]=1;
			// 	maxj=max(j,maxj);
			// }
			j=0;
			for(jj=len-1;jj>=0;jj--){
				int t=s[jj]-'a';
				a[t].num[j]++;
				//printf("%c %d\n",s[jj],j);
				if(jj==0)
					book[t]=true;
				maxj=max(j,maxj);
				j++;
			}
		}
		for(i=0;i<26;i++){
			for(j=1;j<=maxj;j++){
				a[i].num[j]+=a[i].num[j-1]/26;
				a[i].num[j-1]%=26;
			}
			j=maxj;
			//printf("j:%d\n",j);
			while(a[i].num[j]>=26){
				a[i].num[j+1]+=a[i].num[j]/26;
				a[i].num[j]%=26;
				j++;
				maxj=max(j,maxj);
			}
		}
		//printf("%d\n",maxj);
		sort(a,a+26,cmp);
		// for(i=0;i<26;i++){
		// 	printf("%c:",'a'+a[i].id);
		// 	for(j=0;j<=maxj;j++){
		// 		printf("%d ",a[i].num[j]);
		// 	}
		// 	printf("\n");
		// }
		if(book[a[25].id]){
			for(i=25;i>=0;i--){
				if(book[a[i].id]==false)
					break;
			}
			a[26]=a[i];
			for(;i<=25;i++){
				a[i]=a[i+1];
			}
		}
		long long ans=0;
		for(i=0;i<26;i++){
			for(j=0;j<=maxj;j++){
				if(a[i].num[j]!=0){
					ans+=((25-i)*weight[j]*a[i].num[j])%mod;
					//printf("%c %d %d %d\n",a[i].id+'a',25-i,i,weight[j]);
					ans%=mod;
				}
			}
		}
		printf("Case #%d: %lld\n",kase,ans);
	}
	return 0;
}