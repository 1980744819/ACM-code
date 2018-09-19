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
int p[50005];
int ran[50005];
int main(){
	int t;
	int n;
	int q,op,x,y;
	int num;
	int tmp,tm;
	int i;
	scanf("%d",&t);
	int coun;
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&p[i]);
			ran[p[i]]=i;
		}
		/*for(i=1;i<=n;i++){
			printf("rank %d = %d\n",i,ran[i]);
		}*/
		num=n*6;
		num/=10;
		//printf("num=%d\n",num);
		scanf("%d",&q);
		while(q--){
			scanf("%d %d %d",&op,&x,&y);
			//该队伍的排名
			if(op==1){
				x=p[x];
				tmp=ran[x];
				while(x!=y){
					ran[x]=ran[x-1];
					p[ran[x-1]]++;
					x--;
				}
				ran[y]=tmp;
				p[tmp]=y;
				/*for(i=1;i<=n;i++){
					printf("rank %d = %d\n",i,ran[i]);
				}
				for (i = 1; i <=n; ++i){
					printf("%d ",p[i]);
				}
				printf("\n");*/
			}
			else{
				coun=0;
				//printf("%d\n",num);
				for(i=x;i<=y;i++){
					//printf("%d %d\n",i,p[i]);
					if(p[i]>num){
						coun++;
					}
				}
				printf("%d\n",coun);
			}
		}
	}
    return 0;
}
