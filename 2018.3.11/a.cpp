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
const int maxn=505;
char im[maxn][maxn];
int r,c;

int main(){
	// freopen("test.txt","r",stdin);
	//freopen("test.out","w",stdout);
	
	while(~scanf("%d %d",&r,&c)){
		memset(im,'.',sizeof(im));
		for(int i=1;i<=r;i++){
			getchar();
			for(int j=1;j<=c;j++){
				scanf("%c",&im[i][j]);
				// printf("%c",im[i][j]);
			}
			// printf("\n");
		}
		int flag=0;
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				if(im[i][j]=='S'){
					if(im[i][j+1]=='W'||im[i][j-1]=='W'||im[i+1][j]=='W'||im[i-1][j]=='W'){
						flag=1;
						printf("No\n");
						break;
					}
					else{
						if(im[i][j+1]=='.')
							im[i][j+1]='D';
						if(im[i][j-1]=='.')
						im[i][j-1]='D';
						if(im[i-1][j]=='.')
						im[i-1][j]='D';
						if(im[i+1][j]=='.')
						im[i+1][j]='D';
					}
				}
			}
			if(flag){
				break;
			}
		}
		if(!flag){
			printf("Yes\n");
			for(int i=1;i<=r;i++){
				for(int j=1;j<=c;j++){
					printf("%c",im[i][j]);
				}
				printf("\n");
			}
		}
	}
    return 0;
}
