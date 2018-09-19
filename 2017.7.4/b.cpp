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
struct stu{
	int x,y;
	int f,h,g;
	int has;
	int maze[3][3];
	bool operator>(const stu n1)const{
		return h!=n1.h?h>n1.h:g>n1.g;
	}
	bool check(){
		if(x<0||x>=3||y<0||y>=3)
			return false;
		return true;
	}
}
int Hash[]={1,1,2,6,24,120,720,5040,40320};
int aim=322560;
int vis[400000];
int pre[400000];
int nextx[4]={1,-1,0,0};
int nexty[4]={0,0,-1,1};
struct stu tmp,tm;
int gethash(struct stu temp){
	int num[9];
	int i,j,k;
	k=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			num[k++]=temp.maze[i][j];
		}
	}
	int result=0;
	int coun=0;
	for(i=0;i<9;i++){
		coun=0;
		for(j=0;j<i;j++){
			if(a[j]>a[i])
				coun++;
		}
		result+=coun*Hash[i];
	}
	return result;
}
int geth(struct stu temp){
	int result = 0 ;
	for(int i = 0 ; i < 3 ; ++i)
	{
		for(int j = 0 ; j < 3 ; ++j)
		{
			if(temp.maze[i][j])
			{
				int x = (n.maze[i][j]-1)/3 , y = (n.maze[i][j]-1)%3 ;
				result += abs(x-i)+abs(y-j) ;
			}
		}
	}
	return result ;
}
int main(){
	char str[100];
	int num[9];
	int i,j,k;
	struct stu t;
	while(gets(str)){
		//puts(str);
		memset(vis,-1,sizeof(vis));
		memset(pre,-1,sizeof(pre));
		j=0;
		for(i=0;i<strlen(str);i++){
			if(str[i]=='x'){
				num[j++]=0;
			}
			if(str[i]>='1'&&str[i]<='8'){
				num[j++]=str[i]-'0';
			}
		}
		k=0;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				t.maze[i][j]=num[k++];
				if(t.maze[i][j]==0){
					t.x=i;
					t.y=j;
				}
			}
		}
		t.has=gethash(t);
		vis[t.has]=-2;
		t.g=0;

	}
    return 0;
}
