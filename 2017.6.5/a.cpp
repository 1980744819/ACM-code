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
	int fi,se;
}node[100005];
bool cmp(struct stu a,struct stu b){
	return a.se>b.se;
}
int main(){
	int i,j;
	int n,k;
	int sum;
	int num;
	int p;
	int tmp;
	int ans;
	while(~scanf("%d %d",&n,&k)){
		sum=0;
		ans=0;
		for(i=0;i<n;i++){
			scanf("%d",&num);
			node[i].fi=num/10;
			node[i].se=num%10;
			sum+=10-node[i].fi;
			ans+=node[i].fi;
		}
		sort(node,node+n,cmp);
		// for(i=0;i<n;i++){
		// 	printf("%d ",node[i].se);
		// }
		// printf("\n");
		//printf("%d %d\n",sum,ans); 
		p=0;
		while(node[p].se>0&&p<n){
			tmp=10-node[p].se;
			if(k>=tmp){
				k-=tmp;
				node[p].se=0;
				node[p].fi++;
				ans++;
				//printf("%d ",p);
				sum--;
				p++;
			}
			else{
				break;
			}
		}
		k/=10;
		if(k>sum){
			ans+=sum;
		}
		else{
			ans+=k;
		}
		printf("%d\n",ans);
	}
    return 0;
}
