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
int main(){
	freopen("test.txt","r",stdin);
	int i,j;
	vector<int>a;
	vector<int>r;
	int k;
	int ai,ri;
	priority_queue<int,greator<int> >que;
	int tmp,tm;
	int Min;
	bool flag;
	int sz;
	while(~scanf("%d",&k)){
		while(k--){
			scanf("%d %d",&ai,&ri);
			a.push_back(ai);
			r.push_back(ri);
			que.push(ai);
		}
		flag=false;
		Min=que.top();
		que.pop();
		sz=que.size();
		while()
	}
	return 0;
}