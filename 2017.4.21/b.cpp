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
int lan[200005],b[200005],c[200005];
int main(){
	int n,m;
	int i,j;
	map<int,int>mp;
	scanf("%d",&n);
	int num;
	for(i=1;i<=n;i++){
		scanf("%d",&num);
		mp[num]++;
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%d",&c[i]);
	}
	int tmp=1;
	int max=0;
	int ma=0;
	for(i=1;i<=m;i++){
		if(max<mp[b[i]]){
			max=mp[b[i]];
			tmp=i;
			ma=mp[c[i]];
		}
		else if(max==mp[b[i]]){
			if(ma<mp[c[i]]){
				tmp=i;
				ma=mp[c[i]];
			}
		}
	}
	printf("%d\n",tmp);
    return 0;
}
