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
int main(){
	//freopen("test.txt","r",stdin);
	int n;
	int coun;
	int num;
	int i,j;
	int tmp;
	while(~scanf("%d",&n)){
		coun=0;
		tmp=-1;
		for(i=0;i<n;i++){
			scanf("%d",&num);
			if(coun==0){
				tmp=num;
				coun=1;
			}
			else{
				if(tmp==num)
					coun++;
				else{
					coun--;
				}
			}
		}
		printf("%d\n",tmp);
	}
	return 0;
}