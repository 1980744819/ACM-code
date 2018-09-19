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
bool book[205][205];
struct stu{
	int x,y;
	int step;
};
int m,n;
char mp[205][205];
int  dis[205][205][2];
int nextx[4]={-1,1,0,0};
int nexty[4]={0,0,1,-1};
void bfs(int startx,int starty,int all,int coun){
	int i,j;
	queue<struct stu>que;
	struct stu tmp,tm;
	while(!que.empty())
		que.pop();
	tmp.x=startx;
	tmp.y=starty;
	tmp.step=0;
	book[tmp.x][tmp.y]=true;
	dis[tmp.x][tmp.y][coun]=0;
	que.push(tmp);
	int cal;
	cal=0;
	while(!que.empty()&&cal<all){
		tm=que.front();
		tmp.step=tm.step+1;
		//printf("%d %d %d\n",tm.x,tm.y,tm.step);
		for(i=0;i<4;i++){
			tmp.x=tm.x+nextx[i];
			tmp.y=tm.y+nexty[i];
			if(tmp.x<0||tmp.x>=m||tmp.y<0||tmp.y>=n)
				continue;
			if(mp[tmp.x][tmp.y]=='#'||mp[tmp.x][tmp.y]=='Y'||mp[tmp.x][tmp.y]=='M')
				continue;
			if(book[tmp.x][tmp.y]==false){
				book[tmp.x][tmp.y]=true;
				if(mp[tmp.x][tmp.y]=='@'){
					dis[tmp.x][tmp.y][coun]=tmp.step;
					// for(int p=0;p<m;p++){
					// 	for(int q=0;q<n;q++){
					// 		printf("%d ",dis[p][q]);
					// 	}
					// 	printf("\n");
					// }
					// printf("\n");
					cal++;
				}
				que.push(tmp);
			}
		}
		que.pop();
	}
	memset(book,false,sizeof(book));

}
int main(){
	//freopen("test.txt","r",stdin);
	int i,j;
	int all,coun;
	int Min;
	while(~scanf("%d %d",&m,&n)){
		memset(dis,0,sizeof(dis));
		all=0;
		coun=0;
		for(i=0;i<m;i++){
			getchar();
			for(j=0;j<n;j++){
				scanf("%c",&mp[i][j]);
				if(mp[i][j]=='@'){
					all++;
				}
			}
			//scanf("%s",mp[i]);
		}
		// for(i=0;i<m;i++){
		// 	for(j=0;j<n;j++){
		// 		printf("%c",mp[i][j]);
		// 	}
		// 	printf("\n");
		// }
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(mp[i][j]=='Y'||mp[i][j]=='M'){
					//coun++;
					bfs(i,j,all,coun);
					coun++;
				}
			}
		}
		Min=0xfffffff;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if((dis[i][j][0]+dis[i][j][1])<Min&&mp[i][j]=='@'&&dis[i][j][0]>0&&dis[i][j][1]>0){
					Min=dis[i][j][0]+dis[i][j][1];
				}
			}
		}
		printf("%d\n",Min*11);
	}
	return 0;
}