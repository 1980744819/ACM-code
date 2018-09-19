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
	int a,b;
	int step;
	int fa;
	int way;
};
std::vector<struct stu> que;
std::vector<struct stu >::iterator it;
void print(int num){
	if(que[num].fa==-1){
		if(que[num].way==0){//0
			cout<<"FILL(1)"<<endl;
		}
		else if(que[num].way==1){//1
			cout<<"FILL(2)"<<endl;
		}
		else if(que[num].way==2){//2
			cout<<"POUR(2,1)"<<endl;
		}
		else if(que[num].way==3){//3
			cout<<"POUR(1,2)"<<endl;
		}
		else if(que[num].way==4){//4
			cout<<"DROP(1)"<<endl;
		}
		else if(que[num].way==5){//5
			cout<<"DROP(2)"<<endl;
		}
		return;
	}
	else{
		print(que[num].fa);
		if(que[num].way==0){//0
			cout<<"FILL(1)"<<endl;
		}
		else if(que[num].way==1){//1
			cout<<"FILL(2)"<<endl;
		}
		else if(que[num].way==2){//2
			cout<<"POUR(2,1)"<<endl;
		}
		else if(que[num].way==3){//3
			cout<<"POUR(1,2)"<<endl;
		}
		else if(que[num].way==4){//4
			cout<<"DROP(1)"<<endl;
		}
		else if(que[num].way==5){//5
			cout<<"DROP(2)"<<endl;
		}
		return;
	}
}
bool book[105][105];
int main(){
	//freopen("test.txt","r",stdin);
	int na,nb,nc;
	int i,j;
	struct stu tm,tmp;
	int front;
	bool flag;
	while(cin>>na>>nb>>nc){
		book[0][0]=true;
		que.clear();
		tmp.a=na;tmp.b=0;tmp.fa=-1;tmp.way=0;tmp.step=1;
		que.push_back(tmp);
		tmp.a=0;tmp.b=nb;tmp.fa=-1;tmp.way=1;tmp.step=1;
		que.push_back(tmp);
		tm=que[0];
		front=0;
		flag=false;
		//cout<<que.size()<<endl;
		while(front<que.size()){
		 	tm=que[front];
		 	//cout<<tm.a<<" "<<tm.b<<" "<<tm.way<<" "<<tm.step<<endl;
		 	if(tm.a==nc||tm.b==nc){
		 		flag=true;
		 		cout<<tm.step<<endl;
		 		print(front);
		 		break;
		 	}
		 	tmp.step=tm.step+1;
		 	tmp.fa=front;
		 	front++;
		 	if(!book[tm.a][tm.b])
		 		book[tm.a][tm.b]=true;
		 	else
		 		continue;
		 	if(tm.a!=na){//0
		 		tmp.a=na;
		 		tmp.b=tm.b;
		 		tmp.way=0;
		 		if(book[tmp.a][tmp.b]!=true){
		 			que.push_back(tmp);
		 		}
		 	}
		 	if(tm.b!=nb){//1
		 		tmp.a=tm.a;
		 		tmp.b=nb;
		 		tmp.way=1;
		 		if(book[tmp.a][tmp.b]!=true){
		 			que.push_back(tmp);
		 		}
		 	}
		 	if(tm.a!=na&&tm.b!=0){//2
		 		if(tm.b+tm.a>=na){
		 			tmp.a=na;
		 			tmp.b=tm.a+tm.b-na;
		 		}
		 		else{
		 			tmp.a=tm.a+tm.b;
		 			tmp.b=0;
		 		}
		 		tmp.way=2;
		 		if(book[tmp.a][tmp.b]!=true){
		 			que.push_back(tmp);
		 		}
		 	}
		 	if(tm.b!=nb&&tm.a!=0){//3
		 		if(tm.a+tm.b>=nb){
		 			tmp.b=nb;
		 			tmp.a=tm.a+tm.b-nb;
		 		}
		 		else{
		 			tmp.b=tm.a+tm.b;
		 			tmp.a=0;
		 		}
		 		tmp.way=3;
		 		if(book[tmp.a][tmp.b]!=true){
		 			que.push_back(tmp);
		 		}
		 	}
		 	if(tm.a!=0){//4
		 		tmp.a=0;
		 		tmp.b=tm.b;
		 		tmp.way=4;
		 		if(book[tmp.a][tmp.b]!=true){
		 			que.push_back(tmp);
		 		}
		 	}
		 	if(tm.b!=0){//5
		 		tmp.a=tm.a;
		 		tmp.b=0;
		 		tmp.way=5;
		 		if(book[tmp.a][tmp.b]!=true){
		 			que.push_back(tmp);
		 		}
		 	}
		}
		if(!flag)
			cout<<"impossible"<<endl;
		memset(book,false,sizeof(book));
	}
	return 0;
}