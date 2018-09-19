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
#define ll long long
#define read(a) scanf("%d",&a);
using namespace std;
const int maxn=105;
const int inf=99999999;
int a[maxn][maxn];
int b[maxn][maxn];
struct node{
	int kind;
	int number;
};
int main(){
	freopen("test.txt","r",stdin);
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		int sum1=0,sum2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				b[i][j]=a[i][j];
				sum1+=a[i][j];
			}
		}
		sum2=sum1;
		queue<node>que1,que2;
		while(!que1.empty()){
			que1.pop();
		}
		while(!que2.empty()){
			que2.pop();
		}
		int flag=0;
		struct node tmp;
		int cnt1=0,cnt2=0;
		while(sum1){
			int kind;
			int number;
			int mini;
			int maxn=-99999999;
			maxn=-99999999;
			for(int i=1;i<=n;i++){
				mini=inf;
				for(int j=1;j<=m;j++){
					mini=min(mini,a[i][j]);
				}
				if(maxn<mini){
					maxn=mini;
					kind=0;
					number=i;
				}
			}
			for(int j=1;j<=m;j++){
				mini=inf;
				for(int i=1;i<=n;i++){
					mini=min(a[i][j],mini);
				}
				if(maxn<mini){
					maxn=mini;
					kind=1;
					number=j;
				}
			}
			if(maxn==0){
				flag=1;
				//printf("-1\n");
				break;
			}
			if(kind==0){
				sum1-=maxn*m;
				for(int j=1;j<=m;j++){
					a[number][j]-=maxn;
				}
				for(int i=1;i<=maxn;i++){
					tmp.number=number;
					tmp.kind=0;
					que1.push(tmp);
					cnt1++;
				}
			}
			else{
				sum1-=maxn*n;
				for(int i=1;i<=n;i++){
					a[i][number]-=maxn;
				}
				for(int i=1;i<=maxn;i++){
					tmp.number=number;
					tmp.kind=1;
					que1.push(tmp);
					cnt1++;
				}
			}
		}
		flag=0;
		while(sum2){
			int kind;
			int number;
			int mini;
			int maxn=-99999999;
			maxn=-99999999;
			for(int j=1;j<=m;j++){
				mini=inf;
				for(int i=1;i<=n;i++){
					mini=min(b[i][j],mini);
				}
				if(maxn<mini){
					maxn=mini;
					kind=1;
					number=j;
				}
			}
			for(int i=1;i<=n;i++){
				mini=inf;
				for(int j=1;j<=m;j++){
					mini=min(mini,b[i][j]);
				}
				if(maxn<mini){
					maxn=mini;
					kind=0;
					number=i;
				}
			}
			if(maxn==0){
				flag=1;
				//printf("-1\n");
				break;
			}
			if(kind==0){
				sum2-=maxn*m;
				for(int j=1;j<=m;j++){
					b[number][j]-=maxn;
				}
				for(int i=1;i<=maxn;i++){
					tmp.number=number;
					tmp.kind=0;
					que2.push(tmp);
					cnt2++;
				}
			}
			else{
				sum2-=maxn*n;
				for(int i=1;i<=n;i++){
					b[i][number]-=maxn;
				}
				for(int i=1;i<=maxn;i++){
					tmp.number=number;
					tmp.kind=1;
					que2.push(tmp);
					cnt2++;
				}
			}
		}

		if(flag){
			printf("-1\n");
			continue;
		}
		//printf("%d\n",que.size());
		printf("%d\n",cnt1>cnt2?cnt2:cnt1);
		if(cnt1<cnt2){
			while(!que1.empty()){
				tmp=que1.front();
				que1.pop();
				if(tmp.kind==1)
					printf("col ");
				else
					printf("row ");
				printf("%d\n",tmp.number);
			}
		}
		else{
			while(!que2.empty()){
				tmp=que2.front();
				que2.pop();
				if(tmp.kind==1)
					printf("col ");
				else
					printf("row ");
				printf("%d\n",tmp.number);
			}
		}
	}
	return 0;
}