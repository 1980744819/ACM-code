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
int t[200005];
vector<int>dis;
int main(){
	int i,j;
	int n,k;
	int tol;
	int len;
	int l,r;
	scanf("%d %d",&n,&k);
	tol=0;
	l=-1;
	r=-1;
	for(i=0;i<n;i++){
		scanf("%d",&t[i]);
		if(t[i]<0){
			tol++;
			r=i;
			if(l!=-1)
				dis.push_back(r-l-1);
			l=i;
		}
	}
	if(tol>k){
		printf("-1\n");
		return 0;
	}
	k-=tol;
	tol*=2;
	// for(i=0;i<dis.size();i++){
	// 	printf("%d ",dis[i]);
	// }
	// printf("\n");
	sort(dis.begin(),dis.end());
	for(i=0;i<dis.size();i++){
		if(k>=dis[i]){
			k-=dis[i];
			tol-=2;
		}
		else{
			break;
		}
	}
	if(k>=n-1-r&&r!=-1)
		tol--;
	printf("%d\n",tol);
    return 0;
}
