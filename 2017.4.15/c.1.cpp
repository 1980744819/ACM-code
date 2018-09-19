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
std::queue<int> q[300005];
std::vector<int> v;
bool vis[300005];
int main(){
	int n,q;
	int i,j;
	int re[]
	scanf("%d %d",&n,&q);
	int cnt=0;
	int a,b;
	int sum=0;
	while(q--){
		scanf("%d %d",&a,&b);
		if(a==1){
			q[b].push(cnt);
			v.push_back(cnt);
			cnt++;
			sum++;
		}
		else if(a==2){
			while(!q[b].empty()){
				
			}
		}
		else{

		}
	}
    return 0;
}
