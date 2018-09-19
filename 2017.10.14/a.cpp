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
#define ll long long
using namespace std;
const int maxn=10000;
int num[30][30];
int main(){
	freopen("test.txt","r",stdin);
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			getchar();
			for(int j=1;j<=n;j++){
				char c;
				scanf("%c",&c);
				num[i][j]=c-'A';
				//printf("%d ",num[i][j]);
			}
			//printf("\n");
		}
		int col[30];
		int row[30];
		for(int i=1;i<=n;i++){
			col[i]=0;
			for(int j=1;j<=n;j++){
				col[i]+=num[i][j];
			}
			//printf("%d ",col[i]);
		}
		//printf("\n");
		for(int j=1;j<=n;j++){
			row[j]=0;
			for(int i=1;i<=n;i++){
				row[j]+=num[i][j];
			}
			//printf("%d ",row[j]);
		}
		//printf("\n");
		int row_num=0,col_num=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(i==1){
				if(col[i]!=col[i+1]&&col[i]!=col[i+2]){
					col_num=i;
					sum=col[i+1];
					break;
				}
			}
			else if(i==n){
				if(col[i]!=col[i-1]&&col[i]!=col[i-2]){
					col_num=i;
					sum=col[i-1];
					break;
				}
			}
			else{
				if(col[i]!=col[i-1]&&col[i]!=col[i+1]){
					col_num=i;
					sum=col[i+1];
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(i==1){
				if(row[i]!=row[i+1]&&row[i]!=row[i+2]){
					row_num=i;
					break;
				}
			}
			else if(i==n){
				if(row[i]!=row[i-1]&&row[i]!=row[i-2]){
					row_num=i;
					break;
				}	
			}
			else{
				if(row[i]!=row[i+1]&&row[i]!=row[i-1]){
					row_num=i;
					break;
				}
			}
		}
		printf("%d %d ",col_num,row_num);
		col[col_num]-=num[col_num][row_num];
		printf("%c\n",sum-col[col_num]+'A');
	}
    return 0;
}