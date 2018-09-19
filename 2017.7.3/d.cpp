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
	int num[3][3];
	int x,y;
	int way;
	int fa;
};
int nextx[4]={1,-1,0,0};
int nexty[4]={0,0,-1,1};//d,u,l,r
std::vector<struct stu> que;
void dfs(int num){
	int i,j;
	if(que[num].fa==-1)
		return;
	else{
		dfs(que[num].fa);
		if(que[num].way==0){
			printf("r");
		}
		else if(que[num].way==1){
			printf("l");
		}
		else if(que[num].way==2){
			printf("d");
		}
		else if(que[num].way==3){
			printf("u");
		}
		// for(i=0;i<3;i++){
		// 	for(j=0;j<3;j++){
		// 		printf("%d ",que[num].num[i][j]);
		// 	}
		// 	printf("\n");
		// }
	}
}
int main(){
	freopen("test.txt","r",stdin);
	map<int ,int>mp;
	int i,j,k;
	char ch;
	char str[100];
	struct stu tmp,tm;
	int num[9];
	int book;
	int front;
	int x_pos,y_pos;
	int tempx,tempy;
	int temp;
	bool flag;
	while(~scanf("%c",&ch)){
		// j=0;
		// for(i=0;i<strlen(str);i++){
		// 	if(str[i]=='x'){
		// 		num[j]=0;
		// 		x_pos=j/3;
		// 		y_pos=j%3;
		// 		j++;
		// 	}
		// 	else if(str[i]>='1'&&str[i]<='9'){
		// 		num[j]=str[i]-'0';
		// 		j++;
		// 	}
		// }
		if(ch=='x'){
			num[0]=0;
			x_pos=0;
			y_pos=0;
		}
		else
			num[0]=ch-'0';
		for(i=1;i<9;i++){
			getchar();
			getchar();
			scanf("%c",&ch);
			if(ch=='x'){
				num[i]=0;
				x_pos=i/3;
				y_pos=i%3;
			}
			else
				num[i]=ch-'0';
		}
		getchar();
		for(i=0;i<9;i++)
			printf("%d ",num[i]);
		printf("\n");
		mp.clear();
		que.clear();
		k=0;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				tmp.num[i][j]=num[k];
				k++;
			}
		}
		//printf("%d %d\n",x_pos,y_pos);
		tmp.x=x_pos;
		tmp.y=y_pos;
		tmp.way=-1;
		tmp.fa=-1;
		book=0;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				book*=10;
				book+=tmp.num[i][j];
			}
		}
		//printf("%d\n",book);
		mp[book]=1;
		que.push_back(tmp);
		front=0;
		flag=false;
		while(front<que.size()){
			// for(i=0;i<3;i++){
			// 	for(j=0;j<3;j++){
			// 		printf("%d ",que[front].num[i][j]);
			// 	}
			// 	printf("\n");
			// }
			book=0;
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					book*=10;
					book+=que[front].num[i][j];
				}
			}
			//printf("%d %d\n",book,front);
			if(book==123456780){
				flag=true;
				dfs(front);
				printf("\n");
				break;
			}
			for(i=0;i<4;i++){
				tmp=que[front];
				tmp.x=que[front].x+nextx[i];
				tmp.y=que[front].y+nexty[i];
				if(tmp.x<0||tmp.x>=3||tmp.y<0||tmp.y>=3)
					continue;
				temp=tmp.num[que[front].x][que[front].y];
				tmp.num[que[front].x][que[front].y]=tmp.num[tmp.x][tmp.y];
				tmp.num[tmp.x][tmp.y]=temp;
				book=0;
				for(j=0;j<3;j++){
					for(k=0;k<3;k++){
						book*=10;
						book+=tmp.num[j][k];
					}
				}
				if(mp[book]==1)
					continue;
				else{
					tmp.way=i;
					tmp.fa=front;
					mp[book]=1;
					que.push_back(tmp);
				}
			}
			front++;
		}
		if(!flag)
			printf("unsolvable\n");
	}
	return 0;
}