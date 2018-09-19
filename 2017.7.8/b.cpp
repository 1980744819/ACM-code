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
int col[400005];
struct stu{
	int l,r,sum;
}tree[400005];
void build(int l,int r,int num){
	tree[num].l=l;
	tree[num].r=r;
	tree[num].sum=(r-l+1);
	if(l==r)
		return;
	int mid=(l+r)/2;
	build(l,mid,num*2);
	build(mid+1,r,num*2+1);
}
void push_down(int node){
	if(col[node]){
		col[node*2]=col[node*2+1]=col[node];
		tree[node*2].sum=col[node]*(tree[node*2].r-tree[node*2].l+1);
		tree[node*2+1].sum=col[node]*(tree[node*2+1].r-tree[node*2+1].l+1);
		col[node]=0;
	}
}
void update(int l,int r,int node,int val){
	if(l<=tree[node].l&&r>=tree[node].r){
		col[node]=val;
		tree[node].sum=val*(tree[node].r-tree[node].l+1);
		return;
	}
	push_down(node);
	int mid=(tree[node].l+tree[node].r)/2;
	if(l<=mid){
		update(l,r,node*2,val);
	}
	if(r>=mid+1){
		update(l,r,node*2+1,val);
	}
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
}
int main(){
	//freopen("test.txt","r",stdin);
	int kase;
	int t;
	int n;
	int i,j;
	int op;
	int a,b,val;
	scanf("%d",&t);
	kase=1;
	while(t--){
		memset(col,0,sizeof(col));
		scanf("%d",&n);
		build(1,n,1);
		scanf("%d",&op);
		//printf("%d\n",op);
		for(i=1;i<=op;i++){
			scanf("%d %d %d",&a,&b,&val);
			update(a,b,1,val);
		}
		// for(i=0;i<n;i++)
		// 	printf("%d ",&tree[i].sum);
		printf("Case %d: The total value of the hook is %d.\n",kase++,tree[1].sum);
	}
	return 0;
}