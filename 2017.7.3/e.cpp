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
	char s[36];
	int step;
};
char aim[36];
char temp[36];
int main(){
	freopen("test.txt","r",stdin);
	int t;
	int i,j;
	int coun;
	struct stu tmp,tm;
	queue<struct stu>que;
	map<string,int>mp;
	scanf("%d",&t);
	for(i=0;i<4;i++){
		for(j=0;j<8;j++){
			if(j==7){
				aim[i*8+j]=1;
			}
			else{
				aim[i*8+j]=(i+1)*10+j+1;
			}
		}
	}
	// for(i=0;i<4;i++){
	// 	for(j=0;j<8;j++){
	// 		printf("%d ",aim[i*8+j]);
	// 	}
	// 	printf("\n");
	// }
	bool flag;
	while(t--){
		coun=11;
		for(i=0;i<4;i++){
			temp[i*8]=coun;
			coun+=10;
		}
		for(i=0;i<4;i++){
			for(j=1;j<8;j++){
				scanf("%d",&coun);
				if(coun%10==1){
					temp[i*8+j]=1;
				}
				else{
					temp[i*8+j]=coun;
				}
			}
		}
		mp.clear();
		while(!que.empty())
			que.pop();
		for(i=0;i<36;i++){
			tmp.s[i]=temp[i];
			//printf("%d ",tmp.s[i]);
		}
		//printf("\n");
		tmp.step=0;
		que.push(tmp);
		coun=1;
		mp[aim]=coun++;
		if(mp[aim]==mp[temp]){
			printf("0\n");
			continue;
		}
		mp[temp]=coun++;
		flag=false;
		while(!que.empty()){
			tm=que.front();
			// for(i=0;i<32;i++){
			// 	printf("%d ",tm.s[i]);
			// 	if((i+1)%8==0)
			// 		printf("\n");
			// }
			// printf("%d\n",tm.step);
			// if(tm.step==3){
			// 	printf("%d !!!!!!!!!!!!\n",t);
			// 	break;
			// }
			que.pop();
			for(i=1;i<32;i++){
				if(tm.s[i]==1&&tm.s[i-1]!=1&&tm.s[i-1]%10!=7){
					tmp=tm;
					tmp.step=tm.step+1;
					for(j=0;j<32;j++){
						if(tmp.s[j]==tm.s[i-1]+1){
							tmp.s[j]=1;
							break;
						}
					}
					tmp.s[i]=tm.s[i-1]+1;
					if(mp[tmp.s]==mp[aim]){
						flag=true;
						printf("%d\n",tmp.step);
						break;
					}
					if(mp[tmp.s]==0){
						//coun++;
						mp[tmp.s]=coun++;
						que.push(tmp);
					}
				}
			}
			if(flag){
				break;
			}
		}
		if(!flag)
			printf("-1\n");
	}
	return 0;
}