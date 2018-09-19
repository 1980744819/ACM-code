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
struct stu{
	int id;
	long double k;
}node[100005];
bool cmp(stu a,stu b){
	return a.k<b.k;
}
int main(){
	int i,j;
	int n;
	long double x,y;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>x>>y;
		node[i].id=i;
		node[i].k=atan2(x,y);
	}
	sort(node+1,node+1+n,cmp);
	node[0]=node[n];
	long double ve,MIN=999999;
	int ans1,ans2;
	for(i=0;i<n;i++){
		ve=node[i+1].k-node[i].k;
		if(ve<0)
			ve+=acos(-1.0)*2;
		if(ve<MIN){
			MIN=ve;
			ans1=node[i].id;
			ans2=node[i+1].id;
		}
	}
	printf("%d %d\n",ans1,ans2);
    return 0;
}
