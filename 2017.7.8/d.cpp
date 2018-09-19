#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
using namespace std;
bool has[10005];
int li[10005],ri[10005],col[10005<<4],x[10005<<3];
int m,ans;
void push_down(int node){
	col[node*2]=col[node*2+1]=col[node];
	col[node]=-1;
}
void update(int LL,int RR,int l,int r,int c,int node){
	if(LL<=l&&RR>=r){
		col[node]=c;
		return;
	}
	if(col[node]!=-1)
		push_down(node);
	int mid=(l+r)/2;
	if(LL<=mid)
		update(LL,RR,l,mid,c,node*2);
	if(RR>=mid+1)
		update(LL,RR,mid+1,r,c,node*2+1);
}
int b_search(int LL,int RR,int c){
	int mid;
	while(LL<=RR){
		mid=(LL+RR)/2;
		if(x[mid]==c)
			return mid;
		else if(x[mid]>c)
			RR=mid-1;
		else LL=mid+1;
	}
	return -1;
}
void query(int l,int r,int node){
	if(l==r){
		if(!has[col[node]]){
			ans++;
			has[col[node]]=true;
		}
		return;
	}
	if(col[node]!=-1)
		push_down(node);
	int mid=(l+r)/2;
	query(l,mid,node*2);
	query(mid+1,r,node*2+1);
}
int main(){
	freopen("test.txt","r",stdin);
	int i,j;
	int t;
	int n;
	scanf("%d",&t);
	while(t--){
		memset(col,-1,sizeof(col));
		memset(has,false,sizeof(has));
		int cnt=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d %d",&li[i],&ri[i]);
			x[++cnt]=li[i];
			x[++cnt]=ri[i];
		}
		sort(x+1,x+cnt+1);
		m=1;
		for(i=2;i<=cnt;i++){
			if(x[i]!=x[i-1])
				x[++m]=x[i];
		}
		for(i=m;i>1;i--){
			if(x[i]-x[i-1]>1)
				x[++m]=x[i]-1;
		}
		sort(x+1,x+m+1);
		for(i=1;i<=n;i++){
			int L=b_search(1,m,li[i]);
			int R=b_search(1,m,ri[i]);
			update(L,R,1,m,i,1);
		}
		ans=0;
		query(1,m,1);
		printf("%d\n",ans);
	}
	return 0;
}