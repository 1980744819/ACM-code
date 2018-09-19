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
int m,n;
bool book[810][810][2];
char mp[810][810];
struct stu{
	int x,y;
	//int step;
}gost[2],G,M;
int nextx[4]={0,0,1,-1};
int nexty[4]={1,-1,0,0};
struct stu tmp,tm;
queue<struct stu>que[2];
int coun;
bool judge(int x,int y){
	if(x<0||x>=m||y<0||y>=n)return false;
	if(mp[x][y]=='X') return false;
	if(abs(x-gost[0].x)+abs(y-gost[0].y)<=2*coun)return false;
	if(abs(x-gost[1].x)+abs(y-gost[1].y)<=2*coun)return false;
	return true; 
}
int bfs(int k){
	int i,j;
	int sum=que[k].size();
	while(sum--){
		tm=que[k].front();
		que[k].pop();
		if(!judge(tm.x,tm.y))
			continue;
		//tmp.step=tm.step+1;
		for(i=0;i<4;i++){
			tmp.x=tm.x+nextx[i];
			tmp.y=tm.y+nexty[i];
			if(!judge(tmp.x,tmp.y))
				continue;
			if(!book[tmp.x][tmp.y][k]){
				book[tmp.x][tmp.y][k]=true;
				if(book[tmp.x][tmp.y][1-k]) return 1;
				que[k].push(tmp);
			}
		}
	}
	return 0;
}
int main(){
	//freopen("test.txt","r",stdin);
	int t;
	int i,j;
	//int coun;
	scanf("%d",&t);
	bool flag;
	while(t--){
		scanf("%d %d",&m,&n);
		coun=0;
		for(i=0;i<m;i++)
			scanf("%s",mp[i]);
		for(i=0;i<m;i++){
			//getchar();
			for(j=0;j<n;j++){
				//scanf("%c",&mp[i][j]);
				if(mp[i][j]=='Z'){
					gost[coun].x=i;
					gost[coun].y=j;
					coun++;
				}
				if(mp[i][j]=='G'){
					G.x=i;
					G.y=j;
				}
				if(mp[i][j]=='M'){
					M.x=i;
					M.y=j;
				}
			}
		}
		while(!que[0].empty())
			que[0].pop();
		while(!que[1].empty())
			que[1].pop();
		tmp.x=M.x;
		tmp.y=M.y;
		//tmp.step=0;
		book[tmp.x][tmp.y][0]=true;
		que[0].push(tmp);
		tmp.x=G.x;
		tmp.y=G.y;
		//tmp.step=0;
		book[tmp.x][tmp.y][1]=true;
		que[1].push(tmp);
		coun=0;
		flag=false;
		while((!que[0].empty())||(!que[1].empty())){
			coun++;
			if(bfs(0)){
				flag=true;
				printf("%d\n",coun);
				break;
			}
			if(bfs(0)){
				flag=true;
				printf("%d\n",coun);
				break;
			}
			if(bfs(0)){
				flag=true;
				printf("%d\n",coun);
				break;
			}
			if(bfs(1)){
				flag=true;
				printf("%d\n",coun);
				break;
			}
		}
		if(!flag)
			printf("-1\n");
		memset(book,false,sizeof(book));
	}
	return 0;
}