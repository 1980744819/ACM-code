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
	int cur[3],step;
};
bool book[105][105][105];
int main(){
	//freopen("test.txt","r",stdin);
	int a,b,c;
	int num[3];
	int i,j;
	int half;
	bool flag;
	struct stu tmp,tm,t;
	queue<struct stu>que;
	while(cin>>num[0]>>num[1]>>num[2]){
		if(num[0]==0&&num[1]==0&&num[2]==0)
			break;
		half=num[0]/2;
		if(num[0]%2){
			cout<<"NO"<<endl;
			continue;
		}
		while(!que.empty())
			que.pop();
		tmp.cur[0]=num[0];
		tmp.cur[1]=0;
		tmp.cur[2]=0;
		tmp.step=0;
		book[tmp.cur[0]][tmp.cur[1]][tmp.cur[2]]=true;
		que.push(tmp);
		flag=false;
		while(!que.empty()){
			tm=que.front();
			// for(i=0;i<3;i++)
			// 	cout<<tm.cur[i]<<" ";
			// cout<<tm.step<<endl;
			if((tm.cur[0]==half&&tm.cur[1]==half)||(tm.cur[1]==half&&tm.cur[2]==half)||(tm.cur[2]==half&&tm.cur[0]==half)){
				flag=true;
				cout<<tm.step<<endl;
				break;
			}
			//tmp.step=tm.step+1;
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					if(i==j)
						continue;
					tmp=tm;
					tmp.step=tm.step+1;
					if(tm.cur[i]!=0&&tm.cur[j]!=num[j]){
						if(num[j]<=tm.cur[j]+tm.cur[i]){
							tmp.cur[j]=num[j];
							tmp.cur[i]=tm.cur[i]+tm.cur[j]-num[j];
						}
						else{
							tmp.cur[j]=tm.cur[i]+tm.cur[j];
							tmp.cur[i]=0;
						}
						if(book[tmp.cur[0]][tmp.cur[1]][tmp.cur[2]]==false){
							book[tmp.cur[0]][tmp.cur[1]][tmp.cur[2]]=true;
							que.push(tmp);
						}
					}
				}
			}
			que.pop();
		}
		if(!flag){
			cout<<"NO"<<endl;
		}
		memset(book,false,sizeof(book));
	}
	return 0;
}