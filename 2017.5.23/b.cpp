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
struct stu1{
	int num;
	int id;
	bool operator < (const stu1 &a)const{
		return num<a.num;
	}
};
struct stu2{
	int num;
	int id;
	bool operator < (const stu2 &a) const{
		return num>a.num;
	}
};
int data[200005];

int main(){
	int n,k,x;
	int i,j;
	priority_queue<struct stu1>que1;
	priority_queue<struct stu2>que2;
	long long pro=1,tmp1,tmp2,tm1,tm2;
	scanf("%d %d %d",&n,&k,&x);
	struct stu1 node1;
	struct stu2 node2;
	for(i=0;i<n;i++){
		scanf("%d",&data[i]);
		pro*=data[i];
		if(data[i]<0){
			node1.num=data[i];
			node1.id=i;
			que1.push(node1);
		}
		else{
			node2.num=data[i];
			node2.id=i;
			que2.push(node2);
		}
	}
	//printf("%lld\n",pro);
	//k--;
	while(k--){
		//printf("%d\n",k);
		if(!que1.empty()&&!que2.empty()){
			printf("1\n");
			node1=que1.top();
			node2=que2.top();
			if(node1.num!=0)
				tmp1=pro/node1.num;
			tmp2=pro/node2.num;
			if(pro<0){
				tm1=tmp1*(node1.num-x);
				tm2=tmp2*(node2.num+x);
				if(tm1<tm2){
					pro=tm1;
					que1.pop();
					node1.num=node1.num-x;
					que1.push(node1);
				}
				else{
					pro=tm2;
					que2.pop();
					node2.num=node2.num+x;
					que2.push(node2);
				}
			}
			else{
				tm1=tmp1*(node1.num+x);
				tm2=tmp2*(node2.num-x);
				if(tm1<tm2){
					pro=tm1;
					que1.pop();
					if((node1.num+x)>=0){
						node2.num=node1.num+x;
						node2.id=node1.id;
						que2.push(node2);
					}
					else{
						node1.num=node1.num+x;
						que1.push(node1);
					}

				}
				else{
					pro=tm2;
					que2.pop();
					if((node2.num-x)<0){
						node1.num=node2.num-x;
						node1.id=node2.id;
						que1.push(node1);
					}
					else{
						node2.num=node2.num-x;
						que2.push(node2);
					}
				}
			}
		}
		else if(!que1.empty()&&que2.empty()){
			printf("2\n");
			node1=que1.top();
			tmp1=pro/node1.num;
			if(pro<0){
				tm1=tmp1*(node1.num-x);
				pro=tm1;
				node1.num=node1.num-x;
				que1.pop();
				que1.push(node1);
			}
			else{
				tm1=tmp1*(node1.num+x);
				pro=tm1;
				que1.pop();
				if((node1.num+x)<0){
					node1.num=node1.num+x;
					que1.push(node1);
				}
				else{
					node2.num=node1.num+x;
					node2.id=node1.id;
					que2.push(node2);
				}
			}
		}
		else if(que1.empty()&&!que2.empty()){
			printf("3\n");
			node2=que2.top();
			tmp2=pro/node2.num;
			pro=tmp2*(node2.num-x);
			que2.pop();
			if(pro<0){
				node1.num=node2.num-x;
				node1.id=node2.id;
				que1.push(node1);
			}
			else{
				node2.num=node2.num-x;
				que2.push(node2);
			}
		}
	}
	//printf("1\n");
	while(!que1.empty()){
		node1=que1.top();
		que1.pop();
		data[node1.id]=node1.num;
	}
	while(!que2.empty()){
		node2=que2.top();
		que2.pop();
		data[node2.id]=node2.num;
		//printf("%d\n",node2.num);
	}
	for(i=0;i<n;i++){
		printf("%d ",data[i]);
	}
	printf("\n");
    return 0;
}
