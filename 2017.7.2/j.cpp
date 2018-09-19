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
	int num1,num2;
	int left;
};
bool book[105][105][105];
int main(){
	freopen("test.txt","r",stdin);
	int a,b,c;
	int i,j;
	struct stu tmp,tm;
	queue<struct stu>que;
	int n1,n2;
	while(~scanf("%d %d %d",&a,&b,&c)){
		book[a][0][0]=true;
		if(a%2==1){
			printf("NO\n");
			continue;
		}
		while(!que.empty()){
			que.pop();
		}
		n1=n2=0;
		tmp.num1=tmp.num2=tmp.left=0;
		que.push(tmp);
		while(!que.empty()){
			tm=que.front();
			if(tm.num1!=b){
				
			}
			if(tm.num2!=c){

			}
			if(tm.num1!=b&&tm.num2!=0){

			}
			if(tm.num2!=c&&tm.num1!=0){

			}
			if(tm.num1!=b){

			}
			if(tm.num2!=c){
				
			}
		}	
	}
	return 0;
}