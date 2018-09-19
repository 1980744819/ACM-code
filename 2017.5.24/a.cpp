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
long long aabs(long long x){
	return x>=0? x:-x;
}
struct stu{
	long long num;
	int id;
	bool operator < (const struct stu &a)const{
		return aabs(num)>aabs(a.num);
	}
};
long long data[200005];
int main(){
	int  n,k,x;
	int i,j;
	int zcoun=0,ncoun=0;
	priority_queue<struct stu>que;
	scanf("%d %d %d",&n,&k,&x);
	struct stu node;
	for(i=0;i<n;i++){
		scanf("%lld",&data[i]);
		if(data[i]<0)
			ncoun++;
		if(data[i]==0)
			zcoun++;
		node.num=data[i];
		node.id=i;
		que.push(node);
	}
	while(k--){
		node=que.top();
		que.pop();
		if(ncoun%2==0){
			if(node.num<0){
				node.num+=x;
				if(node.num>=0)
					ncoun--;
			}
			else if(node.num==0){
				node.num-=x;
				if(node.num<0)
					ncoun++;
			}
			else{
				node.num-=x;
				if(node.num<0)
					ncoun++;
			}
		}
		else{
			if(node.num<0){
				node.num-=x;
			}
			else if(node.num==0){
				node.num+=x;
			}
			else{
				node.num+=x;
			}
		}
		que.push(node);
	}
	while(!que.empty()){
		node=que.top();
		data[node.id]=node.num;
		//printf("%d %d\n",node.num,node.id);
		que.pop();
	}
	for(i=0;i<n;i++){
		printf("%lld ",data[i]);
	}
	printf("\n");
    return 0;
}
