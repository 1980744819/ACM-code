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
struct stu{
	int l,r;
	int first,last;
	int sum;
	int lazy;
}tree[200005];
int m,n;
void build(int l,int r,int node){
	tree[node].l=l;
	tree[node].r=r;
	tree[node].first=l;
	tree[node].last=r;
	tree[node].sum=l-r+1;
	tree[node].lazy=0;
	if(l==r)
		return;
	int mid=(l+r)/2;
	build(l,mid,node*2);
	build(mid+1,r,node*2+1);
}
void push_up(int node){
	if(tree[node].l==tree[node].r)
		return;
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
	if(tree[node*2].first!=-1)
		tree[node].first=tree[node*2].first;
	else
		tree[node].first=tree[node*2+1].first;
	if(tree[node*2+1].last!=-1)
		tree[node].last=tree[node*2+1].last;
	else
		tree[node].last=tree[node*2].last;
}
void push_down(int node){
	if(tree[node].l==tree[node].r)
		return;
	if(tree[node].lazy==1){
		tree[node*2].first=tree[node*2].l;
		tree[node*2].last=tree[node*2].r;
		tree[node*2].sum=tree[node*2].r-tree[node].l+1;
		tree[node*2].lazy=1;
		tree[node*2+1].first=tree[node*2+1].l;
		tree[node*2+1].last=tree[node*2+1].r;
		tree[node*2+1].sum=tree[node*2+1].r-tree[node*2+1].l+1;
		tree[node*2+1].lazy=1;
	}
	if(tree[node].lazy==-1){
		tree[node*2].first=-1;
		tree[node*2].last=-1;
		tree[node*2].sum=0;
		tree[node*2].lazy=-1;
		tree[node*2+1].first=-1;
		tree[node*2+1].last=-1;
		tree[node*2+1].sum=0;
		tree[node*2+1].lazy=-1;
	}
}
int sum(int node,int l,int r){
	if(tree[node].l==l&&tree[node].r==r){
		return tree[node].sum;
	}
	push_down(node);
	int mid=(tree[node].l+tree[node].r)/2;
	if(r<=mid){
		return sum(node*2,l,r);
	}
	else if(l>mid){
		return sum(node*2+1,l,r);
	}
	else return sum(node*2,l,mid)+sum(node*2+1,mid+1,r);
}
int b_search(int pos,int f){
	if(sum(1,pos,n)==0)
		return -1;
	if(sum(1,pos,n)<f)
		return n;
	int l=pos,r=n;
	int ans=pos;
	while(l<=r){
		int mid=(l+r)/2;
		if(sum(1,pos,mid)>=f){
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	return ans;
}
int query1(int node,int l,int r){
	if(tree[node].l==l&&tree[node].r==r){
		return tree[node].first;
	}
	push_down(node);
	int mid=(tree[node].l+tree[node].r)/2;
	int ans1,ans2;
	if(r<=mid){
		return query1(node*2,l,r);
	}
	else if(l>=mid+1){
		return query1(node*2+1,l,r);
	}
	else{
		ans1=query1(node*2,l,mid);
		if(ans1!=-1)
			return ans1;
		else
			return query1(node*2+1,mid+1,r);
	}
}
int query2(int node,int l,int r){
	if(tree[node].l==l&&tree[node].r==r)
		return tree[node].last;
	push_down(node);
	int mid=(tree[node].l+tree[node].r)/2;
	int ans1,ans2;
	if(r<=mid){
		return query2(node*2,l,r);
	}
	else if(l>=mid+1){
		return query2(node*2+1,l,r);
	}
	else{
		ans1=query2(node*2+1,mid+1,r);
		if(ans1!=-1)
			return ans1;
		else
			return query2(node*2,l,mid);
	}
}
void update(int node,int l,int r,int type){
	if(tree[node].l==l&&tree[node].r==r){
		if(type==0){
			if(tree[node].sum==0)
				return;
			tree[node].sum=0;
			tree[node].first=-1;
			tree[node].last=-1;
			tree[node].lazy=-1;
			return;
		}
		else if(type==1){
			if(tree[node].sum==tree[node].r-tree[node].l+1)
				return;
			tree[node].sum=tree[node].r-tree[node].l+1;
			tree[node].first=tree[node].l;
			tree[node].last=tree[node].r;
			tree[node].lazy=1;
			return;
		}
	}
	push_down(node);
	int mid=(tree[node].l+tree[node].r)/2;
	if(r<=mid){
		update(node*2,l,r,type);
	}
	else if(l>mid){
		update(node*2+1,l,r,type);
	}
	else{
		update(node*2,l,mid,type);
		update(node*2+1,mid+1,r,type);
	}
	push_up(node);
}
int main(){
	freopen("test.txt","r",stdin);
	int i,j;
	int T;
	int op,a,b;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		build(1,n,1);
		while(m--){
			scanf("%d %d %d",&op,&a,&b);
			if(op==1){
				a++;
				int t=b_search(a,b);
				printf("t:%d\n",t);
				if(t==-1){
					printf("Can not put any one.\n");
                    continue;
				}
				printf("%d %d\n",query1(1,a,t)-1,query2(1,a,t)-1);
				update(1,a,t,0);
			}
			else{
				a++;
				b++;
				printf("%d\n",b-a+1-sum(1,a,b));
				update(1,a,b,1);
			}
		}
		printf("\n");
	}
	return 0;
}