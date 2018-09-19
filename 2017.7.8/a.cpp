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
int ans;
struct stu{
	int a,b,val;
}tree[4000005];
void build(int l,int r,int num){
 	tree[num].a=l;
 	tree[num].b=r;
 	tree[num].val=0;
 	int mid=(l+r)/2;
 	if(l==r)
 		return;
 	build(l,mid,num*2);
 	build(mid+1,r,num*2+1);
}
void update(int num,int pos,int val){
	if(tree[num].a==tree[num].b&&tree[num].a==pos){
		tree[num].val=val;
		return;
	}
	int mid=(tree[num].a+tree[num].b)/2;
	if(pos<=mid)
		update(num*2,pos,val);
	else
		update(num*2+1,pos,val);
	tree[num].val=max(tree[num*2].val,tree[num*2+1].val);
}
void query(int l,int r,int num){
	if(tree[num].a==l&&tree[num].b==r){
		ans=max(tree[num].val,ans);
		return;
	}
	int mid=(tree[num].a+tree[num].b)/2;
	if(r<=mid)
		query(l,r,num*2);
	else if(l>=mid+1)
		query(l,r,num*2+1);
	else{
		query(l,mid,num*2);
		query(mid+1,r,num*2+1);
	}
}
int main(){
	//freopen("test.txt","r",stdin);
	int m,n;
	char ch;
	int val;
	int a,b;
	int i;
	while(~scanf("%d %d",&n,&m)){
		build(1,n,1);
		//printf("1111\n");
		for(i=1;i<=n;i++){
			scanf("%d",&val);
			update(1,i,val);
		}
		//printf("11111\n");
		for(i=1;i<=m;i++){
			getchar();
			scanf("%c %d %d",&ch,&a,&b);
			//printf("%c\n",ch);
			if(ch=='U'){
				update(1,a,b);
			}
			else{
				ans=-9999999;
				query(a,b,1);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}