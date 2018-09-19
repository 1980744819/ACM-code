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
int gri[105][105];
int ans1[105][105],ans2[105][105],ans3[105][105],ans4[105][105];
int main(){
	int i,j;
	int m,n;
	int mi;
	int flag;
	vetcor<int>veca,vecb;
	while(~scanf("%d,%d",&m,&n)){
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				scanf("%d",&gri[i][j]);
				ans[i][j]=gri[i][j];
			}
		}
		if(m<=n){
			for(i=0;i<m;i++){
				min=99999;
				for(j=0;j<n;j++){
					if(min<ans[i][j]){
						min=ans[i][j];
					}
				}
				if(min!=0){
					for(j=0;j<n;j++){
						ans[i][j]-=min;
					}
					veca.push_back(i);
					vecb.push_back(0);
				}
			}
		}
		else{

		}
	}
    return 0;
}
