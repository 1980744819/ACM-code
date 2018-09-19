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
int main(){
	freopen("test.txt","w",stdout);
	int t=1000;
	printf("%d\n",t);
	while(t--){
		int num=rand()%100;
		if(num<=1)
			num+=2;
		printf("%d\n",num);
		while(num--){
			for(int i=0;i<rand()%100001;i++){
				printf("%c",'a'+rand()%26);
			}
			printf("\n");
		}
	}
    return 0;
}
