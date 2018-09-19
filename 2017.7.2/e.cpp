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
bool prim[10005];
bool book[10005];
bool jud(int num){
	int i=2;
	for(i=2;i*i<=num;i++){
		if(num%i==0){
			return false;
		}
	}
	return true;
}
struct stu{
	int num,step;
};
int main(){
	//freopen("test.txt","r",stdin);
	int a,b;
	int i,j;
	for(i=1000;i<=9999;i++){
		if(jud(i)){
			prim[i]=true;
			//printf("%d,",i);
		}
	}
	int t;
	scanf("%d",&t);
	queue<struct stu>que;
	struct stu tm,tmp;
	int te;
	int dig[4];
	while(t--){
		scanf("%d %d",&a,&b);
		while(!que.empty()){
			que.pop();
		}
		tmp.num=a;
		tmp.step=0;
		que.push(tmp);
		while(!que.empty()){
			tm=que.front();
			//printf("%d %d\n",tm.num,tm.step);
			if(tm.num==b){
				printf("%d\n",tm.step);
				break;
			}
			te=tm.num;
			tmp.step=tm.step+1;
			for(i=3;i>=0;i--){
				dig[i]=te%10;
				te/=10;
			}
			for(i=1;i<10;i++){
				te=1000*i+dig[1]*100+dig[2]*10+dig[3];
				if(te!=tm.num&&prim[te]&&!book[te]){
					book[te]=true;
					tmp.num=te;
					que.push(tmp);
				}
			}
			for(i=0;i<10;i++){
				te=1000*dig[0]+i*100+dig[2]*10+dig[3];
				if(te!=tm.num&&prim[te]&&!book[te]){
					book[te]=true;
					tmp.num=te;
					que.push(tmp);
				}
			}
			for(i=0;i<10;i++){
				te=1000*dig[0]+dig[1]*100+i*10+dig[3];
				if(te!=tm.num&&prim[te]&&!book[te]){
					book[te]=true;
					tmp.num=te;
					que.push(tmp);
				}
			}
			for(i=0;i<10;i++){
				te=1000*dig[0]+dig[1]*100+dig[2]*10+i;
				if(te!=tm.num&&prim[te]&&!book[te]){
					book[te]=true;
					tmp.num=te;
					que.push(tmp);
				}
			}
			que.pop();
		}
		for(i=1000;i<=9999;i++){
			book[i]=false;
		}
	}
	return 0;
}