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
int val[505],wei[505];
int dp[1005];
struct stu{
	int left;
	int money;
};
int main(){
	//freopen("test.txt","r",stdin);
	int t;
	int a,b;
	int coun;
	int i,j;
	int n,m;
	bool flag;
	scanf("%d",&t);
	queue<struct stu>que;
	struct stu tm,tmp;
	int temp;
	while(t--){
		scanf("%d %d",&a,&b);
		coun=b-a;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d %d",&val[i],&wei[i]);
		}
		while(!que.empty())
			que.pop();
		flag=false;
		tmp.left=coun;
		tmp.money=0;
		que.push(tmp);
		int Max;
		Max=99999999;
		while(!que.empty()){
			tm=que.front();
			que.pop();
			//printf("%d\n",temp);
			for(i=0;i<n;i++){
				if(tm.left>=wei[i]){
					tmp=tm;
					if(tmp.left%wei[i]==0){
							temp=tmp.money+((tmp.left/wei[i])*val[i]);
						if(Max>temp)
							Max=temp;
						flag=true;
					}
					else{
						temp=tmp.left/wei[i];
						tmp.money+=temp*val[i];
						tmp.left=tmp.left%wei[i];
						que.push(tmp);
					}
				}	
			}
		}
		if(!flag){
			printf("This is impossible.\n");
			continue;
		}
		else{
			printf("The minimum amount of money in the piggy-bank is %d.\n",Max);
		}
		
	}
	return 0;
}