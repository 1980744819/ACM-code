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
struct stu{
	int pos,step;
};
bool book[400005];
int main(){
	//freopen("test.txt","r",stdin);
	int n,k;
	int num;
	queue<struct stu>que;
	struct stu tmp,tm;
	while(~scanf("%d %d",&n,&k)){
		tmp.pos=n;
		tmp.step=0;
		que.push(tmp);
		if(n==k){
			printf("0\n");
			continue;
		}
		while(!que.empty()){
			tm=que.front();
			//printf("%d %d\n",tm.pos,tm.step);
			tmp.pos=tm.pos+1;
			tmp.step=tm.step+1;
			if(tmp.pos==k){
				printf("%d\n",tmp.step);
				break;
			}
			if(book[tmp.pos]==false){
				que.push(tmp);
				book[tmp.pos]=true;
			}
			tmp.pos=tm.pos-1;
			tmp.step=tm.step+1;
			if(tmp.pos==k){
				printf("%d\n",tmp.step);
				break;
			}
			if(book[tmp.pos]==false&&tmp.pos>=0){
				que.push(tmp);
				book[tmp.pos]=true;
			}
			tmp.pos=tm.pos*2;
			tmp.step=tm.step+1;
			if(tmp.pos==k){
				printf("%d\n",tmp.step);
				break;
			}
			if(book[tmp.pos]==false&&tmp.pos<100105){
				que.push(tmp);
				book[tmp.pos]=true;
			}
			que.pop();
		}
		while(!que.empty()){
			que.pop();
		}
		memset(book,false,sizeof(book));
	}
	return 0;
}