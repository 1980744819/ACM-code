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
const int Maxn=8010;
struct stu{
	int l,r,col;
}tree[Maxn*4];
int ans[Maxn];
int color[Maxn];
void build(int l,int r,int node){
	tree[node].l=l;
	tree[node].r=r;
	tree[node].col=-1;
	if(l==r)
		return;
	int mid=(l+r)/2;
	build(l,mid,node*2);
	build(mid+1,r,node*2+1);
}
void push_down(int node){
	tree[node*2].col=tree[node*2+1].col=tree[node].col;
	tree[node].col=-1;
}
void update(int l,int r,int val,int node){
	if(tree[node].col==val)
		return;
	if(l<=tree[node].l&&r>=tree[node].r){
		tree[node].col=val;
		return;
	}
	if(tree[node].col!=-1)
		push_down(node);
	int mid=(tree[node].l+tree[node].r)/2;
	if(r<=mid){
		update(l,r,val,node*2);
	}
	else if(l>=mid+1){
		update(l,r,val,node*2+1);
	}
	else{
		update(l,r,val,node*2);
		update(l,r,val,node*2+1);
	}
	if((tree[node*2].col==tree[node*2+1].col)&&tree[node*2].col!=-1){
		tree[node].col=tree[node*2].col;
	}
}
void coun(int node){
	int i,j;
	if(tree[node].col!=-1){
		for(i=tree[node].l;i<=tree[node].r;i++){
			color[i]=tree[node].col;
		}
		return;
	}
	if(tree[node].l==tree[node].r)
		return;
	coun(node*2);
	coun(node*2+1);
}
void print(){
	int pre;
	int i;
	pre=-1;
	for(i=1;i<=8000;i++){
		if(pre!=color[i]){
			pre=color[i];
			ans[pre]++;
		}
	}
	for(i=0;i<=8000;i++){
		if(ans[i]!=0){
			printf("%d %d\n",i,ans[i]);
		}
	}
	printf("\n");
}
int main(){
	//freopen("test.txt","r",stdin);
	int i,j;
	int n;
	int a,b,c;
	//printf("111\n");
	while(~scanf("%d",&n)){
		build(1,8000,1);
		memset(ans,0,sizeof(ans));
		memset(color,-1,sizeof(color));
		for(i=0;i<n;i++){
			scanf("%d %d %d",&a,&b,&c);
			if(a==b)
				continue;
			update(a+1,b,c,1);
		}
		coun(1);
		print();
	}
	return 0;
}