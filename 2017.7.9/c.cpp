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
	freopen("test.txt","r",stdin);
	int n;
	int coun;
	int cla;
	int i,j;
	int num;
	bool con;
	int con_coun;
	int coun_win;
	while(~scanf("%d",&n)){
		coun=0;
		cla=1;
		con_coun=0;
		con=false;
		for(i=0;i<n;i++){
			scanf("%d",&num);
			if(con){
				con_coun++;
				if(num==1){
					coun_win++;
				}
				if(coun_win==2||con_coun==3){
					if(coun_win>=2){
						cla++;
						coun=0;
						con=false;
						coun_win=0;
					}
					else{
						coun=60;
						con=false;
						coun_win=0;
					}
				}
			}
			else{
				if(num==1){
					coun+=10;
					if(coun>=100){
						con=true;
						con_coun=0;
						coun_win=0;
					}
				}
				else{
					coun-=5;
					if(coun<0)
						coun=0;
				}
			}
			if(cla>=5)
				cla=5;
		}
		if(cla==1){
			printf("D\n");
		}
		else if(cla==2){
			printf("C\n");
		}
		else if(cla==3){
			printf("B\n");
		}
		else if(cla==4){
			printf("A\n");
		}
		else{
			printf("S\n");
		}
	}
	return 0;
}