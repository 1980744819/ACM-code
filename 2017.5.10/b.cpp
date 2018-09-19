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
using namespace std;
struct node{
	int l,r,id;
}a[300005];
bool cmp(struct node u,struct node v){
	return u.l<v.l;
}
int main(){
	int i,j;
	int len;
	int n,k;
	scanf("%d %d",&n,&k);
	priority_queue<int,vector<int>,greater<int> >que;
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i].l,&a[i].r);
		a[i].id=i+1;
	}
	sort(a,a+n,cmp);
	int tmp=0;
	int ans=0;
	len=0;
	for(i=0;i<n;i++){
		que.push(a[i].r);
		if(que.size()>k){
			que.pop();
		}
		len=que.top()-a[i].l+1;
		if(que.size()==k&&ans<len){
			ans=len;
			tmp=a[i].l;
		}
	}
	printf("%d\n",ans);
	if(ans==0){
		for(i=1;i<=k;i++){
			printf("%d ",i);
		}
		printf("\n");
	}
	else{
		for(i=0;i<n&&k;i++){
			if(tmp>=a[i].l&&a[i].r-tmp+1>=ans){
				printf("%d ",a[i].id);
				k--;
			}
		}
		printf("\n");
	}
    return 0;
}
