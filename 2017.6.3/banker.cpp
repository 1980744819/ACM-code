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
int avi[105],max_need[100][105],allo[100][105],need[100][105];//可分配资源数，最大需求，已分配资源，需求资源
bool vis[100];//各个进程是否满足需求
int n,m;
bool judge(int i){//判断第i个进程的需求是否能满足
	for(int j=0;j<n;j++){
		if(need[i][j]>avi[j])
			return false;
	}
	return true;
}
int main(){
	int i,j;
	memset(vis,false,sizeof(vis));
	scanf("%d %d",&n,&m);//资源种类，进程数量
	for(i=0;i<n;i++){
		scanf("%d",avi[i]);
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",max_need[i][j]);
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",allo[i][j]);
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			//scanf("%d",need[i][j]);
			need[i][j]=max_need[i][j]-allo[i][j];
		}
	}
	int sum=0;
	for(i=0;i<m;i++){
		for(j=0;i<m;j++){//从第一个进程开始，扫描未被满足资源的进程
			if(vis[j]==false){//j进程的需求未被满足
				if(judge(j)){//j进程的需求能被满足
					vis[j]=true;//分配给j进程资源，
					sum++;
					printf("process %d solved\n",j);//j进程运行完成,释放资源，更新可用资源信息
					for(int k=0;k<n;k++){
						avi[k]+=allo[j][k];
						allo[j][k]=0;
						need[j][k]=0;
					}
					break;//解决了这个进程就没必要往后扫描了，退出这个扫描，从头开始
				}
			}
		}
	}
	printf("the sum of solved processes is %d\n",sum);
    return 0;
}
