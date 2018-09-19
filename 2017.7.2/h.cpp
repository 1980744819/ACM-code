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
int mp[10][10];
bool book[10][10];
struct stu{
	int x,y;
	int step;
	int fa;
}que[1005];
int nextx[4]={0,1,0,-1};
int nexty[4]={1,0,-1,0};
void dfs(int num){
	if(que[num].fa==-1){
		printf("(0, 0)\n");
		return;
	}
	else{
		dfs(que[num].fa);
		printf("(%d, %d)\n",que[num].x,que[num].y);
	}
}
int main(){
	//freopen("test.txt","r",stdin);
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			scanf("%d",&mp[i][j]);
			//printf("%d ",mp[i][j]);
		}
		//printf("\n");
	}
	int front,tail;
	struct stu tm,tmp;
	tmp.x=tmp.y=tmp.step=0;
	tmp.fa=-1;
	front=0;
	que[front].x=tmp.x;
	que[front].y=tmp.y;
	que[front].step=tmp.step;
	que[front].fa=tmp.fa;
	tail=front;
	book[0][0]=true;
	while(front<=tail){
		if(que[front].x==4&&que[front].y==4){
			dfs(front);
		}
		tmp.step=que[front].step+1;
		tmp.fa=front;
		for(i=0;i<4;i++){
			tmp.x=nextx[i]+que[front].x;
			tmp.y=nexty[i]+que[front].y;
			if(tmp.x>=5||tmp.x<0||tmp.y>=5||tmp.y<0)
				continue;
			if(!book[tmp.x][tmp.y]&&mp[tmp.x][tmp.y]==0){
				book[tmp.x][tmp.y]=true;
				tail++;
				que[tail].x=tmp.x;
				que[tail].y=tmp.y;
				que[tail].step=tmp.step;
				que[tail].fa=tmp.fa;
			}
		}
		front++;
	}
	return 0;
}