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
	//freopen("test.txt","r",stdin);
	int num;
	long long tmp;
	queue<long long>que;
	while(~scanf("%d",&num)&&num){
		que.push(1);
		while(!que.empty()){
			tmp=que.front();
			//printf("%lld,",tmp);
			if(tmp%num==0){
				printf("%lld\n",tmp);
				break;
			}
			que.push(tmp*10);
			que.push(tmp*10+1);
			que.pop();
		}
		while(!que.empty()){
			que.pop();
		}
	}
	return 0;
}