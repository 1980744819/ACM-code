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
#define ll long long
using namespace std;
const int maxn=100005;
bool book[maxn];
struct node{
	int val,step;
};
std::vector<int> vec[maxn];
int main(){
	//freopen("finput6.in","r",stdin);
	// freopen("a.out","w",stdout);
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	queue<node>que;
	book[1]=true;
	for(int i=0;i<vec[1].size();i++){
		node tmp;
		tmp.val=vec[1][i];
		tmp.step=1;
		que.push(tmp);
		book[vec[1][i]]=true;
		if(vec[1][i]==n){
			printf("PP will be happy!\n");
			return 0;
		}
	}
	bool flag=false;
	while(!que.empty()){
		node tmp,tm;
		tmp=que.front();
		if(tmp.step>6){
			printf("PP will die!\n");
			return 0;
		}
		if(tmp.val==n){
			printf("PP will be happy!\n");
			return 0;
		}
		tm.step=tmp.step+1;
		for(int i=0;i<vec[tmp.val].size();i++){
			if(book[vec[tmp.val][i]]){
				continue;
			}
			else{
				book[vec[tmp.val][i]]=true;
				tm.val=vec[tmp.val][i];
				que.push(tm);
			}
		}
		que.pop();
	}
	if(!flag)
		printf("PP will die!\n");
    return 0;
}
